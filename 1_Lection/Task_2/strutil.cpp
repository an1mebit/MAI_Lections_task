#include <iostream>

int strConteins(char* a, char* str)
{
	int i = 0; int j = 0;
	while (str[i] != NULL)
	{
		if (str[i] == a[0])
		{
			bool found = true;
			while (a[j] != NULL)
			{
				if (a[j] != str[i + j])
				{
					found = false;
					break;
				}
				j++;
			}
			if (found)
				return 0;
		}
		i++;
	}
	return -1;
}
