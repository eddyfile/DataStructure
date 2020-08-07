object = linkqueue.o main.o
main:$(object)
	g++ -c main.cpp
	gcc -o main $(object)
%.o:%.c
	gcc -c $<

.PHONY :clean
clean:
	rm *.o main

