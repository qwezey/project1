#ifndef tools_h
#define tools_h

#include <stdio.h>
#include <sys/types.h>

#define TEMPSIZE 4096

unsigned int tokenizeRow(const char * line, char * ** row);
void trim (char * str);
void removeChars (char * str, unsigned long startIndex, unsigned long endIndex);
void fillTable(FILE * csvFile, char * *** table, unsigned int * rows, unsigned int * columns);
void printTable (FILE * stream, char *** table, unsigned int rows, unsigned int columns);
int isNumber(const char * str);
int isXBeforeY (const char * x, const char * y, int areNumbers);
int isNumericColumn(char *** table, int rows, int columnIndex);
int findCsvFiles(const char * dirPath, char * ** csvPaths, int * numFound);
int isProperCsv(const char * csvPath);
unsigned int lineageParser(const char * path, char * ** lineage);

#endif /* tools_h */
