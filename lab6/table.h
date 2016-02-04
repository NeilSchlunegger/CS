//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied
void destroy(node * & root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
void duplicate(node* root, node*& newRoot);
int  findSmallest(node* root);
void remove(node*& root, int target);
void remHelper(node*& root, int target);
//void removeRootMatch();
//void removeMatch(node*& parent, node*& match, bool left);
void delNode(node*& root);
