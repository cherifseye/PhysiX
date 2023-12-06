# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -Wall -g

# Define the target file
TARGET = build

# Define the source files
SRCS = test.cpp ../math/complex.cpp ../math/Quaternions.cpp 

# Define the object files based upon the source files

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


clean:
	rm -f *.o $(TARGET)
