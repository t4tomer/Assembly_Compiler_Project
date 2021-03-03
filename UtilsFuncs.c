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

instNode* buildInstructionsList(FILE *insFile)
{
    char line[MAX_LINE_LEN] ={0};/*varible for reading the lines.*/
    instNode *head = NULL;
    instNode *pos = NULL;
    while (fgets(line, MAX_LINE_LEN, insFile))
    {
        instNode *node = malloc(sizeof(instNode));
        node->words = malloc(sizeof(MAX_LINE_LEN));
        strcpy(node->words,trimSpace(line));
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

