#include <iostream>
#include <string>

/*Вариант 1.
Номер варианта – остаток от деления суммы всех букв фамилии на число вариантов.*/

int main()
{
	int var_numb = 2;
	std::string surname;
	std::cin >> surname;
	int var = surname.size() % var_numb + 1;
	std::cout << "Yor variant is " << var;
	return 0;
}
