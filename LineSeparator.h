
#ifndef EX2_HONE_LINESEPARATOR_H
#define EX2_HONE_LINESEPARATOR_H

#define READ "r"
#define DECIMAL 10
#define MAX_LINE_LENGTH 400
#define MAX_DIEMANSIONS 200
#define LOWER_POSITIVE_BOUND 0.00001
#define FILE_OPEN_ERR "Problem with source file"
#define FILE_CLOSING_ERR "Could not close source file"

#define ABOVE_PLANE 1
#define BELOW_PLANE -1
typedef struct Point
{
    double vector[MAX_DIEMANSIONS];
    int value;
} Point;

/**
 * calcultes the dot product of the two vectors supplied.(<V1,V1>) only works for real numbers vector(not complex).
 * vectors must be at least "numberOfDimensions" long, and will only calculte up to "numberOfDimensions"
 * @param firstVector first vector
 * @param secondVector  second vector
 * @param numberOfDimensions number of dimensions we are working with.
 * @return the dot product of the vector.
 */
double dotProduct(const double *firstVector, const double *secondVector, int numberOfDimensions);

/**
 * calculates (firstVector * firstVectorMultiplayer)  + (secondVector * secondVectorMultiplayer)
 * and puts the result in the destination array
 * @param firstVector first vector
 * @param firstVectorMultiplayer times what we want the first vector to be taken
 * @param secondVector second vector
 * @param secondVectorMultiplayer times what we want the second vector to be taken
 * @param numberOfDimensions number of dimensions we are working with.
 * @param destination where to write the result.
 */
void linearVectorAdding(const double firstVector[], double firstVectorMultiplayer,
                        const double secondVector[], double secondVectorMultiplayer,
                        int numberOfDimensions, double destination[]);

/**
 * take a line of text with the specified format in the ex description
 * and writes the data into the Point type supplid
 * @param line line to turn into point
 * @param dimensions number of dimensions we are working with.
 * @param pointToWrite point to write results in.
 */
void makePointFromLine(char line[MAX_LINE_LENGTH], int dimensions, Point *pointToWrite);

/**
 * This is a function to calculates the hyper-plane norm vector(W vector) from the data supplied.
 * @param sourceFile where to read data from.
 * @param numberOfPoints how many training points there is.
 * @param numberOfDimensions number of dimensions we are working with.
 * @param wVector an array to store wVector in.
 */
void trainAlgorithm(FILE *sourceFile, int numberOfPoints, int numberOfDimensions, double wVector[]);

/**
 * reads vectors as a line from the files, and for each vector prints the value of it (+1 || -1).
 * @param sourcrFile file to get vectors from.
 * @param dimensions number of dimensions we are working with.
 * @param wVector hyper-plane norm vector, either calculated before or supllied in advance.
 */
void tagVectors(FILE *sourcrFile, int dimensions, double wVector[]);

#endif //EX2_HONE_LINESEPARATOR_H
