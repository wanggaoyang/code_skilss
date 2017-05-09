#include <iostream>
#include <string>
using namespace std;

void fuck(string str) {
	if (str == "")
		return;
	if (str.size() <= 8) {
		str.append(8 - str.size(), '0');
		cout << str << endl;
		return;
	}
	cout << str.substr(0, 8) << endl;//如果长度大于8，那就只输出前8个
	fuck(str.substr(8, str.size()));//这个递归用的屌
}
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	fuck(str1);
	fuck(str2);
	return 0;
}
