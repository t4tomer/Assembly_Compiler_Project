/*This file contain the first transition method.*/

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "FirstTransition.h"
int firstTransition ()
{
   
    int IC=100,DC=0; /*IC - Instructions counter, DC - Data counter.*/
    FILE *insFile; /*Instructions file.*/ 
    char line[MAX_LINE_LEN] ={0};/*varible for reading the lines.*/
    unsigned int line_count = 0;
    if((insFile=fopen(TEMP_FILE,"r"))==NULL)
    {
        perror(TEMP_FILE);
        return EXIT_FAILURE;
    }

     while (fgets(line, MAX_LINE_LEN, insFile))
    {
        /* Print each line */
        printf("line[%06d]: %s", ++line_count, line);
        
        /* Add a trailing newline to lines that don't already have one */
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }
    if (fclose(insFile))
    {
        return EXIT_FAILURE;
        perror(insFile);
    }
    return(EXIT_SUCCESS);
}