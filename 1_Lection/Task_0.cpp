#include <iostream>

int main()
{
	unsigned int a = 0; int b = 2;
	std::cin >> a;
	if (a == 0)
	{
		exit(0);
	}
	int var = a % b + 1;
	std::cout << var;
	return 0;
}
