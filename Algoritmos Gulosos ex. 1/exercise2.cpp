

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool sortPair(const pair <int, int>& a, const pair <int, int>& b){
    if(a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second < b.second);
}

int main(){
    int num_lectures;
    cin >> num_lectures;
    int start;
    int end;
    int lecture_counts = 1;
    vector <pair<int, int>> lectures;

    //Cria um vetor de pares sendo {inicio, fim} das palestras
    for(int i = 0; i < num_lectures; i++){
        cin >> start;
        cin >> end;

        lectures.emplace_back(start, end);
    }

    //Ordena o vetor pelo inicio, com o fim sendo o critério de desempate em ordem crescente
    sort(lectures.begin(), lectures.end(), sortPair);

    start = lectures[0].first;
    end = lectures[0].second;

    for(int i = 1; i < num_lectures; i++){
        //Caso de uma palestra de duração menor que termine antes (better fit case)
        if(lectures[i].first > start && lectures[i].second < end){
            start = lectures[i].first;
            end = lectures[i].second;
        }
        //Procura a proxima palestra a ser agendada
        if(lectures[i].first >= end){
            start = lectures[i].first;
            end = lectures[i].second;
            lecture_counts++;
        } 
    }

    cout<< lecture_counts << "\n";
    
    return 0;

}
