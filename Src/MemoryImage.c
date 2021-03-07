#include "../Headers/Structs.h"
#include "../Headers/UtilsFuncs.h"
#include "../Headers/Constants.h"

void initMemoryTable(memoryImageList *list)
{
    list = (memoryImageList*)malloc(sizeof(memoryImageList));
    list->head = NULL;
    list->last = NULL; 
}

memoryNode* createMemoryNode( int adress, short value, char type)
{

    memoryNode* newMemory=malloc(sizeof(memoryNode));

    newMemory->adress = adress;
    newMemory->value = value;
    newMemory->type = type;
     
    return newMemory;
}

void addNewMemory(memoryImageList *list, memoryNode *newNode)
{
    if(list->head == NULL)
    {
        list->head = newNode;
        list->last = newNode;
    }  
    else
    {
        list->last->next = newNode;
        list->last = list->last->next;
    }
}






void freeMemoryTable(symbolTableList *list)
{
    /*TODO need to fix the free function for ALL structs!
    symbolNode* tmp;
    symbolNode* head = list->head;
    while (head != NULL)
    {
        int i=0;
        tmp = head;
        head = head->next;
        for(;i<tmp->nOfAtt;i++) {
            free(tmp->attributes[i]);
        }
        free(tmp->attributes);
        free(tmp->symbol);
        free(tmp);
    }
    */
}