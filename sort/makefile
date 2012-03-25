#
CPP = g++
OFLAG = -o
CFLAG = -c
OBJ = test.o sort.o priority_queue.o

.SUFFIXES: .cpp .o
.cpp.o:
	$(CPP) $(CFLAG) $<

test:$(OBJ)
	$(CPP) $(OFLAG) $@ $(OBJ)

test.o: test.cpp ../utility.h sort.h priority_queue.h ../constant.h

sort.o: sort.cpp ../utility.h sort.h ../constant.h

priority_queue.o: priority_queue.cpp  ../utility.h  priority_queue.h ../constant.h
clean:
	rm -rf *.o
	rm test
