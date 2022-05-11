#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct admin
{
    char username[100];
	char password[100];
}Admin;



typedef struct adminlistnode{
    Admin  Data;
    struct adminlistnode * Next;

}AdminListNode;



typedef struct adminListLinkedBased
{
    AdminListNode * Head;
    int Size;AdminList
}AdminList;



void AdminList_voidInit( *pl);
void AdminList_voidInsertList(int Position, AdminList *pl, Admin Element);



void AdminList_voidInit(AdminList *pl){
    pl->Head = NULL;
    pl->Size = 0;
}


void AdminList_voidInsertList(int Position, AdminList *pl, Admin  Element){
    /*create new node and intialize its data*/
    AdminListNode* pn = (AdminListNode *)malloc(sizeof(AdminListNode));
    pn->Data = Element;

    /*corner case : insertion in the first plcae*/
    if (Position == 0){
        pn->Next = pl->Head;
        pl->Head = pn;
    }

    /*General case : Insert in any position instead of position 0*/
    else{
        /*create a new pointer of list node and iterate until reaching the position before that i want*/
        AdminListNode * pn2 = pl->Head;
        for(int i = 0; i < Position-1; i++ ){
            pn2 = pn2->Next;
        }
        /*Insertion Step*/
        pn->Next = pn2->Next;
        pn2->Next = pn;

    }
    /*increasing the size of the list*/
    pl->Size++;
}





