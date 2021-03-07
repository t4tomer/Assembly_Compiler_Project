/*This file contain the first transition method.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Constants.h"
#include "../Headers/Structs.h"
#include "../Headers/UtilsFuncs.h"
#include "../Headers/Validations.h"
#include "../Headers/SymbolsTable.h"
int firstTransition (char *fileName)
{
    int IC=100,DC=0; /*IC - Instructions counter, DC - Data counter.*/
    FILE *insFile; /*Instructions file pointer.*/ 
    instNode *listOfInstructions;
    instNode *instPos;
    boolean labelFlag;
    struct symbolNode *symbolNode;

    symbolTableList *symbolTable;
    memoryImageList *memoryTable;
    struct memoryNode *memoryNode;

    struct memoryNode *memoryTmp;
    struct symbolNode *symbolTmp;
    
    initSymbolTable(symbolTable);
    initMemoryTable(memoryTable);

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
                symbolNode = createSymbolNode(instPos->words[0], DC, instPos->words[1]);
                addNewSymbol(symbolTable,symbolNode);
                printf("this word:%s\n",instPos->words[1]);
                if(strcmp(instPos->words[1],".string")==0)
                     {
                            char kaka = instPos->words[2][3];
                            memoryNode=createMemoryNode(IC,kaka,'A');


                            stringToCharForImag(instPos->words[2]);
                            printf("the words is:%x\n",kaka);



                            printf("true\n");
                            printf("the words is:%s\n",instPos->words[2]);

                           /* char *sptr;
                            printf("  %c",instPos->words[2][0]);

                         sptr=instPos->words[2][0];  */

                     }



            }

           
            



        }
        labelFlag=false;
        instPos=instPos->next;
    }

    
    symbolTmp = symbolTable->head;
    while(symbolTmp!=NULL)
    {
        printf("%s\n",symbolTmp->symbol);
        symbolTmp=symbolTmp->next;
    }

    if (fclose(insFile))
    {
        perror("cannot close file!");
        return EXIT_FAILURE;
    }

    return(EXIT_SUCCESS);
}

