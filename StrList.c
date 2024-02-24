#include "StrList.h"
#include "stdio.h"
#include "string.h"

// the struct of list and the nodes
typedef struct _node
{
    char *_data;
    struct _node *_next;
} Node;

struct _StrList
{
    Node *_head;
    size_t _size;
};

// free all memmory
void StrList_free(StrList *StrList)
{
    if (StrList == NULL)
        return;
    Node *p1 = StrList->_head;
    Node *p2;
    while (p1)
    {
        p2 = p1;
        p1 = p1->_next;
        free(p2);
    }
    free(StrList);
}

// makes new list
StrList *StrList_alloc()
{
    StrList *p = (StrList *)malloc(sizeof(StrList));
    if (p != NULL){
        p->_head = NULL;
        p->_size = 0;
    }
    return p;
}

// maked new node
Node *Node_alloc(const char *data, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p != NULL)
    {
        p->_data = data;
        p->_next = next;
    }
    return p;
}

// returns list size
size_t StrList_size(const StrList *list)
{
    return list->_size;
}
// Inserts an element at the end of the StrList
void StrList_insertLast(StrList *StrList, const char *data)
{
    Node *newNode = Node_alloc(data, NULL); // Create a new node with the provided data and NULL next pointer
    

    // If the list is empty, make the new node the head of the list
    if (StrList->_head == NULL)
    {
        StrList->_head = newNode;
    }
    else
    {
        // Traverse the list to find the last node
        Node *temp = StrList->_head;
        while (temp->_next != NULL)
        {
            temp = temp->_next;
        }
        // Insert the new node at the end of the list
        temp->_next = newNode;
    }
    
    

    StrList->_size++; // Increment the size of the list
}
// Returns the data of the first node in the StrList
char *StrList_firstData(const StrList *StrList)
{
    // If the list is empty, return NULL
    if (StrList->_head == NULL)
    {
        return NULL;
    }
    // Otherwise, return the data of the first node
    return StrList->_head->_data;
}

// input new node in location i
void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    Node *temp;
    Node *head = StrList->_head;
    int size = StrList_size(StrList);

    if (index < size && index > 0)
    {
        while (index > 1)
        {
            head = head->_next;
            index--;
        }
        temp = Node_alloc(data, head->_next);
        head->_next = temp;
        StrList->_size++;
    }
}

// print all list
void StrList_print(const StrList *StrList)
{
    if (StrList == NULL)
    {
        printf("List is empty\n");
        return;
    }

    const Node *temp = StrList->_head;

    while (temp)
    {
        printf("%s ", temp->_data);
        temp = temp->_next;
    }
    printf("\n");
}
// Prints the word at the given index to the standard output
void StrList_printAt(const StrList *StrList, int index)
{
    const Node *temp = StrList->_head;
    int currentIndex = 0;

    // Traverse the list until the desired index or end of list is reached
    while (temp != NULL && currentIndex < index)
    {
        temp = temp->_next;
        currentIndex++;
    }

    // If index is valid and node is found, print the data at that index
    if (temp != NULL && currentIndex == index)
    {
        printf("%s\n", temp->_data);
    }
}

// number of chars in llist total
int StrList_printLen(const StrList *Strlist)
{
    int countChars = 0;
    Node *temp = Strlist->_head;

    while (temp)
    {
        int sizeOfString = strlen(temp->_data);
        countChars += sizeOfString;
        temp = temp->_next;
    }

    return countChars;
}
// Given a string, return the number of times it exists in the list
int StrList_count(StrList *StrList, const char *data)
{
    int count = 0;
    Node *temp = StrList->_head;

    // Traverse the list and count occurrences of the given string
    while (temp != NULL)
    {
        if (strcmp(temp->_data, data) == 0)
        {
            count++;
        }
        temp = temp->_next;
    }

    return count;
}

// remove all aperences of string
void StrList_remove(StrList *StrList, const char *data)
{
    Node *temp = StrList->_head;
    Node *prev = NULL;
    Node *helper = NULL;

    while (temp)
    {
        if (strcmp(temp->_data, data) == 0)
        {
            if (temp == StrList->_head)
            {
                StrList->_head = temp->_next;
                
            }
            else
            {
                prev->_next = temp->_next; 
            }
            helper = temp;
            temp = temp->_next;

            free(helper);
            StrList->_size--;
        }
        
        else{
            prev = temp;
            temp = temp->_next;
        }
        
        
    }
}
void StrList_removeAt(StrList *StrList, int index)
{
    if (index < 0 || index >= StrList->_size || StrList->_head == NULL)
    {
        return; // Index out of bounds or empty list
    }

    Node *current = StrList->_head;
    Node *prev = NULL;
    int currentIndex = 0;

    // Traverse the list until the desired index is reached
    while (current != NULL && currentIndex < index)
    {
        prev = current;
        current = current->_next;
        currentIndex++;
    }

    // If the index is found, remove the node
    if (current != NULL)
    {
        // Update pointers to bypass the node to be removed
        if (prev == NULL)
        {
            StrList->_head = current->_next;
        }
        else
        {
            prev->_next = current->_next;
        }
        free(current);        // Free memory allocated for the node
        StrList->_size--;     // Decrement the size of the list
    }
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
{
    Node *head1 = StrList1->_head;
    Node *head2 = StrList2->_head;

    if (StrList_size(StrList1) != StrList_size(StrList2))
        return 0;

    while (head1)
    {
        if (strcmp(head1->_data, head2->_data) != 0)
            return 0;
        head1 = head1->_next;
        head2 = head2->_next;
    }
    return 1;
}
// Clones the given StrList
StrList *StrList_clone(const StrList *StrList)
{

    struct _StrList *cloneList = StrList_alloc(); // Allocate memory for the new list

    // Check if the original list is empty
    if (StrList->_head == NULL)
    {
        return cloneList; // Return the empty clone list
    }

    Node *current = StrList->_head;

    // Traverse the original list and copy each element to the new list
    while (current != NULL)
    {
        StrList_insertLast(cloneList, current->_data); // Insert the data into the clone list
        current = current->_next;                      // Move to the next node
    }

    return cloneList;
}

void StrList_reverse(StrList *StrList)
{
    Node *head = StrList->_head;
    Node *nextnode = NULL;
    Node *prevnode = NULL;

    while (head != NULL)
    {
        nextnode = head->_next; // save next neighbor
        head->_next = prevnode; // revers currunt node
        prevnode = head;        // save the current node before going to next node
        head = nextnode;        // move head to next node
    }

    StrList->_head = prevnode;
}

// Sort the given list in lexicographical order
void StrList_sort(StrList *StrList)
{
    if (StrList->_head == NULL || StrList->_head->_next == NULL)
    {
        return; // List is empty or has only one node, no need to sort
    }

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = StrList->_head;

        while (ptr1->_next != lptr)
        {
            // Compare adjacent strings and swap if they are in the wrong order
            if (strcmp(ptr1->_data, ptr1->_next->_data) > 0)
            {
                char *temp = ptr1->_data;
                ptr1->_data = ptr1->_next->_data;
                ptr1->_next->_data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->_next;
        }
        lptr = ptr1;
    } while (swapped);
}

// check if list is sorted
int StrList_isSorted(StrList *StrList)
{
    Node *head = StrList->_head;

    while (head && head->_next)
    {
        // if first is shold be second str return 0
        if (strcmp(head->_data, head->_next->_data) > 0)
        {
            return 0;
        }
        head = head->_next;
    }
    // all is sorted
    return 1;
}