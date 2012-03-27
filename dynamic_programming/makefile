#
CPP = g++
O = -o
C = -c

OBJ = rod_cut_test matrix_chain_multi_test obst_test

all:$(OBJ)
obst_test: obst_test.o obst.o
	$(CPP) $(O) obst_test obst_test.o obst.o
obst_test.o: obst_test.cpp obst.h
	$(CPP) $(C) $<
obst.o: obst.cpp obst.h ../constant.h ../utility.h
	$(CPP) $(C) $<


matrix_chain_multi_test: matrix_chain_multi_test.o matrix_chain_multi.o
	$(CPP) $(O) matrix_chain_multi_test matrix_chain_multi_test.o matrix_chain_multi.o
matrix_chain_multi_test.o: matrix_chain_multi_test.cpp matrix_chain_multi.h ../constant.h
	$(CPP) $(C) $<
matrix_chain_multi.o:matrix_chain_multi.cpp matrix_chain_multi.h ../utility.h ../constant.h
	$(CPP) $(C) $<


rod_cut_test: rod_cut_test.o rod_cut.o
	$(CPP) $(O) rod_cut_test rod_cut_test.o rod_cut.o
rod_cut_test.o: rod_cut_test.cpp rod_cut.h
	$(CPP) $(C) $<
rod_cut.o : rod_cut.cpp rod_cut.h ../constant.h ../utility.h
	$(CPP) $(C) $<


clean:
	rm $(OBJ)
	rm *.o
