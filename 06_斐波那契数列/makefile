object = fibonacci.o
main:$(object)
	gcc -o main $(object)
fibonacci.o:fibonacci.cpp
	gcc -c fibonacci.cpp
.PYTHON: clean
clean:
	rm *.o main