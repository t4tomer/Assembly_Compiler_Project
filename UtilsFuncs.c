/*
This file contains all the utilites functions for the project.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Structs.h"
#include "Constants.h"
#include "UtilsFuncs.h"


char *trimSpace(char *str);/*Help function to trim spaces*/
void convertLineToArray(char* line, char** arr); /* this function converts line to an array by using delimeter of space */
char amountOfSpaces(char* line); /*this function returns the amount of spaces */

instNode* buildInstructionsList(FILE *insFile)
{
    char line[MAX_LINE_LEN] ={0};/*varible for reading the lines.*/
    instNode *head = NULL;
    instNode *pos = NULL;
    int i;
    while (fgets(line, MAX_LINE_LEN, insFile))
    {
        instNode *node = malloc(sizeof(instNode));

        node->amountOfWords=amountOfSpaces(trimSpace(line))+1;
        node->words = malloc(sizeof(char**) * node->amountOfWords);
        convertLineToArray(trimSpace(line), node->words);

        node->next =NULL;

        if(head == NULL){  
            pos = head = node;
        } else {
            pos = pos->next = node;
        }
    }

    return head;
}


char *trimSpace(char *str)
{
  char *end;

  while(((unsigned char)*str) == SPACE_CHAR) str++;

  if(*str == 0)  
    return str;


  end = str + strlen(str) - 1;
  while(end > str && ((unsigned char)*end) == SPACE_CHAR) end--;

  end[1] = '\0';

  return str;
}

void convertLineToArray(char* line, char** arr){

    char nSpaces;
    int i;
    char *pWord;  
    nSpaces=amountOfSpaces(line);

    /* split the elements by space delimeter */ 
    pWord=strtok(line," \t");
    i=0;
    while(pWord!=NULL)
    {
        arr[i] = malloc(sizeof(char*));
        strcpy(arr[i++],pWord);
        pWord=strtok(NULL," \t");
    }
}

char amountOfSpaces(char* line){
  int i;
  char amountOfSpaces=0; 
  for(i=0;line[i];i++) /* count amount of spaces */ 
        if(line[i]==' ')
             amountOfSpaces++;
  return amountOfSpaces;           
}



