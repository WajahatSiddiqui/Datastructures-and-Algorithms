
SHELL = /bin/sh
CC = g++
CFLAGS = -Wall -g
TARGET = Graph
TARGETTEST = GraphTest

all: $(TARGET)

$(TARGET): $(TARGET).o $(TARGETTEST).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o $(TARGETTEST).o

$(TARGETTEST).o: $(TARGETTEST).cpp
	$(CC) $(CFLAGS) -c $(TARGETTEST).cpp

$(TARGET).o:  $(TARGET).cpp $(TARGET).h 
	$(CC) $(CFLAGS) -c $(TARGET).cpp

clean:
	rm -f *.o *.out $(TARGET)
