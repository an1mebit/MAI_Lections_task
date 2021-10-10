#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n;	int i = -1;
	cout << "Enter a number of numbers" << endl;
	cin >> n;
	vector<int> num(n + 1);

	generate(num.begin(), num.end(), [&i] {i++; return i; });
	copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
}
