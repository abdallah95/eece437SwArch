
CXX := g++
INCLUDE_DIR := include/
BUILD_DIR := build/
CPP_FILES := $(wildcard src/*/*.cpp)
OBJ_FILES := $(addprefix build/,$(CPP_FILES:.cpp=.o))
CXX_FLAGS := -I $(INCLUDE_DIR)

build: $(OBJ_FILES)

all: build

build/src/%.o: src/%.cpp build/src/%.d
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

build/src/%.d: src/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXX_FLAGS) -M $< > $@

# test: test.cpp build_dir $(OBJ_FILES)
# 	$(CXX) -o test $(OBJ_FILES) test.cpp

clean:
	rm -f test 
	rm -rf build/
