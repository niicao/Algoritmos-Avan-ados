    //Disciplina: Algoritmos Avançados - Exercicio 7
    //Nicholas Yudi Kurita Ikai - 13671852
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

        UnionFind(long long int n){
            for(int i = 0; i < n; i++){
                this->parents.push_back(i);
                this->rank.push_back(1);
            }
            this->size = n;
        }

        int find(long long int i){
            if(parents[i] == i)
                return i;

            return parents[i] = find(parents[i]);
        }

        bool isSameSet(long long int i, long long int j){
            return (find(i) == find(j));
        }

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

        void kruskals(){
            set<int> visited;
            sort(adjList.begin(), adjList.end(), [](const vector<long long int>& a, const vector<long long int>& b){
                return a[2] < b[2];
            });
            UnionFind unionVar(numVertices);

            long long int minCost = 0;

            for(auto edge:adjList){
                long long int edge1 = edge[0];
                long long int edge2 = edge[1];
                long long int cost = edge[2];

                if(unionVar.find(edge1) != unionVar.find(edge2)){
                    if(edge1 == 5 && edge2 == 1){
                        cout << "Diagnosis: " << unionVar.find(edge1) << " " << unionVar.find(edge2) << endl;
                    }
                    unionVar.unite(edge1, edge2);
                    minCost += cost;
                    cout << edge1 << " -- " << edge2 << " == " << cost << endl;
                }

                for(auto edge:adjList){
                    if(unionVar.find(edge[0]) != edge[0]){
                        visited.insert(edge[0]);
                        visited.insert(unionVar.find(edge[0]));
                    }
                        
                }

            }

            if(visited.size() == numVertices){
                cout << minCost;
            }
            else{
                cout << -1;
            }

        }
    };
