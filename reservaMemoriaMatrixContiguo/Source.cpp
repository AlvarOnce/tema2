/**
* @file reserva_memoria_matriz_bloque_contiguo.cpp
* @brief Ejemplo de reserva de memoria para una matriz N x M (C++98)
*		 usando bloques contiguos y gestión de excepciones.
* @author Pablo San Segundo, curso Informática Industrial, ETSIDI, UPM
* @date 21/02/2023
* @last update 21/02/2026
*/

#include <iostream>
#include <cstddef>		// size_t
#include <new>


using mat_t = int;

using namespace std;

/**
 * @brief Allocates a 2D matrix using a single contiguous memory block.
 *
 * This function allocates an N x M matrix of type mat_t.
 * Memory layout consists of:
 *  - One contiguous block of N*M elements (row-major order).
 *  - An array of N pointers, each pointing to the beginning of a row.
 *
 * This design improves cache locality and reduces fragmentation
 * compared to allocating each row independently.
 *
 * @param N Number of rows.
 * @param M Number of columns.
 *
 * @return Pointer to an array of N row pointers.
 *         Returns nullptr if N == 0 or M == 0.
 *
 * @exception std::bad_alloc Thrown if memory allocation fails.
 *
 * @note The returned matrix must be freed using free_mat_eff().
 * @note Elements are value-initialized (zero-initialized for fundamental types).
 */
mat_t** allocate_mat_eff(size_t N, size_t M)
{
	if (N == 0 || M == 0) return nullptr;

	mat_t* table1D = nullptr;
	mat_t** ptr = nullptr;

	try {
		table1D = new mat_t[N * M]{};							/* initialized to 0 */

		ptr = new mat_t * [N] {};								/* initialized to 0 */

		for (size_t i = 0; i < N; ++i) {
			ptr[i] = table1D + i * M;
		}

		return ptr;
	}
	catch (...) {
		delete[] table1D;
		delete[] ptr;
		throw;
	}
}

/**
 * @brief Deallocates a matrix created with allocate_mat_eff().
 *
 * This function releases the memory associated with a 2D matrix
 * allocated using the contiguous-block strategy:
 *
 *  - Frees the single contiguous data block.
 *  - Frees the array of row pointers.
 *
 * After deallocation, the input pointer is set to nullptr
 * to prevent dangling references.
 *
 * @param[in,out] mat Reference to the matrix pointer.
 *                    If non-null, the memory is released and
 *                    the pointer is set to nullptr.
 *
 * @note Safe to call with nullptr.
 * @note This function must only be used with matrices allocated
 *       using allocate_mat_eff().
 *
 * @warning Undefined behavior if used with matrices allocated
 *          row-by-row using independent allocations.
 */
void free_mat_eff(mat_t**& mat)
{
	if (!mat) return;

	delete[] mat[0];					/* frees table */
	delete[] mat;						/* frees pointers */
	mat = nullptr;
}

void print_mat(mat_t** mat, int N, int M)
{
	for (int i = 0; i < N; i++) {
		const mat_t* row = mat[i];

		for (int j = 0; j < M; j++) {
			std::cout << row[j] << " ";
		}
		std::cout << std::endl;
	}
}

///////////////
//UNIT TESTS
///////////////

int main() {

	const size_t N = 3, M = 4;

	mat_t** mat = allocate_mat_eff(N, M);
	print_mat(mat, N, M);

	// usar matriz

	free_mat_eff(mat);
}