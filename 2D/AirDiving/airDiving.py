import numpy as np
import matplotlib.pyplot as plt

def surface(radius):
    return np.pi * (radius**2)

h      = 7
g      = 9.81
rho    = 1.22
massT  = 57/1000
CxT    = 0.57
radT   = 3.3/100
VoT    = np.sqrt((2*massT * g) / (CxT*rho*surface(radT)))
Ttenis = VoT / g
tmaxT  = Ttenis * np.arccosh(np.exp(h / (VoT * Ttenis)))
massP = 700/1000
CxP   = 0.45
radP  = 3.7/100
VoP   = np.sqrt((2*massP * g) / (CxP*rho*surface(radP)))
Tpet  = VoP / g
TmaxP = Tpet * np.arccosh(np.exp(h / (VoP * Tpet)))

t = np.linspace(0, max(TmaxP, tmaxT), 1000)
h1 = h - VoT*Ttenis*np.log(np.cosh(t/Ttenis))
h2 = h - VoP*Tpet*np.log(np.cosh(t/Tpet))
plt.plot(t, h1, label="Tennis Ball")
plt.plot(t, h2, '--', label="Petanque Ball")
plt.axis([0, max(TmaxP, tmaxT), 0, h])
plt.legend()
plt.show()