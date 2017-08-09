#include <stdio.h>
#include <assert.h>

int main(int art, int sads)
{
    printf("Hello, World!\n");

    return 0;
}

unsigned int countSubStr(const char *str1, const char *str2, int isCyclic)
{
    assert(str1 != NULL && str2 != NULL);
    const char *currentStr1Char = str1;
    const char *currentStr2Char = str2;
    unsigned int numberOfMatches = 0;

    while (currentStr1Char != '\0')
    {
        if (currentStr1Char == currentStr2Char)
        {
            currentStr2Char++;
        } else
        {
            currentStr2Char = str2;
            continue;
        }
        if (currentStr2Char == '\0')
        {
            numberOfMatches++;
            currentStr2Char = str2;
        }
        currentStr1Char++;
    }

    if (isCyclic)
    {
        currentStr1Char = str1;
        while (currentStr2Char != '\0')
        {
            if (currentStr1Char == currentStr2Char)
            {
                currentStr2Char++;
                currentStr1Char++;
                if (currentStr1Char == '\0')
                {
                    currentStr1Char = str1;
                }
                if (currentStr2Char == '\0')
                {
                    numberOfMatches++;
                }
            } else
            {
                break;
            }
        }
    }

    return numberOfMatches;
}
