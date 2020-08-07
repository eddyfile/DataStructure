object = stack.o main.o

main:$(object)
	gcc -o main $(object)

stack.o:stack.cpp
	gcc -c stack.cpp
main.o:main.cpp
	gcc -c main.cpp


.PHONY: clean
clean:
	rm *.o main