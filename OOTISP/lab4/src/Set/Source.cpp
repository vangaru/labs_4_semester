#include "Set.h"

int main()
{
	Set<int>* set = new Set<int>({ 4, 1, 2, 3, 5, 3, 4, 4, 4, 4 } );

	set->display();

	std::cout << std::endl << set->size();

	return 0;
}