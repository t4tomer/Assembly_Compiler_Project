#include "Validations.h"
#include "Constants.h"
#include <string.h>

boolean isLabel(char *word)
{
    if(word[strlen(word)-1]==':')
        return true;
    return false;
}

boolean isDataAllocation(char *word)
{
    if(strcmp(word,".string") || strcmp(word,".data"))
        return true;
    return false;
}