/*
This file contains all the utilites functions for the project.
*/


#include <stdlib.h>
#include <stdio.h>
#include "Structs.h"
#include "Constants.h"
#include "UtilsFuncs.h"

instNode *buildInstructionsList(FILE *insFile)
{
    char line[MAX_LINE_LEN] ={0};/*varible for reading the lines.*/
    instNode *head = NULL;
    instNode *pos = NULL;
    while (fgets(line, MAX_LINE_LEN, insFile))
    {
        if(pos == NULL) /*first insertion*/
        {
            head = (instNode*)malloc(sizeof(instNode));
            pos = head;
            head->words = line;
            head->next = NULL;
        }
        else
        {
            pos->next = (instNode*)malloc(sizeof(instNode));
            pos->next->words=line;
            pos->next->next=NULL;
            pos=pos->next;
        }
    }
    return head;
}


