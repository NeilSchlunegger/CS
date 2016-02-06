#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	cout << "\n***************************************************" << endl;
	cout << "******************Duplicating list**************************" << endl;
	cout << "******************************************************************\nDisplaying duplicate list: ";
	node* newHead = NULL;
	duplicate(head, newHead);
	display(newHead);
	cout << "\n******************************************************************" << endl;
	cout << "******************End of duplicating list********************" << endl;
	cout << "***************************************************" << endl;
	cout << "\n******************Removing 2s*******************************" << endl;
	cout << "After removing " << removeTwo(head) << " twos:";
    display(head);
    destroy(head);
    destroy(newHead);
    return 0;
}
