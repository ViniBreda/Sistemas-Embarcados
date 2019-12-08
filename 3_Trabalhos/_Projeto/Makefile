CC := g++

CFLAGS := -std=c++14 -Wall

LIBFLAGS := -lpython2.7 -lopencv_core -lopencv_imgproc -lopencv_highgui -lwiringPi -I/usr/include/python2.7 -lcrypto++ -I/opt/opencv-4.1.0/include/opencv4/opencv2 -I/opt/opencv-4.1.0/include/opencv4/opencv2/core `pkg-config opencv --cflags --libs` -L/opt/opencv-4.1.0/include/opencv4/opencv2 -L/usr/include

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) obj/*.o $(CFLAGS) $(LIBFLAGS) -o bin/saida

obj/%.o : src/%.cpp
	$(CC) -O0 $(CFLAGS) $(LIBFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	bin/saida
