CC = g++
CFLAGS = -Wall -std=c++17 -Iinclude
TARGET = main

SRCS = src/Circle.cpp src/CurveFactory.cpp src/Ellipse.cpp src/Helix.cpp
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))

build/$(TARGET): $(OBJS) app/main.cpp
	$(CC) $(CFLAGS) -o $@ $(OBJS) app/main.cpp

build/%.o: src/%.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build
