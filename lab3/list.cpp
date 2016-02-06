#include "list.h"

void duplicate(node* head, node*& newHead)
{
	if (head == NULL)
	{
		newHead = NULL;
		return;
	}
	
	newHead = new node;
	newHead->data = head->data;
	duplicate(head->next, newHead->next);
}

int removeTwo(node*& head)
{
	node* curr = head;
	node* prev = NULL;

	if(curr == NULL)
	{
		return 0;
	}
	else if(curr->data == 2)
	{
		if(curr == head)
		{
			node* currPtr = head;
			head = head->next;
			delete currPtr;
		//	currPtr = head;
			return 1 + removeTwo(head);
		}
		else if(curr->next == NULL)
		{
			delete curr;
			curr = NULL;
			prev->next = NULL;
			return 1;
		}
		else
		{
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
			return 1 + removeTwo(curr);
		}
	}
	else
	{
		return removeTwo(head->next);
	}
}


void addToEnd(node*& head, int passedData)
{
	if(head == NULL)
	{
		head = new node;
		head->data = passedData;
		head->next = NULL;
		return;
	}	

	return addToEnd(head->next, passedData);
}
void remEnd(node*& head)
{
	if(head->next->next == NULL)
	{
		head->next = NULL;
		return;
	}

	return remEnd(head->next);
}
int findMatch(node* head, int passedData)
{
	if(head == NULL)
	{
		return 0;
	}	

	if(head->data == passedData)
	{
		return 1 + findMatch(head->next, passedData);
	}
	else
	{
		return 0 + findMatch(head->next, passedData);
	}
}
void rem(node*& head, int passedData)
{
	node* curr = head;
	node* prev = NULL;

	if(head == NULL)
	{
		return;
	}
	else if(head->data == passedData)
	{
		if(head == curr)
		{
			node* temp = head;
			head = head->next;
			delete temp;
			return rem(head, passedData);
		}
		else if(curr->next == NULL)
		{
			delete curr;
			return;	
		}
		else
		{
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
			return rem(curr, passedData);
		}
	}
	else
	{
		return rem(head->next, passedData);		
	}
}
void remAll(node*& head)
{
	if(!head)
	{
		return;
	}
	else
	{
		remAll(head->next);
		delete head;
		head = NULL;
	}
}

bool hasDupe(node* head)
{
	if(head == NULL)
		return false;

	else
		return hasHelper(head,head->next);
}

bool hasHelper(node* head, node* next)
{
	if(!next)
		return false;

	if(head->data == next->data)
		return true;
	else	
		return hasHelper(head, next->next);
}
