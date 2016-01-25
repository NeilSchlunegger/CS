#include "clist.h"

using namespace std;

void addHead(node*& head, int value)
{
	node* temp = head;
	while(temp->next != head)
	{
		temp = temp->next;
	}

	node* newNode = new node;
	newNode->data = value;

	if(head == NULL)
	{
		head = newNode;
		newNode->next = head;
	}
	else
	{
		newNode->next = head;
		head = newNode;
		temp->next = head;
	}
}


void myDisplay(node* head)
{
	cout << head->data << " -> ";
	return displayHelper(head, head->next);
	cout << endl;
}

void displayHelper(node* head, node* curr)
{
	if(head == curr)
	{
		cout << head->data;
		return;
	}
	
	cout << curr->data << " -> ";
	return displayHelper(head, curr->next);
}
