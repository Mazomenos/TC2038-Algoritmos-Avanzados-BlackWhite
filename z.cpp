

#include <iostream>
#include <string>

int matching(std::string T, std::string P){

    int N = T.length();
    int M = P.length();

    std::cout << T << " " << N << std::endl;
    std::cout << P  << " " << M << std::endl;


    for (int i = 0; i<N; i++){
        std::cout << T.substr(i,M) << std::endl;
        if (P == T.substr(i,M)){
            std::cout << "found ";
            return i+1;
        }
    }
    return -1;



}

int matchingZ(std::string T, std::string P){
    int N = T.length();
    int M = P.length();
    int arrZ[1+M+N];


    std::cout << T << " " << N << std::endl;
    std::cout << P  << " " << M << std::endl;

    for (int i = 1; i<M+N+1; i++){
        std::cout << T.substr(i,M) << std::endl;
        for (int j = 0; i<M; i++){


        }
    }
    return -1;

}

int main(){

    std::string T, P;

    std::cin >>T >>P;

    std::cout << T << " " << P << std::endl;

    int result = matching(T,P);



    std::cout << result;
    return 0;
}
