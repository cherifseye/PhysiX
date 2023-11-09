# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -Wall -g

# Define the target file
TARGET = main

# Define the source files
SRCS = main.cpp fraction.cpp Quaternions.cpp complex.cpp 

# Define the object files based upon the source files
# This uses a suffix replacement within a macro:
# $(name:string1=string2)
# For example, hello.c becomes hello.o
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o 
