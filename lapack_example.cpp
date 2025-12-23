# include <iostream>
# include <lapacke.h>

int main(){
    double A [9] = {4 , 2 , 3 , 3 , 7 , 1 , 2 , 1 , 8}; // Matriz A (3x3)
    double b [3] = {10 , 19 , 17}; // Vector b
    int n = 3 , nrhs = 1 , lda = 3 , ldb = 3;
    int ipiv [3] , info ;

    // Resolver Ax = b
    info = LAPACKE_dgesv(LAPACK_ROW_MAJOR , n , nrhs , A , lda , ipiv , b , ldb);

    if(info==0){
        std :: cout << " Solucion : ";
        for(int i = 0; i < n ; ++ i ){
            std :: cout << b [ i ] << " ";
        }
        std :: cout << std::endl;
    }else {
        std :: cerr << " Error al resolver el sistema , codigo : "<< info << std::endl;
    }

    return 0;
}