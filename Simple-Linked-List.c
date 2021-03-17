#include <stdio.h>
#include <stdlib.h>

//Written by: H.Haziq, 17/03/2021
//Basic linked list program with insert and delete feature
//Error handling is not considered
//No feature as sorting, reversing, query list

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int _data, struct Node *nextNode) //create new node
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = _data;
    newNode->next = nextNode;

    return newNode;
}

int listLength() //return length of the list
{
    struct Node *tmp = head;

    int itr = 0;
    while (tmp != NULL)
    {
        itr++;
        tmp = tmp->next;
    }
       
    return itr;
}

void insertFront(int _data) //insert data at front of list
{   
    struct Node *newNode = createNode(_data,head);

    head = newNode;
}

void insertBack(int _data) //insert data at back of list
{
    struct Node *newNode = createNode(_data,NULL);

    if (head == NULL) //if empty list
    {
        head = newNode;
        return;
    }
    
    //iterate to last node in list
    struct Node *tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next;
    }

    //point last node to new node
    tmp->next = newNode;
}

void insertAt(int index, int _data)
{
    struct Node *newNode = createNode(_data,NULL);

    //if index is 0, same as front insertion
    if (index == 0)
    {
        insertFront(_data);
        return;
    }
    
    //iterate through list using given index value
    int itr = 0;
    struct Node *tmp = head;
    struct Node *b4tmp = NULL;
    while(tmp != NULL)
    {
        if (itr == index) //perform insertion at given index
        {
            b4tmp->next = newNode;
            newNode->next = tmp;
            
            return;
        }

        b4tmp = tmp;
        tmp = tmp->next;
        itr++;
    }
    
}

void deleteFront() //delete first node in list
{
    head = head->next;
}

void deleteBack() //delete last node in list
{
    struct Node *tmp = head;
    struct Node *b4tmp = NULL;

    //iterate until last node
    while (tmp->next)
    {
        b4tmp = tmp;
        tmp = tmp->next;
    }
    
    //delete last node
    b4tmp->next = NULL;
    tmp = NULL;  
}


void deleteAt(int index)
{
    if (index == 0) //if index is 0, same as front deletion
    {
        deleteFront();
        return;
    }
    
    //iterate through list using given index value
    int itr = 0;
    struct Node *tmp = head;
    struct Node *b4tmp = NULL;
    while(tmp != NULL)
    {
        if (itr == index) //perform deletion at given index
        {
            b4tmp->next = tmp->next;
            tmp->next = NULL;
            
            return;
        }

        b4tmp = tmp;
        tmp = tmp->next;
        itr++;
    }
    
}

void printList()
{
    struct Node *tmp = head;

    printf("[ ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("]");
}

void main()
{
    //USE CASE: [5]->[5 16]->[5 10 16]->[5 20 10 16]->[20 10 16]->[20 10]->[20]->[]
    
    insertFront(5);
    insertBack(16);
    insertAt(1,10);
    insertAt(1,20);
    
    printf("List length: %d\n", listLength());
    
    printf("After insert: ");
    printList();
    printf("\n");

    deleteFront();
    deleteBack();
    deleteAt(1);
    deleteAt(0);
    
    printf("After delete: ");
    printList();
    printf("\n");
}