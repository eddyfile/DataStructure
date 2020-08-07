object = SqList.o TestSqList.o main.o
main:$(object)
	gcc -o main $(object)
%.o:%.c
	gcc -c $<
.PHONY: clean
clean:
	rm *.o main
