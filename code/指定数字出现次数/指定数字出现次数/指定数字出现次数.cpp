//指定数字出现次数
#include <iostream>
using namespace std;

int findDigitOccurrence(int num1,long num2) {
	int count = 0;
	while (num2) {
		int temp = num2 % 10;
		cout << temp << endl;
		if (temp == num1)
			count++;
		num2 /= 10;
	}
	return count;
}

int main() {
	int rel = findDigitOccurrence(2, 123228);
	cout << rel;
	return 0;
}