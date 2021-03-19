#include "Set.h"
#include <iostream>

using namespace std;

int main()
{
	Set<int> set = { 1, 2, 3, 4 };

	while (set.hasNext())
	{
		cout << set.next() << endl;
	}

	return 0;
}
