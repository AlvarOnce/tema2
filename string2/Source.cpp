#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "C++ is an impressive language.";
	auto pos = str.find_first_of(" .");
	while (pos != string::npos) {
		cout << "Found space or dot at: " << pos << endl;
		pos = str.find_first_of(" .", pos + 1);
	}
	return 0;
}