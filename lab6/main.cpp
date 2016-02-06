#include "table.h"

#include <iostream>

using namespace std;

int main()
{
   	 node* root = NULL;
	 node* newRoot = NULL;
	 build(root);
   	 display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
	cout << "********DUPLICATING LIST**************" << endl;
	duplicate(root, newRoot);
	cout << "Duplicated list: ";
	display(newRoot);
	cout << "********END OF DUPLICATING LIST*******" << endl;
  	cout << "********REMOVING A SINGLE 100 VALUE***" << endl;
	remove(root, 100);
	display(root);
	cout << "********END OF REMOVAL****************";
	display(root);
   	 
	destroy(root);
  	destroy(newRoot);
	return 0;
}
