#ifndef SYMBOLSTABLEH
#define SYMBOLSTABLEH

#include "Structs.h"

symbolTableList* initList();
void addNewSymbol(symbolTableList, symbolNode);
symbolNode* createNode(char *, int, char *);
#endif