/*This file contain the first transition method.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"
#include "Structs.h"
#include "UtilsFuncs.h"
int firstTransition (char *fileName)
{
    int IC=100,DC=0; /*IC - Instructions counter, DC - Data counter.*/
    FILE *insFile; /*Instructions file pointer.*/ 
    instNode *listOfInstructions;
    instNode *temp;
    if((insFile=fopen(fileName,"r"))==NULL)
    {
        perror("cannot open file!");
        return EXIT_FAILURE;
    }

    listOfInstructions = buildInstructionsList(insFile);
    temp = listOfInstructions;
    while(temp!=NULL)
    {
        printf("%s->",temp->words);
        temp=temp->next;
    }
    
    if (fclose(insFile))
    {
        perror("cannot close file!");
        return EXIT_FAILURE;
    }
    return(EXIT_SUCCESS);
}