CC = gcc
CFLAGS = -Wall -g

run: main
	mkdir out
	./struct_main.out < input/01.txt > out/01-struct.txt
	./struct_main.out < input/02.txt > out/02-struct.txt
	./struct_main.out < input/03.txt > out/03-struct.txt

main: clean
	$(CC) $(CFLAGS) -o struct_main.out struct_main.c


clean:
	rm -rf *.o *.out out/*.txt out/