CC = "clang"
CFLAGS = "-g"

run : make
	mkdir out
	./04.out < in/01.txt 1> out/01o.txt
	./04.out < in/02.txt 1> out/02o.txt

make : clean
	$(CC) $(CLAGS) 04.c -o 04.out

clean :
	rm -rf *.out *.dSYM out