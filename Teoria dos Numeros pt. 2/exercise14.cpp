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