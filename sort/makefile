#
vpath %.h ../include

test: sort.o priority_queue.o sort.h priority_queue.h utility.h
sort.o: sort.h utility.h constant.h
priority_queue.o: priority_queue.h utility.h constant.h

clean:
	rm -rf *.o
	rm test
