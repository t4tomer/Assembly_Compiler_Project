myprog:main.o firstTransition.o UtilsFuncs.o Validations.o SymbolsTable.o
	gcc -g -ansi -Wall -pedantic main.o Validations.o UtilsFuncs.o SymbolsTable.o firstTransition.o -o myprog 
main.o: main.c FirstTransition.h
	gcc -c -ansi -Wall -pedantic main.c -o main.o
Validations.o: Constants.h Structs.h
	gcc -c -ansi -Wall -pedantic Validations.c -o Validations.o
SymbolsTable.o: Constants.h Structs.h UtilsFuncs.h
	gcc -c -ansi -Wall -pedantic SymbolsTable.c -o SymbolsTable.o
UtilsFuncs.o: UtilsFuncs.c Constants.h Structs.h UtilsFuncs.h
	gcc -c -ansi -Wall -pedantic UtilsFuncs.c -o UtilsFuncs.o
firstTransition.o: FirstTransition.c Constants.h FirstTransition.h UtilsFuncs.h
	gcc -c -ansi -Wall -pedantic FirstTransition.c -o firstTransition.o

