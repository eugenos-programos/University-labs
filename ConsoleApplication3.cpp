
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	char st[20];      
	int arr1[20], tmp = 1, tmp1 = 0;
	puts("Input string ");
	gets_s(st);
	for (int i = 0; i < sizeof(st) - 1; i++) {
		if (st[i] == st[i + 1])tmp++;
		else {
			arr1[tmp1] = tmp;
			tmp1++;
			tmp = 1;
		}
	}
	int max, index = 0;
	max = arr1[0];
	for (int i = 0; i < tmp1 -1; i++) {
		if (max < arr1[i]) {
			max = arr1[i];
			index = i;
		}
	}
	if ((st[0] == '1') && ((index % 2 == 0) || index == 0)) {
		for (int i = 0; i < max; i++) cout << "1";
	}
	if ((st[0] == '1') && (index % 2 == 1)) {
		for (int i = 0; i < max; i++) cout << "0";
	}
	if ((st[0] == '0') && (index % 2 == 0)) {
		for (int i = 0; i < max; i++) cout << "0";
	}
	if ((st[0] == '0') && (index % 2 == 1)) {
		for (int i = 0; i < max; i++) cout << "1";
	}
}
