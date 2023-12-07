#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>


using namespace std;

void sumOfSubsets(int array[], int start, int end, set<int, greater<int>> &pollenSet, int sum = 0){
    if(start > end){
        if(sum != 0)
            //Insere a soma em um set, para evitar repetições
            pollenSet.insert(sum);
        return;
    }

    //Dado um subconjunto e um elemento fora dele, existem sempre dois conjuntos possiveis
    //um com o elemento (sum + array[st]) e um sem ele (sum)
    sumOfSubsets(array, start + 1, end, pollenSet, sum + array[start]);
    sumOfSubsets(array, start + 1, end, pollenSet, sum);
}

int main(){
    int totalBees;
    cin >> totalBees;
    set <int, greater<int>> pollenSet;
    int pollenArray[totalBees];
    int counter = 0;
    for(int i = 0; i < totalBees; i++){
        cin >> pollenArray[i];
    }

    sumOfSubsets(pollenArray, 0, (sizeof(pollenArray)/sizeof(int)) - 1,pollenSet);
    
    cout << pollenSet.size() << "\n";
    return 0;

}