/*This file contain the first transition method.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"
#include "Structs.h"

int firstTransition (char *fileName)
{
   
    int IC=100,DC=0; /*IC - Instructions counter, DC - Data counter.*/
    FILE *insFile; /*Instructions file pointer.*/ 
    char line[MAX_LINE_LEN] ={0};/*varible for reading the lines.*/
    unsigned int line_count = 0;
    instNode *instLies;
    if((insFile=fopen(fileName,"r"))==NULL)
    {
        perror("cannot open file!");
        return EXIT_FAILURE;
    }

    /*while (fgets(line, MAX_LINE_LEN, insFile))
    {
         Print each line 
        printf("line[%06d]: %s", ++line_count, line);
        
         Add a trailing newline to lines that don't already have one 
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }
    */
    if (fclose(insFile))
    {
        perror("cannot close file!");
        return EXIT_FAILURE;
    }
    return(EXIT_SUCCESS);
}