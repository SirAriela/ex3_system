#include "StrList.h"
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
    p->_head = NULL;
    p->_size = 0;
    return p;
}

// maked new node
Node *Node_alloc(const char *data,
                 Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->_data = data;
    p->_next = next;
    return p;
}

// returns list size
size_t StrList_size(const StrList *list)
{
    return list->_size;
}

// input new node in location i
void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    Node *temp;
    Node *head = StrList->_head;
    int size = StrList_size(StrList);

    if (index < size && index > 0)
    {
        while (index > 0)
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
    const Node *temp = StrList->_head;
    while (temp)
    {
        printf("%s ", temp->_data);
        temp = temp->_next;
    }
    printf("\n");
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
    }
    return countChars;
}

// remove all aperences of string
void StrList_remove(StrList *StrList, const char *data)
{
    Node *temp = StrList->_head;
    Node *helper = NULL;
    Node *nextNode;

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
                helper->_next = temp->_next;
            }
            nextNode = temp->_next;
            free(temp);
            temp = nextNode;
        }
        helper = temp;
        temp = temp->_next;
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

void StrList_reverse(StrList *StrList)
{
    Node *head = StrList->_head;
    Node *nextnode = NULL;
    Node *prevnode = NULL;

    while (head)
    {
        nextnode = head->_next; // save next neighbor
        head->_next = prevnode; // revers currunt node
        prevnode = head;        // save the current node before going to next node
        head = nextnode;        // move head to next node
    }
}

// check if list is sorted
int StrList_isSorted(StrList *StrList)
{
    Node *head = StrList->_head;

    while (head && head->_next)
    {
        //if first is shold be second str return 0
        if (strcmp(head->_data, head->_next->_data) > 0)
        {
            return 0;
        }
        head = head->_next;
    }
    //all is sorted
    return 1;
}