#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

#include "tools.h"
#include "sorter.h"
#include "analyser.h"
#include "mainTools.h"
#include "forkTools.h"
#include "memTools.h"

int main2(int argc, char ** argv) {
    
    char * columnHeader = getColumnHeader(argc, argv);
    sortCsv("movie_metadata.csv", columnHeader, ".");
    exit(EXIT_SUCCESS);
}

int main() {
    
    pid_t initial = getpid();
//    unsigned int * processCount = (unsigned int *) myMap(sizeof(unsigned int));
    
    printf("Initial PID: %d\n", initial);
    printf("PIDS of all child processes: ");
    fflush(stdout);
    
    struct csvDir * info;
    processCsvDir(".", &info, NULL, NULL);
    
    printf("\nTotal number of processes: %d\n", 1 + *(info->numSubDirs) + *(info->numCsvPaths));
    
    printDirTree(stdout, info);

    exit(EXIT_SUCCESS);
}








//int main3(int argc, char ** argv) {
//
//    char * columnHeader = getColumnHeader(argc, argv);
//    char * inputDirecory = getInputDirectory(argc, argv);
//
//    if (inputDirecory == NULL) {
//        inputDirecory = ".";
//    }
//
//    char ** csvPaths;
//    int numCsv;
//
//    if (findCsvFiles(inputDirecory, &csvPaths, &numCsv)) {
//        
//        int fd[2];
//        pipe(fd);
//        pid_t * children = multiFork(numCsv);
//        pid_t * pids = (pid_t *) pipeDataToChildren(children, sizeof(pid_t) * numCsv,
//                                                    fd, children != NULL, numCsv);
//        
//        if (children == NULL){
//            
//            for (int i = 0; i < numCsv; i++) {
//                
//                if (getpid() == pids[i]) {
//                    
//                    
//                }
//            }
//            
//        } else {
//            
//            for (int i = 0; i < numCsv; i++) {
//                wait(NULL);
//            }
//        }
//
//    } else {
//
//        fprintf(stderr, "Specified directory not found: %s\n", inputDirecory);
//        exit(EXIT_FAILURE);
//    }
//
//    exit(EXIT_SUCCESS);
//}

//int main2(int argc, char ** argv) {
//
//    for (int i = 0; i < argc; i++) { // Loops through arguments.
//
//        if (!strcmp("-c", argv[i])) { // Looks for column header with flag.
//
//            if ((i + 1) >= argc) { // Checks argument after flag.
//
//                perror("Column header not specified");
//                exit(EXIT_FAILURE);
//
//            } else {
//
//                char * inputDirPath = ".";
//                char * outputDirPath;
//                int odps; // Is output directory path specified.
//
//                for (int j = 0; j < argc; j++) { // Loops through arguments.
//
//                    if (!strcmp("-d", argv[j])) {  // Looks for directory path with flag.
//
//                        if ((j + 1) >= argc) { // Checks argument after flag.
//
//                            perror("Input directory path not specified with -d flag");
//                            exit(EXIT_FAILURE);
//
//                        } else {
//
//                        }
//                    }
//                }
//
//                char *** table;
//                unsigned int rows;
//                unsigned int columns;
//                const char * columnHeader = argv[i + 1];
//
//                fillTable(stdin, &table, &rows, &columns);
//
//                if (sortByHeader(columnHeader, table, rows, columns)) {
//                    printTable(table, rows, columns);
//
//                } else {
//
//                    fprintf(stderr, "Specified column header not found: %s", columnHeader);
//                    exit(EXIT_FAILURE);
//                }
//
//                freeTable(&table, rows, columns);
//            }
//        }
//
//        if (!strcmp("-i", argv[i])) {
//
//            char *** table;
//            unsigned int rows;
//            unsigned int columns;
//
//            fillTable(stdin, &table, &rows, &columns);
//
//            if (rows < 31) {
//
//                perror("Table is to small to find interesting data");
//                exit(EXIT_FAILURE);
//
//            } else {
//                analize(table, rows, columns);
//            }
//
//            freeTable(&table, rows, columns);
//        }
//    }
//
//    exit(EXIT_SUCCESS);
//}

