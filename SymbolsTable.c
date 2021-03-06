#include "Structs.h"
#include "UtilsFuncs.h"
#include "Constants.h"
#include <stdlib.h>
#include <string.h>
symbolTableList* initSymbolTable()
{
    return (symbolTableList*)malloc(sizeof(symbolTableList));
}

void addNewSymbol(symbolTableList *list, symbolNode *newNode)
{
    symbolNode *pos = list->head;
    while(pos->next!=NULL)
        pos = pos->next;
    pos->next = malloc(sizeof(symbolNode));
    pos->next->symbol = malloc(sizeof(char*) * sizeof(strlen(newNode->symbol)));
    pos->next->value = newNode->value;
    pos->next->attributes =malloc(sizeof(char*));
    pos->next->attributes[0] =malloc(sizeof(char)* strlen(newNode->attributes[0]));
    strcpy(pos->next->attributes[0], newNode->attributes[0]);
}

symbolNode* createNode(char *symbol, int value, char *attr)
{
    symbolNode *newSymbol=NULL;
    newSymbol=malloc(sizeof(symbolNode));
    newSymbol->symbol=malloc(sizeof(char) * strlen(symbol));
    strcpy(newSymbol->symbol,substr(symbol,0,strlen(symbol)-1));
    newSymbol->value = value;
    newSymbol->attributes=malloc(sizeof(char*));
    newSymbol->attributes[0]=malloc(sizeof(char)* strlen(attr));
    strcpy(newSymbol->attributes[0], substr(attr,1,strlen(attr)));
    return newSymbol;
}