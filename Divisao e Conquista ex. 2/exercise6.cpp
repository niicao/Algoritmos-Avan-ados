//Disciplina: Algoritmos Avançados - Exercicio 6
//Nicholas Yudi Kurita Ikai - 13671852
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

//Funcao que calcula o numero de explosivos minimos com um alcance rangeExplosiv
//os colocando em suas posições ótimas, retornando o booleano da comparação
bool check(int* array, int numStatues, int numExplosiv, int rangeExplosiv){
    int posReached = -1;
    int explosivCount = 0;
    for(int i = 0; i < numStatues; i++){
        if(posReached < array[i]){
            explosivCount++;
            posReached = array[i] + 2*rangeExplosiv;
        }
    }

    return (explosivCount <= numExplosiv);
}

int main(){
    int numStatues;
    int numExplosiv;
    int low = 0;
    int hi = 1e9;
    int mid;

    //Leitura dos dados
    cin >> numStatues;
    cin >> numExplosiv;

    int statuesPos[numStatues];

    for(int i = 0; i < numStatues; i++){
        cin >> statuesPos[i];
    }
    //Fim da leitura dos dados
    

    //Por meio da busca binaria, acharemos o alcance ótimo, tendo como
    //parametro, o número de explosivos dado na entrada
    while(low < hi){
        mid = (low + hi)/2;
        if(check(statuesPos, numStatues, numExplosiv, mid))
            hi = mid;
        else
            low = mid + 1;
    }


    cout << low << "\n";


    return 0;
}