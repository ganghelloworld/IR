#
CPP = g++
OFLAG = -o
CFLAG = -c
OBJ = test.o sort.o priority_queue.o utility.o

.SUFFIXES: .cpp .o
.cpp.o:
	$(CPP) $(CFLAG) $<

test:$(OBJ)
	$(CPP) $(OFLAG) $@ $(OBJ)
clean:
	rm -rf *.o
	rm test
