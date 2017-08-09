#include <stdio.h>
#include <assert.h>
#include "LineSeparator.h"

#define NO_MULT 1


int dotProduct(const int *firstVector, const int *secondVector, int numberOfDimensions)
{
    assert(firstVector != NULL && secondVector != NULL && numberOfDimensions > 1);
    int product = 0;
    for (int i = 0; i < numberOfDimensions; ++i)
    {
        product += firstVector[i] * secondVector[i];
    }
    return product;
}

void linearVectorAdding(const int firstVector[], int firstVectorMultiplayer,
                        const int secondVector[], int secondVectorMultiplayer,
                        int numberOfDimensions, int destination[])
{
    assert(sizeof(*destination) == numberOfDimensions);
    for (int i = 0; i < numberOfDimensions; ++i)
    {
        destination[i] = firstVectorMultiplayer * firstVector[i] + secondVectorMultiplayer * secondVector[i];
    }
}

int trainAlgoritm(Point pointsArray[], int numberOfPoints, int numberOfDimensions, int *destination)
{
    for (int i = 0; i < numberOfPoints; ++i)
    {
        Point currentPoint = pointsArray[i];
        int *tempVector = currentPoint.vector;
        int tempDotProduct = dotProduct(tempVector, destination, numberOfDimensions);
        if (tempDotProduct != currentPoint.value)
        {
            linearVectorAdding(destination, NO_MULT, tempVector, tempDotProduct, numberOfDimensions, destination);
        }
    }
}

int tagPoints(Point pointsToTag[],int* normVector, int numberOfPoints, int numberOfDimensions)
{
    for (int i = 0; i < numberOfPoints; ++i)
    {
        Point currentPoint = pointsToTag[i];
        if (dotProduct(currentPoint.vector, normVector, numberOfDimensions) > 0)
        {
            currentPoint.value = 1;
        } else
        {
            currentPoint.value = -1;
        }
    }
}


