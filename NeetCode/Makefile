# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++20 
#-Wall -Werror -O3

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Executables
PROGS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SRCS))

# Default rule
all: $(PROGS)

# Build a specific program
#%: $(BIN_DIR)/%

# Link object file into executable
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean rule
clean:
	rm -f $(PROGS)

# Create directories if not exists
$(BIN_DIR):
	mkdir -p $@

# Make bin directory before building
$(PROGS): $(BIN_DIR)

.PHONY: all clean
