#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_statues;
    int guard_dist;
    int statue;
    int guard_counter = 0;
    int guard_covered_range = 0;

    cin >> num_statues;
    cin >> guard_dist;

    vector <int> statues_placem;
    //Leitura das posições das estatuas
    for(int i = 0; i < num_statues; i++){
        cin >> statue;
        statues_placem.push_back(statue);
    }


     
    for(int i = 0; i != statues_placem.size(); i++){
        //Avalia se o local da estatua esta sendo coberto pelo alcance do ultimo guarda
        if(statues_placem[i] > guard_covered_range){
            //Insere o guarda na posicao otima (ponta do alcance cobre a estatua)
            guard_covered_range = statues_placem[i] + 2*guard_dist;
            guard_counter++;
        }

    }

    cout << guard_counter << "\n";


    return 0;
}