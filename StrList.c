#include "StrList.h"

typedef struct _node {
    char* _data;
    struct _node * _next;
} Node;


struct _StrList {
    Node* _head;
    size_t _size;
};
void StrList_free(StrList* StrList){
    if (StrList==NULL) return;
	Node* p1= StrList->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		free(p2);
	}
	free(StrList);
}
// StrList* StrList_alloc(){
//     StrList* p= (StrList*)malloc(sizeof(StrList));
// 	p->_head= NULL;
// 	p->_size= 0;
// 	return p;
// }

Node* Node_alloc(const char* data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	return p;
}

size_t StrList_size(const StrList* list) {
	return list->_size;
}

void StrList_insertAt(StrList* StrList,	const char* data,int index){
    Node* temp;
    Node* head = StrList->_head;
    int size = StrList_size(StrList);
    
    if(index < size && index > 0){
        while(index > 0){
            head = head->_next;
            index--;
        }
        temp = Node_alloc(data,head->_next);
        head->_next = temp;
        StrList->_size++;
    }
}