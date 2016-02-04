#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
	node* newHead = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	cout << "************DUPLICATING LIST********************" << endl;
	duplicate(head,newHead);
	cout << "DISPLAYING DUPLICATED LIST: ";
	display(newHead);
	cout << "\n***********END OF DUPLICATING LIST**************" << endl;
	cout << "\n***********REMOVING TWOS*************************" << endl;
	cout << "After removing " << removeTwo(head) << " twos: ";
	display(head);
	cout << "***********END OF REMOVING TWOS******************" << endl;
    destroy(head);    
    destroy(newHead);
	
	return 0;
}
