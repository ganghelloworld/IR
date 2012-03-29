#
vpath %.h ../include

OBJ = obst_test matrix_chain_multi_test rod_cut_test

all: $(OBJ)

obst_test: obst.o
obst.o: obst.h constant.h utility.h

matrix_chain_multi_test: matrix_chain_multi.o constant.h
matrix_chain_multi.o: matrix_chain_multi.h constant.h utility.h

rod_cut_test: rod_cut.o
rod_cut.o: rod_cut.h constant.h utility.h

clean:
	rm $(OBJ)
	rm *.o
