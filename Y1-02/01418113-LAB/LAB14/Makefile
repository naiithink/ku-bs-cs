CC = clang++

main : RandomGenerator.o Coin.o Dice.o
	$(CC) -g RandomGenerator.o Coin.o Dice.o main.cpp -o main.out

Dice.o : RandomGenerator.o
	$(CC) -c Dice.cpp

Coin.o : RandomGenerator.o
	$(CC) -c Coin.cpp

RandomGenerator.o : clean
	$(CC) -c RandomGenerator.cpp

clean :
	rm -f *.o main.out