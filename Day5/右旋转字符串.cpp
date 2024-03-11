#include <iostream>
#include <algorithm>

using namespace  std;



int main(int argc, char const *argv[])
{
	string str;
	int n;
	cin >> str;
	cin << n;

	int len = str.size();

	reverse(str.begin(), str.end()); //整体反转
	reverse(str.begin(), str.begin() + n);
	reverse(str.begin() + n, str.end());
	cout << str << endl;
	return 0;
}