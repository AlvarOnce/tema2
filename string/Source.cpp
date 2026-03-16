#include <iostream>
#include <string>

using namespace std;

int main() {
	string str("Hello, can you find Ben?");
	string::size_type pos = str.find("Ben", 10, 2); //a partir de pos:=15,"Be"
	if (pos != string::npos) {
		cout << "First occurrence of Ben was found at: " << pos << endl;
		cout << str.substr(pos, 3);
	}
	return 0;
}