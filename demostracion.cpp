#include <iostream>
#include <vector>
#include <lapacke.h>

int main() {
    // Definir dimensiones de la matriz A (2x2)
    lapack_int m = 2;
    lapack_int n = 2;
    lapack_int lda = n;
    lapack_int ldu = m;
    lapack_int ldvt = n;

    // Matriz A
    double a[2 * 2] = {
        1.0, -0.8,
        0.0,  1.0
    };

    // Arreglos para los resultados
    double s[2];    // Valores singulares 
    double u[3 * 3]; 
                     
    double vt[2 * 2];
    double superb[1]; 

      // 'A' significa calcular todas las columnas de U y filas de VT
    lapack_int info = LAPACKE_dgesvd(LAPACK_ROW_MAJOR, 'A', 'A', m, n, 
                                     a, lda, s, u, ldu, vt, ldvt, superb);

    // Verificar si el calculo fue correcto
    if (info > 0) {
        std::cout << "Error en el calculo SVD." << std::endl;
        return 1;
    }

    // Resultados
    std::cout << "--- Resultados de la SVD ---" << std::endl;

    std::cout << "\nValores Singulares:" << std::endl;
    for(int i = 0; i < 2; i++) std::cout << s[i] << "  "; 
    std::cout << "\n(Deberían ser cercanos a 1.62 y 1.0)" << std::endl;

    std::cout << "\nMatriz U (2x2):" << std::endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) std::cout << u[i*2 + j] << "\t";
        std::cout << std::endl;
    }

    std::cout << "\nMatriz V^T (2x2):" << std::endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) std::cout << vt[i*2 + j] << "\t";
        std::cout << std::endl;
    }

    return 0;
}