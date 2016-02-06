#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	cout << "******************************************************************\nDisplaying duplicate list: ";
	node* newHead = NULL;
	duplicate(head, newHead);
	bool yeah = hasDupe(head);
	if(yeah)
		cout << "dupe found" << endl;
	else
		cout << "dupe not found" << endl;
//	display(newHead);
	//cout << "This many twos: " << findMatch(head,2) << endl;
//	cout << "Removing 10 from copied list: " << endl;
//	 rem(newHead,10);	
	cout << "removing end from copied list: ";
	remEnd(newHead);
	display(newHead);
	cout << "Removing all the rest of copied list: ";
	remAll(newHead);
	display(newHead);
	cout << "***************************************************" << endl;
	cout << "\n******************Removing 2s*******************************" << endl;
	cout << "After removing " << removeTwo(head) << " twos and adding 3 to the end" << endl;
	addToEnd(head, 3);
    display(head);
    destroy(head);
    destroy(newHead);
    return 0;
}
