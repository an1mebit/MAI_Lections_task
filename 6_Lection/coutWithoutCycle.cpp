#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int n;
	cout << "Enter a number of numbers" << endl;
	cin >> n;
  
	string num;
	for (int i = 0; i < n + 1; i++)
		num += i;
	copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
}
