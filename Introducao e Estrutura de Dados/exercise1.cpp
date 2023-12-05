//Disciplina: Algoritmos Avançados - Exercicio 1
//Nicholas Yudi Kurita Ikai - 13671852

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>

using namespace std;



int main(){
    int num_subjects;
    cin >> num_subjects;

    map<std::string, int> studentsDB;

    int counter = 0;
    int num_students;

    while(num_subjects>counter){
        cin>>num_students;

        for(int i = 0; i < num_students; i++){//Cadastro dos estudantes na disciplina dada por counter

            string student_ID;
            cin>>student_ID;

            //Cadastro ja existente   
            if(studentsDB.find(student_ID) != studentsDB.end()){
            
                //Verifica se o cadastro feito é de outra disciplina
                if(studentsDB[student_ID] != counter){
                    //Invalida o cadastro do aluno (coloca em uma disciplina -1)
                    studentsDB[student_ID] = -1;
                }

            //Realiza o cadastro
            }else{
                studentsDB.insert({student_ID, counter});
            }

        }
        counter++;
    }

    //Mapa de contagem de alunos/disc
    unordered_map<int, unsigned int> countingMap;//<disciplina, numero alunos>
    for(int i = num_subjects-1; i > -1; i--){
        countingMap.insert({i, 0});
    }

    for(const auto& occurences : studentsDB){
        countingMap[occurences.second]++;
    }

    for(int i = 0; i < num_subjects; i++) {
       
        std::cout << countingMap[i] <<" ";
    }
    cout<<"\n";
}