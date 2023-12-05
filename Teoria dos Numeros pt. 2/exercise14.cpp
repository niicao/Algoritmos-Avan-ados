#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stdlib.h>
using namespace std;


typedef vector<int> vi;
typedef vector<long long> vll;
long long tamCrivo;  


bitset<10000010> crivo; // vamos fazer um crivo até 10^7 
vll primos;

// void crivoErastotenes(long long M){
// 	tamCrivo = M+1; // para acrescentar o proprio M
// 	crivo.set();      // todo mundo é primo

// 	crivo[0] = crivo[1] = 0;  // 0 e 1 nao sao primos..

// 	for (long long i = 2; i <= tamCrivo; ++i){
// 		if (crivo[i]){           // se i for primo, descarta todos os seus multiplos
// 			for (long long j = i*i; j <= tamCrivo; j += i)
// 				crivo[j]=0;
// 			primos.push_back(i);  // guarda i no vetor de primos
// 		}
// 	}
// }


// bool primo(long long n){
// 	if (n <= tamCrivo)
// 		return crivo[n];   // retorna se eh ou nao primo em O(1)

// 	for (long long i = 0; i*i <= primos.size() ; i++){
// 		if (n%primos[i] == 0)
// 			return false;
// 	}
// 	return true;
// }

// bool has3Divs(long long int num){
//     long long int check;
//     check = sqrt(num);
//     // cout << check << "!!!!!!" << endl;
//     if(crivo[sqrt(num)] == 1 && (check * check == num)){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

int main(int argc, char const *argv[]){
	
	// crivoErastotenes(10000000);
    long long int inputNum;
    cin >> inputNum;
    long long int n;
    long long int divisor;
    long long int counter = 0;
    lldiv_t divRes;

    for(int i = 0; i < inputNum; i++){
        cin >> n >> divisor;

        counter = 0;
        
        while(n >= divisor || counter == 0){
            divRes = div(n, divisor);

            if(divRes.quot == 0){ //break, resultado será o resto da divisao
                break;
            }
            
            n = divRes.quot; 
            counter+= (divRes.rem + 1); //contador = 1 (divisao) + remainder
        }

        counter+= n;

        cout << counter << endl;
    }

    
	
	return 0;
}