/*#include <iostream>	

namespace limon {

	namespace detalles {
		void foo_interna() {
			std::cout << "hola detalles foo interna" << std::endl;
		}
	}

	void foo() {
		std::cout << "hola foo" << std::endl;
		detalles::foo_interna();
	}
	void foo2() {
		std::cout << "hola foo2" << std::endl;
	}
	void foo3() {
		std::cout << "hola foo3" << std::endl;
	}
}
/*
using namespace limon;
using namespace limon::detalles;
using limon::foo;
*/
/*
int main() {
	limon::foo();
	limon::detalles::foo_interna();

}
*/