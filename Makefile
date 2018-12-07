CFLAGS = $(shell pkg-config --libs --cflags opencv)
SOURCES = webcam.cpp list.cpp
HEADERS = list.h
.PHONY = all
all: webcam
webcam:	$(SOURCES) $(HEADERS)
	g++  $(SOURCES) $(CFLAGS) -o webcam
