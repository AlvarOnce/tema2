/**
* @file reserva_memoria_matriz.cpp
* @brief Ejemplo de reserva de memoria para una matriz N x M (C++98)
*		 con gestión de excepciones.
* @author Pablo San Segundo, curso Informática Industrial, ETSIDI, UPM
* @date 26/02/2022
* @last_update 21/02/2026
**/

#include <iostream>
#include <cstddef>		// size_t
#include <new>

using mat_t = int;

using namespace std;

/*********************************/
void free_mat(mat_t**& m, size_t N)
/*********************************/
{
	for (size_t i = 0; i < N; ++i) {
		delete[] m[i];
	}

	delete[] m;
	m = nullptr;
}

/******************************************/
mat_t** allocate_mat(size_t N, size_t M)
/******************************************/
{
	mat_t** m = nullptr;

	try {

		m = new mat_t * [N] {};					// inicializa a 0 todos los punteros. 
		// Obligatorio para librerar correctamente en caso de excepción (1)
		for (size_t i = 0; i < N; ++i) {
			m[i] = new mat_t[M]{};				// inicializa a 0
		}
		return m;
	}
	catch (...) {								// captura cualquier excepción
		free_mat(m, N);							// libera lo que se haya podido reservar (1)
		throw;									// re-lanza la excepción
	}

}

/***********************************************/
void print_mat(mat_t** m, size_t N, size_t M)
/**********************************************/
{
	for (size_t i = 0; i < N; i++) {
		const mat_t* row = m[i];

		for (size_t j = 0; j < M; j++) {
			cout << row[j] << " ";
		}
		cout << endl;
	}
}


////////////////////
//TEST UNITARIOS
///////////////////

int main(void) {

	auto** mat = allocate_mat(2, 3);
	print_mat(mat, 2, 3);

	// usar matriz...

	free_mat(mat, 2);
}





