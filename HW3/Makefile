# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -O2

# Source files
SOURCES = substrings.cpp minimalset.cpp lexicographic.cpp insertionorders.cpp

# Executable names
EXECUTABLES = substrings minimalset lexicographic insertionorders

# Default target
all: $(EXECUTABLES)

# Rule to build each executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up build files
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean