SHELL = /bin/sh
CC = g++
CFLAGS = -Wall -g
TARGET = BinaryTree
TEST_TARGET = BinaryTreeTest

all: $(TARGET)

$(TARGET): $(TARGET).o $(TEST_TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o $(TEST_TARGET).o

$(TEST_TARGET).o: $(TEST_TARGET).cpp
	$(CC) $(CFLAGS) -c $(TEST_TARGET).cpp

$(TARGET).o:  $(TARGET).cpp $(TARGET).h 
	$(CC) $(CFLAGS) -c $(TARGET).cpp

clean:
	rm -f *.o *.out $(TARGET)
