#
CPP = g++
O = -o
C = -c

OBJ = rod_cut_test

all:$(OBJ)

rod_cut_test: rod_cut_test.o rod_cut.o
	$(CPP) $(O) rod_cut_test rod_cut_test.o rod_cut.o

rod_cut_test.o: rod_cut_test.cpp rod_cut.h
	$(CPP) $(C) $<

rod_cut.o : rod_cut.cpp rod_cut.h ../constant.h ../utility.h
	$(CPP) $(C) $<

clean:
	rm $(OBJ)
	rm *.o
