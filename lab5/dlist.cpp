#include "dlist.h"

void duplicate(node* head, node*& newHead)
{
	if(!head)
	{
		newHead = NULL;
		return;
	}

	newHead = new node;
	newHead->data = head->data;
	newHead->previous = head->previous;
	duplicate(head->next, newHead->next);
}

int removeTwo(node*& head)
{
	if(head == NULL)
	{
		return 0;
	}
	
	if(head->data == 2)
	{
		node* temp = head;
		if(head->next != NULL)
		{
			head = head->next;//if there is a next, advance to it
			if(temp->previous != NULL)//if there is a previous, skip over temp (aka delete)
			{
				head->previous = temp->previous;
			}
			else
			{
				head->previous = NULL;
			}
		}
		else// there is only the head remaining
		{
			delete head; 
			head = NULL;
			return 1; // end of list
		}
		delete temp;
		return 1 + removeTwo(head);
	}
	else
	{
		return removeTwo(head->next);
	}
}
