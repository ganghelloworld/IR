vpath %.h: ../include

OBJ = activity_selection_test huffman_code_test

activity_selection_test: activity_selection.o
activity_selection.o:activity_selection.h

huffman_code_test: huffman_code.o
huffman_code.o:huffman_code.h

clean:
	rm $(OBJ)
	rm *.o
