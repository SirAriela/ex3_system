#include "StrList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 1024
void insertStringsIntoList(StrList* list, int numWords) {
     char *input = malloc(sizeof(char) * MAX_STRING_LENGTH); // Allocate memory for input
    
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    char *token = strtok(input, " ");
    while (token != NULL && numWords > 0) {
        StrList_insertLast(list, token);
        token = strtok(NULL, " ");
        numWords--;
    }
    free(input); // Free dynamically allocated memory
}

void insertStringAtIndex(StrList* list, const char* data, int index) {
    StrList_insertAt(list, data, index);
}

void printListLength(const StrList* list) {
    printf(" %zu\n", StrList_size(list));}

void printStringAtIndex(const StrList* list, int index) {
    if (index<StrList_size(list)){
    StrList_printAt(list, index);
    }
}

void printTotalCharacters(const StrList* list) {
    printf("%d\n", StrList_printLen(list));
}
void printAllList(const StrList* list){
    StrList_print(list);
}
void freeAllMemory(const StrList* list){
 StrList_free(list);
}
int countOccurrences(const StrList* list, const char* str) {
    return StrList_count(list, str);
}
void removeAllOccurrences(StrList* list, const char* str) {
    while (StrList_count(list, str) > 0) {
        StrList_remove(list, str);
    }
}
void removeStringAtIndex(StrList* list, int index) {
    if (index<StrList_size(list)){
    StrList_removeAt(list, index);
    }
}
void reverseList(StrList* list) {
    StrList_reverse(list);
}
void sortList(StrList* list) {
    StrList_sort(list);
}
int isListSorted(const StrList* list) {
    return StrList_isSorted(list);
}
void exitProgram() {
    exit(0); // Exit the program with a status code of 0 (success)
}




int main() {
    StrList* myList = StrList_alloc();

    char choice;
    int numWords;

    while (1)
    {
    
    scanf("%c", &choice);
    getchar(); // Consume newline character

    if (choice == 'A' ) {
        scanf("%d", &numWords);
        getchar(); // Consume newline character

        insertStringsIntoList(myList, numWords);
    } }

    // Print the list
    printf("List contents:\n");
    StrList_print(myList);

    // Free memory
    StrList_free(myList);

    return 0;
}