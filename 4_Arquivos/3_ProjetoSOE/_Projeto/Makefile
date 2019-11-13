CC := g++

CFLAGS := -std=c++11 -Wall

LIBFLAGS := -lpython2.7 -I/usr/include/python2.7 -lcrypto++

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC)  obj/*.o $(CFLAGS) $(LIBFLAGS) -o bin/saida

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	bin/saida