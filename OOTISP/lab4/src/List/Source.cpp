#include "List.h"

using namespace std;

int main() {
	List<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(10);
	lst.push_front(6);
	lst.insert(9, 2);
	for(int i = 0; i < lst.get_length(); i++) 
	{
		cout << lst[i] << endl;
	}
	lst.removeAt(2);
	for (int i = 0; i < lst.get_length(); i++)
	{
		cout << lst[i] << endl;
	}
	lst.pop_back();
	for (int i = 0; i < lst.get_length(); i++)
	{
		cout << lst[i] << endl;
	}
	return 0;
}