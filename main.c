#include "StrList.h"
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

void insertStringsIntoList(StrList *list, int numWords)
{
    char *input = malloc(sizeof(char) * MAX_STRING_LENGTH); // Allocate memory for input

    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    char *token = strtok(input, " ");
    while (token != NULL && numWords > 0)
    {
        StrList_insertLast(list, token);
        token = strtok(NULL, " ");
        numWords--;
    }
    // free(input); // Free dynamically allocated memory
}

int main()
{
    StrList *myList = StrList_alloc();

    int choice;
    int numWords;
    int index;

    scanf("%d", &choice);
    while (choice != 0)
    {
        if (choice == 1)
        {
            scanf("%d", &numWords);
            insertStringsIntoList(myList, numWords);
        }
        //-------------------------------------------------------------------
        if (choice == 2)
        {
            char *text = (char *)malloc(100 * sizeof(char));

            if (text == NULL)
            {
                printf("coulndt allocate memory for function 2");
            }
            else
            {
                scanf("%d", &index);
                scanf("%s", text);
                StrList_insertAt(myList, text, index);
            }
        }
        //  ------------------------------------------------------------------------

        if (choice == 3)
        {
            StrList_print(myList);
        }

        // -----------------------------------------------------------------------------------

        if (choice == 4)
        {
            int size = StrList_size(myList);
            printf("%d\n", size);
        }

        //---------------------------------------------------------

        if (choice == 5)
        {
            scanf("%d", &index);
            StrList_printAt(myList, index);
        }

        //--------------------------------------------------------

        if (choice == 6)
        {
            int numberOfChars = StrList_printLen(myList);
            printf("%d\n", numberOfChars);
        }

        // ----------------------------------------------------------

        if (choice == 7)
        {
            char *text = (char *)malloc(100 * sizeof(char));

            if (text != NULL)
            {
                scanf("%s", text);
                int times = StrList_count(myList, text);
                printf("%d\n", times);
                free(text);
            }
        }

        //-----------------------------------------------------------------

        if (choice == 8)
        {
            char *text = (char *)malloc(100 * sizeof(char));

            if (text != NULL)
            {
                scanf("%s", text);
                StrList_remove(myList, text);
                free(text);
            }
        }

        //-------------------------------------------------------------------

        if (choice == 9)
        {
            scanf("%d", &index);
            StrList_removeAt(myList, index);
        }

        //---------------------------------------------------------------------

        if (choice == 10)
        {
            StrList_reverse(myList);
        }

        //---------------------------------------------------------------------

        if (choice == 11)
        {
            index = StrList_size(myList);

            while (index > 0)
            {
                StrList_removeAt(myList, 0);
                index--;
            }

        }

        //----------------------------------------------------------------------

        if (choice == 12)
        {
            StrList_sort(myList);
        }

        //-----------------------------------------------------------------------

        if (choice == 13)
        {
            index = StrList_isSorted(myList);
            if(index == 1? printf("%s\n", "true"):printf("%s\n", "false"));     
        }

        //-----------------------------------------------------------------------
        scanf("%d", &choice);
    }

    // Free memory
    StrList_free(myList);

    return 0;
}