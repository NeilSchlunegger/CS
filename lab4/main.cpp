#include "clist.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	cout << "******ADDING 999 TO THE HEAD OF LIST**************" << endl;
	addHead(head, 999);
	cout << "******END ADDING 999 TO HEAD**********************" << endl;
	cout << "\n****MY RECURSIVE DISPLAY************************" << endl;
	cout << "My recursive display ";
	myDisplay(head);
	cout << "\n****END MY RECURSIVE DISPLAY********************" << endl;
	display(head); //resulting list after your function call!
    destroy(head);
    
    return 0;
}
