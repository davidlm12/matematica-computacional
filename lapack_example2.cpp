#include <iostream>
#include <lapacke.h>

int main() {   
    
    double A[4] = {3, 1, 2, 4};    
    
    double b[2] = {5, 6};

    // Dimensiones
    int n = 2;    // Número de filas/columnas de A
    int nrhs = 1; // Número de columnas en b (1 porque es un vector)
    int lda = 2;  // Leading dimension de A
    int ldb = 2;  // Leading dimension de b

    // Variables de pivoteo y estado
    int ipiv[2];  // Array para las permutaciones pivot
    int info;     // Código de retorno de LAPACK
   
    info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, A, lda, ipiv, b, ldb);

    if (info == 0) {
        std::cout << "Solucion del segundo ejemplo:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "x[" << i << "] = " << b[i] << std::endl;
        }
    } else {
        std::cerr << "Error al resolver el sistema, codigo: " << info << std::endl;
    }

    return 0;
}