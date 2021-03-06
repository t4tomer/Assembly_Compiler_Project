/*This file contain the first transition method.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"
#include "Structs.h"
#include "UtilsFuncs.h"
#include "Validations.h"
int firstTransition (char *fileName)
{
    int IC=100,DC=0; /*IC - Instructions counter, DC - Data counter.*/
    FILE *insFile; /*Instructions file pointer.*/ 
    instNode *listOfInstructions;
    instNode *instPos;
    boolean labelFlag;
    if((insFile=fopen(fileName,"r"))==NULL)
    {
        perror("cannot open file!");
        return EXIT_FAILURE;
    }

    listOfInstructions = buildInstructionsList(insFile);
    instPos = listOfInstructions;
    while(instPos!=NULL)
    {
        if(isLabel(instPos->words[0]))
        {
            labelFlag=true;
        }
        if(isDataAllocation(instPos->words[1]))
        {
            if(labelFlag)
            {
                symbolNode *newSymbol=NULL;
                newSymbol->symbol=malloc(sizeof(char) * strlen(instPos->words[0]-1));
                strcpy(newSymbol->symbol,substr(instPos->words[0],0,strlen(instPos->words[0]-1)));
                newSymbol->value=malloc(sizeof(int));
                newSymbol->value = DC;
                newSymbol->attributes=malsloc(sizeof(char*));
                newSymbol->attributes[0]=malloc(sizeof(char)* strlen(instPos->words[1]));
                strcpy(newSymbol->attributes[0], substr(instPos->words[1],1,strlen(substr)));
            }
        }
        instPos=instPos->next;
    }
    /*
    while(temp!=NULL)
    {
        int i=0;
        for(;i<temp->amountOfWords;i++){
            printf("%s(%d) ",temp->words[i],strlen(temp->words[i]));
        }
        printf("->\n");
        temp=temp->next;
    }*/
    
    
    if (fclose(insFile))
    {
        perror("cannot close file!");
        return EXIT_FAILURE;
    }
    return(EXIT_SUCCESS);
}

