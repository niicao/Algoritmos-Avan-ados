#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>



using namespace std;

class UnionFind{
    private:
        typedef vector<long long int> vectorLongInt;
        vectorLongInt parents;
        vectorLongInt rank;
        long long int size;

public:
    //Constructor
    UnionFind(long long int n){
        for(int i = 0; i < n; i++){
            this->parents.push_back(i);
            this->rank.push_back(1);
        }
        this->size = n;
    }

    //Acha o pai de um Union recursivamente
    int find(long long int i){
        if(parents[i] == i)
            return i;

        return parents[i] = find(parents[i]);
    }

    //Verifica se estao no mesmo conjunto
    bool isSameSet(long long int i, long long int j){
        return (find(i) == find(j));
    }

    //Une dois conjuntos, priorizando a arvore resultante mais baixa
    void unite(long long int i, long long int j){
        int temp1 = find(i);
        int temp2 = find(j);

        if(temp1 != temp2){
            if(rank[temp1] < rank[temp2]){
                parents[temp1] = temp2;
            }
            else if(rank[temp1] > rank[temp2]){
                parents[temp2] = temp1;
            }
            else{
                parents[temp2] = temp1;
                rank[temp1] += 1;
            }
        }
    }

};

class Graph{
    vector<vector<long long int>> adjList;
    long long int numVertices;

public:
    Graph(long long int numV){
        this->numVertices = numV;
    }

    void addEdge(long long int edge1, long long int edge2, long long int cost){
        adjList.push_back({edge1, edge2, cost});
    }

    //Algoritmo de Kruskals
    void kruskals(){
        set<int> visited;
        //Ordena a lista de adjacencia a partir do custo, usando uma funcao lambda 
        sort(adjList.begin(), adjList.end(), [](const vector<long long int>& a, const vector<long long int>& b){
            return a[2] < b[2];
        });
        UnionFind unionVar(numVertices);

        long long int minCost = 0;


        for(auto edge:adjList){
            long long int edge1 = edge[0];
            long long int edge2 = edge[1];
            long long int cost = edge[2];
            //Verifica se estao conectados, se nao, os une e adiciona o custo na MST
            if(unionVar.find(edge1) != unionVar.find(edge2)){
                unionVar.unite(edge1, edge2);
                minCost += cost;
            }

                    
            

        }
        //Verifica todos os vertices, se todos estao conectados
        for(int i = 0; i < numVertices; i++){
            visited.insert(unionVar.find(i));
        }
        //Se todos tiverem conectados ao nó raiz (gerador) imprime o custo
        if(visited.size() == 1){
            cout << minCost;
        }
        else{
            cout << -1;
        }

    }
};

int main(){
    long long int vertices;
    long long int edges;

    long long int edgeInput, edgeInput2, costInput;
    cin >> vertices;
    cin >> edges;

    Graph graph(vertices);

    for(int i = 0; i < edges; i++){
        cin >> edgeInput;
        cin >> edgeInput2;
        cin >> costInput;

        graph.addEdge(edgeInput, edgeInput2, costInput);
    }

    graph.kruskals();

    return 0;
}