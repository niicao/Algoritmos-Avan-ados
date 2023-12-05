//Disciplina: Algoritmos Avançados - Exercicio 11
//Nicholas Yudi Kurita Ikai - 13671852

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
    int weightKnapsack;
    int item_amm;
    long long int maxValueNonIncluding;
    long long int maxValueIncluding;
    int weightOfCurrItem;
    cin >> item_amm >> weightKnapsack;

    vector<vector<long long int>> matrix((item_amm + 1), vector<long long int>(weightKnapsack + 1));

    vector<long long int> values(item_amm + 1);
    vector<int> weights(weightKnapsack + 1);
    weights[0] = 0;
    values[0] = 0;



    for(int i = 0; i < item_amm + 1; i++){
        matrix[i][0] = 0;
    }

    for(int i = 0; i < weightKnapsack + 1; i++){
        matrix[0][i] = 0;
    }


    for(int i = 1; i < item_amm+1; i++){
        cin >> weights[i] >> values[i];
    }



    for(int item = 1; item < item_amm + 1; item++){
        for(int capacity = 1; capacity < weightKnapsack + 1; capacity++){
            maxValueNonIncluding = matrix[item-1][capacity];
            maxValueIncluding = 0;
            weightOfCurrItem = weights[item];
            if(capacity >= weightOfCurrItem){
                maxValueIncluding = values[item];

                int remainingCapac = capacity - weightOfCurrItem;
                maxValueIncluding += matrix[item-1][remainingCapac];
            }

            matrix[item][capacity] = max(maxValueIncluding, maxValueNonIncluding);

        }
    }

    cout << matrix[item_amm][weightKnapsack];


    return 0;

}