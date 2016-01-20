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
			currPtr = head;
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
