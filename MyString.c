#include <stdio.h>
#include <assert.h>
#include "MyString.h"


/*
 * Let n = len(str1) | m = len(str2)
 * If function is not cyclic this runs at O(n).
 * If function is cyclic this runs at O(n+m).
 *
 * Basis of the algorithm assumes that if cyclic then we can find just one more match,
 * because otherwise we would have gotten a match in the non-cyclic case.
 * So if cyclic, the function stops at the find of the match, or at the first sight
 * of a failed match.
 */
unsigned int countSubStr(const char *str1, const char *str2, int isCyclic)
{
    assert(str1 != NULL && str2 != NULL);
    const char *currentStr1Char = str1;
    const char *currentStr2Char = str2;
    unsigned int numberOfMatches = 0;

    while (*currentStr1Char != '\0')
    {
        if (*currentStr1Char == *currentStr2Char)
        {
            currentStr2Char++;
        }
        else
        {
            if (currentStr2Char != str2)
            {
                currentStr2Char = str2;
            }
            else
            {
                currentStr1Char++;
            }
            continue;

        }
        if (*currentStr2Char == '\0')
        {
            numberOfMatches++;
            currentStr2Char = str2;
        }
        currentStr1Char++;
    }

    if (isCyclic)
    {
        currentStr1Char = str1;
        while (*currentStr2Char != '\0')
        {
            if (*currentStr1Char == *currentStr2Char)
            {
                currentStr2Char++;
                currentStr1Char++;
                if (*currentStr1Char == '\0')
                {
                    currentStr1Char = str1;
                }
            }
            else
            {
                return numberOfMatches;
            }
        }
        numberOfMatches++;
    }

    return numberOfMatches;
}
