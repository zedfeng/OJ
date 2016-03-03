#include <iostream>
using namespace std;
int main() {
	char *words[] = { "huh","hello" };
	cout << sizeof(char*) << sizeof(words) << sizeof(words[0]) << sizeof(words[1]) << endl;

	system("Pause");
	return 0;
}