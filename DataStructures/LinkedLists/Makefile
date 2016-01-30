SHELL = /bin/sh
CC = g++
CFLAGS = -Wall -g
TARGET = List

all: $(TARGET)

$(TARGET): $(TARGET).o ListTest.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o ListTest.o

ListTest.o: ListTest.cpp
	$(CC) $(CFLAGS) -c ListTest.cpp

$(TARGET).o:  $(TARGET).cpp $(TARGET).h 
	$(CC) $(CFLAGS) -c $(TARGET).cpp

clean:
	rm -f *.o *.out $(TARGET)
