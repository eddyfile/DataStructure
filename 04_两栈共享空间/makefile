object = Stack.o main.o
main:$(object)
	gcc -c main.cpp	
	gcc -o main $(object)
%.o:%.c
	gcc -c $<
.PHONY: clean
clean:
	rm *.o main
	