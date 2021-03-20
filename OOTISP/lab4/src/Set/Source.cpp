#include "Set.h"
#include <iostream>

using namespace std;

int main()
{
	Set<int> set1 = { 4, 3 };
	Set<int> set2 = { 4, 1, 2, 3, 4, 5 };
	Set<int> set3;
	set3 = set1;

	while (set3.hasNext())
	{
		cout << set3.next() << " ";
	}
	set3.toStart();

	//while (set.hasNext())
	//{
	//	cout << set.next() << " ";
	//}
	//cout << endl;
	//set.toStart();

	//while (set2.hasNext())
	//{
	//	cout << set2.next() << " ";
	//}
	//set2.toStart();

	//cout << endl;

	//cout << (set < set2) << endl;
	//cout << (set2 < set) << endl;


	//Set<int> set3;
	//set3 = set;
	//while (set3.hasNext())
	//{
	//	cout << set3.next() << " ";
	//}

	//cout << endl << (set2 < set);
	//cout << endl << (set < set);

	return 0;
}
