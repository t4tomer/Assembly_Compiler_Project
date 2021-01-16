myprog:main.o firstTransition.o 
	gcc -g -ansi -Wall -pedantic main.o firstTransition.o -o myprog 
main.o: main.c FirstTransition.h
	gcc -c -ansi -Wall -pedantic main.c -o main.o 
firstTransition.o: FirstTransition.c Constants.h FirstTransition.h
	gcc -c -ansi -Wall -pedantic FirstTransition.c -o firstTransition.o 