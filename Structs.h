/*
This header contains all the structs in the project.
*/ 

/*
This struct contain all the line as linked list.
Each node contains words of the line (as array) and poniter to the next node.
*/
#ifndef STRUCTSH
#define STRUCTSH
typedef struct instNode { 
    char **words; 
    char amountOfWords;
    struct instNode* next; 

}instNode;
#endif