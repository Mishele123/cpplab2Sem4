
#include "header.h"



int main()
{
	setlocale(LC_ALL, "ru");
	HashTable<int, std::string> _table(1);

	std::cout << "Метод insert" << std::endl;
	_table.insert(1, "100");
	_table.print();
	std::cout << std::endl;
	_table.insert(1, "200");
	_table.insert(2, "200");
	_table.print();
	
	std::cout << "Метод contains для значения = 200" << std::endl;
	std::cout << std::endl;
	std::cout << _table.contains("200") << std::endl;
	std::cout << std::endl;

	std::cout << "Метод insert_or_assign (1, 400)" << std::endl;
	_table.insert_or_assign(1, "400");
	_table.print();
	std::cout << std::endl;

	std::cout << "Метод search(2)" << std::endl;
	std::cout << _table.search(2) << " = " << *_table.search(2) << std::endl;

	std::cout << "Операция удаления erase(2)" << std::endl;
	_table.erase(2);
	_table.print();

	return 0;
}