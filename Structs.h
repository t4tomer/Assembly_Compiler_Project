/*
This header contains all the structs in the project.
*/ 
#ifndef STRUCTSH
#define STRUCTSH
typedef struct instNode { 
    /*
    This struct contain all the line as linked list.
    Each node contains words of the line (as array) and poniter to the next node.
    */
    char **words; 
    char amountOfWords;
    struct instNode* next; 
}instNode;



#endif