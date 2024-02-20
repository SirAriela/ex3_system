#include "StrList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 1024
void insertStringsIntoList(StrList* list, int numWords) {
    printf("Enter %d word(s) to insert (separated by space):\n", numWords);

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

void insertStringAtIndex(StrList* list) {
    int index;
    char input[MAX_STRING_LENGTH];

    printf("Enter the index where you want to insert: ");
    scanf("%d", &index);
    getchar(); // Consume newline character
    if (index<StrList_size(list))
    {
    printf("Enter the word to insert: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline character

    StrList_insertAt(list, input, index);
    }
}

void printListLength(const StrList* list) {
    printf("List length: %zu\n", StrList_size(list));}

void printStringAtIndex(const StrList* list, int index) {
    printf("String at index %d: ", index);
    if (index<StrList_size(list)){
    StrList_printAt(list, index);
    }
}

void printTotalCharacters(const StrList* list) {
    printf("Number of characters in the entire list: %d\n", StrList_printLen(list));
}
void printAllList(const StrList* list){
 printf("List contents:\n");
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
        printf("Enter the number of words to insert: ");
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