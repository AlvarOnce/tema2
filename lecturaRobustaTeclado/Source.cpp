/**
* @file patron_lectura_robusta_teclado.cpp
* @brief Ejemplo de lectura robusta de las dimensiones de una matriz desde teclado en C++.
*
* @details
*  - patrón: usa cin << para leer datos y en caso de errror cin.ignore para descartar la entrada no válida.
* @author Pablo San Segundo, curso Informática Industrial, ETSIDI, UPM
* @date 02/03/2026
*/

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <fstream>


/**
 * @struct dim_t
 * @brief Represents a pair of integer dimensions.
 *
 * This structure stores two integer values typically used
 * to represent matrix or grid dimensions.
 *
 * @note No invariants are enforced at the type level.
 *       Validation (e.g., positivity) must be ensured by the caller.
 */
struct dim_t {
	int n, m;
};

/**
 * @brief Reads two positive integer dimensions from standard input.
 *
 * Prompts the user to enter two integer values representing
 * dimensions (N and M). The function performs input validation:
 *
 * - If non-integer input is provided, the stream error state is cleared.
 * - Invalid input is discarded up to the next newline.
 * - The user is repeatedly prompted until valid positive integers are entered.
 *
 * @return dim_t A structure containing the validated dimensions.
 *
 * @note This function blocks until valid input is received.
 * @warning The function assumes an interactive console environment.
 *
 * @details:
 *	- C++14 use static auto get_dim() signature
 *  - C++11 use static auto get_dim() -> dim_t signature (trailing type syntax)
 */

static dim_t get_dim() {
	dim_t key_dim;
	std::cout << "Introduce N and M dimensions:" << std::endl;
	while (true) {

		// el flujo se convierte a bool mediante basic_ios::operator bool()
		// devuelve true si la extracción fue exitosa (no failbit/badbit)
		if (std::cin >> key_dim.n >> key_dim.m) {

			//@todo additional check for positive dimensions

			break;		//entry is valid, exit loop
		}

		//clears error flags- sets goodbit state
		std::cin.clear();

		//stops ignoring after '\n' 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "error... please try again." << std::endl;
	}
	return key_dim;
}

/// <summary>
/// Test unitario de la función get_dim() para lectura robusta de dimensiones de matriz desde teclado.
/// </summary>
/// <returns></returns>

int main() {

	dim_t dim = get_dim();
	std::cout << "Dimensions read: N = " << dim.n << ", M = " << dim.m << std::endl;

	/*int valor = 0;
	std::ostringstream oss("Ingrese tres numeros enteros \n");
	oss << "el numero es:" << valor;*/

	int a, b, c;

	std::istringstream iss("10 20 30");
	iss >> a >> b >> c;

	return 0;
}
