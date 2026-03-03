#include <iostream>

enum palo {
	OROS = 0,
	COPAS,
	ESPADAS,
	BASTOS = 4
};

int main() {
	int j = static_cast<int>(palo::OROS);
	std::cout << j << std::endl;
	return 0;
}