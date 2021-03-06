#ifndef SYMBOLSTABLEH
#define SYMBOLSTABLEH

#include "Structs.h"

void initSymbolTable(symbolTableList*);
void addNewSymbol(symbolTableList *, symbolNode *);
symbolNode* createNode(char *, int, char *);
void freeSymbolTable(symbolTableList *);
#endif