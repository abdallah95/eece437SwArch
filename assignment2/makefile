
CXX := g++
INCLUDE_DIR := include/
BUILD_DIR := build/
CPP_FILES := $(wildcard src/*/*.cpp)
OBJ_FILES := $(addprefix build/,$(CPP_FILES:.cpp=.o))

build: build_dir $(OBJ_FILES)

all: build_dir

build_dir:
	mkdir -p build

build/src/%.o: src/%.cpp include/%.h
	$(CXX) -c -o $@ $< -I $(INCLUDE_DIR)

# test: test.cpp build_dir $(OBJ_FILES)
# 	$(CXX) -o test $(OBJ_FILES) test.cpp

clean:
	rm -f test 
	rm -rf build/