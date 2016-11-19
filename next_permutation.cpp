#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int a[] = {1, 2, 3, 4};
	do  {
			cout << a[0] <<a[1] <<a[2] <<a[3];
		cout << "\n";
	} 	while (next_permutation(a, a+4));
	char b[] = "abc";

	do {
		cout << b << "\n";
}	while (next_permutation(b, b+3));

	vector<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	do {
		for (int i = 0; i < c.size(); i++)
			cout << c[i] << " ";
		cout << '\n';
	}	while (next_permutation(c.begin(), c.end()));
	return 0;
}
