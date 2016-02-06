
//list.h
#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

//Write your function prototype here:
void duplicate(node* head, node*& newHead);
int removeTwo(node*& head);
void addToEnd(node*& head, int passedData);
int findMatch(node* head, int passedData);
void rem(node*& head, int passedData);
void remAll(node*& head);
void remEnd(node*& head);
bool hasDupe(node* head);
bool hasHelper(node* head, node* next);
