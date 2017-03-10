
CXX := g++
INCLUDE := include/
BUILD_DIR := build/
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))

build: build_dir $(OBJ_FILES)

all: build test

build_dir:
	mkdir -p build

build/%.o: src/%.cpp include/%.h
	$(CXX) -c -o $@ $< -I $(INCLUDE)

test: test.cpp build_dir $(OBJ_FILES)
	$(CXX) -o test $(OBJ_FILES) test.cpp -I $(INCLUDE)

clean:
	rm -f test 
	rm -rf build/