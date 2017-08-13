#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include "LineSeparator.h"

#define NO_MULT 1
#define READ "r"
#define DECIMAL 10
#define MAX_LINE_LENGTH 400
#define MAX_DIEMANSIONS 200
#define LOWER_POSITIVE_BOUND 0.00001


double dotProduct(const double *firstVector, const double *secondVector, int numberOfDimensions)
{
    assert(firstVector != NULL && secondVector != NULL && numberOfDimensions > 1);
    int product = 0;
    for (int i = 0; i < numberOfDimensions; ++i)
    {
        product += firstVector[i] * secondVector[i];
    }
    return product;
}

void linearVectorAdding(const double firstVector[], double firstVectorMultiplayer,
                        const double secondVector[], double secondVectorMultiplayer,
                        int numberOfDimensions, double destination[])
{
    assert(firstVector != NULL && secondVector != NULL && destination != NULL);
    for (int i = 0; i < numberOfDimensions; ++i)
    {
        destination[i] = firstVectorMultiplayer * firstVector[i] + secondVectorMultiplayer * secondVector[i];
    }
}


void makePointFromLine(char line[MAX_LINE_LENGTH], int dimensions, Point *pointToWrite)
{
    char *endChar = line;
    for (int i = 0; i < dimensions; ++i)
    {
        pointToWrite->vector[i] = strtod(endChar, &endChar);
        endChar++;
    }
    pointToWrite->value = strtol(endChar, NULL, DECIMAL);
}


void trainAlgorithm(FILE *sourceFile, int numberOfPoints, int numberOfDimensions, double wVector[])
{
    char line[MAX_LINE_LENGTH];
    Point currentPoint = {0, 0};
    double tempDotProduct;

    for (int i = 0; i < numberOfPoints; ++i)
    {
        fgets(line, MAX_LINE_LENGTH, sourceFile);
        makePointFromLine(line, numberOfDimensions, &currentPoint);
        tempDotProduct = dotProduct(currentPoint.vector, wVector, numberOfDimensions);
        if (tempDotProduct != currentPoint.value)
        {
            linearVectorAdding(wVector, NO_MULT, currentPoint.vector, currentPoint.value, numberOfDimensions, wVector);
        }
    }
}

void tagVectors(FILE *sourcrFile, int dimensions, double wVector[])
{
    char line[MAX_LINE_LENGTH];
    char *endChar;
    double vectorToTag[MAX_DIEMANSIONS];

    while (fgets(line, MAX_LINE_LENGTH, sourcrFile) != NULL)
    {
        endChar = line;
        for (int i = 0; i < dimensions; ++i)
        {
            vectorToTag[i] = strtod(endChar, &endChar);
            endChar++;
        }
        if (dotProduct(vectorToTag, wVector, dimensions) > LOWER_POSITIVE_BOUND)
        {
            printf("%d\n", 1);
        } else
        {
            printf("%d\n", -1);
        }
    }

}

int main(int argc, char *argv[])
{
    int numberOfDimensions, numberOfTraningPoints;
    char tempLine[MAX_LINE_LENGTH];
    double wVector[MAX_DIEMANSIONS] = {0};

    char *fileName = argv[1];
    FILE *sourceFile = fopen(fileName, READ);
    if (sourceFile == NULL)
    {
        perror("Problem with source file");
        return 1;
    }

    numberOfDimensions = strtol(fgets(tempLine, MAX_LINE_LENGTH, sourceFile), NULL, DECIMAL);
    numberOfTraningPoints = strtol(fgets(tempLine, MAX_LINE_LENGTH, sourceFile), NULL, DECIMAL);
    assert(numberOfDimensions > 1 && numberOfTraningPoints >= 1 && errno == 0);

    trainAlgorithm(sourceFile, numberOfTraningPoints, numberOfDimensions, wVector);

    tagVectors(sourceFile, numberOfDimensions, wVector);


    if (fclose(sourceFile))
    {
        fprintf(stderr, "Could not close source file");
        return 1;
    }
    return 0;
}



