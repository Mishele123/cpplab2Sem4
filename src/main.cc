
#include "header.h"



int main()
{
	HashTable<int, std::string> _table(1);

	_table.insert(1, "100");
	_table.insert(1, "200");

	_table.print();

	return 0;
}