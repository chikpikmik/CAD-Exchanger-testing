CC = g++

CFLAGS = -Wall -Werror -Wextra -std=c++17 -fopenmp -I include
LIB_CFLAGS = $(CFLAGS) -fPIC

TARGET = main

LIB_NAME = libcurves.so # libcurves.so / libcurves.dll

SRCS = src/Circle.cpp src/CurveFactory.cpp src/Ellipse.cpp src/Helix.cpp
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))

all: build/$(TARGET)

# -L build -l curves указывает какую библиотеку и где искать при линковке
# -Wl,-rpath,'$$ORIGIN' указывает где искать библиотеку при запуске
build/$(TARGET): app/main.cpp build/$(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ app/main.cpp -L build -l curves -Wl,-rpath,'$$ORIGIN'


# -shared для создания динамической библиотеки
build/$(LIB_NAME): $(OBJS)
	@mkdir -p build
	$(CC) $(LIB_CFLAGS) -shared -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p build
	$(CC) $(LIB_CFLAGS) -c $< -o $@


clean:
	rm -rf build
