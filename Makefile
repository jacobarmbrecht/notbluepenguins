CFLAGS = $(shell pkg-config --libs --cflags opencv)
SOURCES = webcam.cpp
HEADERS =
.PHONY = all
all: webcam
webcam:	$(SOURCES) $(HEADERS)
	g++  $(SOURCES) $(CFLAGS) -o webcam
