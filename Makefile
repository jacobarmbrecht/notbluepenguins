CFLAGS = $(shell pkg-config --libs --cflags opencv)
.PHONY = all
all:
	g++  webcam.cpp $(CFLAGS) -o webcam
