CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

SRCS := $(wildcard src/*.cc)
OUT := build/main

.PHONY: vysh run clean

vysh:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUT)

run:
	mkdir -p build
	./$(OUT)

clean:
	rm -rf $(OUT)
