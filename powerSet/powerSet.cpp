#include <iostream>
#include <set>
#include <string>

using namespace std;
// template vs function: template is type independent. myType is an abstract Type. We call with concrete data type and compiler uses appropriate data type
template<typename myType> set<myType> * power(const myType * parm, size_t size)
{
	set<myType> * result = new set<myType>;
	if(size > 0)
	{
		set<myType> * temp = power(parm, size - 1);
		for(auto itr1 = temp->begin(); itr1 != temp->end(); itr1++) // unioning everything with removed
		{
			for(auto itr2 = parm->begin(); itr2 != parm->end(); itr2++)
			{
				myType temp2(*itr1);
				temp2.insert(*itr2);
				result->insert(temp2);
			}
			result->insert(temp->begin(),temp->end());//unioning with original set
		}
	}
	else
	{
		result->insert(myType()); // empty constructor on set gives you empty set. So we are inserting a set of nothing
	}

	return result; // return is a pointer to a  set of the same type
}


int main()
{
	set<string> setA;
	set<string> setB;
	set<set<string>> powerSet;



	return 0;
}
