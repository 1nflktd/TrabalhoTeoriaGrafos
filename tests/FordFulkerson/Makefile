SRC_FILES := $(wildcard ../../src/*.cpp ../../src/algorithms/*.cpp FordFulkersonTest.cpp)
SRC_FILES := $(filter-out ../../src/main.cpp, $(SRC_FILES))

main:
	g++ $(SRC_FILES) -o trabalho -Wall -std=c++14 -O3