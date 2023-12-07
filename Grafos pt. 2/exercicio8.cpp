#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

class Graph {
  int V;
  list<int> *adj;
  vector<int> indexes;
  void fillOrder(int s, bool visitedV[], stack<int> &Stack);


   public:
  Graph(int V);
  void addEdge(int s, int d);
  void printSCC(vector<int> SCCs, int *counter);
  Graph transpose();
  void printIndexes();
  void assignIndex(int index, int value);
  vector<int> DFS(int s, bool visitedV[], vector<int> SCCs, int* counter);

};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
  this->indexes.assign(V, -1);
}

void Graph::assignIndex(int value, int index){
    this->indexes[index] = value;
}

// DFS
vector<int> Graph::DFS(int s, bool visitedV[], vector<int> SCCs, int* counter) {
  visitedV[s] = true;
  SCCs.push_back(s);
  list<int>::iterator i;
  for (i = adj[s].begin(); i != adj[s].end(); ++i)
    if (!visitedV[*i])
      DFS(*i, visitedV, SCCs, counter);
    else{
        for(int i = 0; i < SCCs.size(); i++){
            if(indexes[SCCs[i]] < 0)
                this->assignIndex(*counter, SCCs[i]);

        }
        
    }
    sort(SCCs.begin(), SCCs.end(), [](const int &a, const int &b){
        return a < b;
    });
    return this->indexes;
}

// Transpose
Graph Graph::transpose() {
  Graph g(V);
  for (int s = 0; s < V; s++) {
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      g.adj[*i].push_back(s);
    }
  }
  return g;
}

// Add edge into the graph
void Graph::addEdge(int s, int d) {
  adj[s-1].push_back(d-1);
}

void Graph::fillOrder(int s, bool visitedV[], stack<int> &Stack) {
  visitedV[s] = true;

  list<int>::iterator i;
  for (i = adj[s].begin(); i != adj[s].end(); ++i)
    if (!visitedV[*i])
      fillOrder(*i, visitedV, Stack);

  Stack.push(s);
}

// Print strongly connected component
void Graph::printSCC(vector<int> SCCs, int* counter) {
  stack<int> Stack;

  bool *visitedV = new bool[V];
  for (int i = 0; i < V; i++)
    visitedV[i] = false;

  for (int i = 0; i < V; i++)
    if (visitedV[i] == false)
      fillOrder(i, visitedV, Stack);

  Graph gr = transpose();

  for (int i = 0; i < V; i++)
    visitedV[i] = false;

  while (Stack.empty() == false) {
    int s = Stack.top();
    Stack.pop();

    if (visitedV[s] == false) {
      SCCs.clear();
      this->indexes = gr.DFS(s, visitedV, SCCs, counter);
      
    *counter += 1;
    }
  }
}

void Graph::printIndexes(){
    vector<int> index_updated;
    int value;
    int counter = 1;
    index_updated.assign(this->indexes.size(), -1);

    for(int i = 0; i < this->indexes.size(); i++){
      if(this->indexes[i] == -1){
        index_updated[i] = counter;
        counter++;
        continue;
      }
      else if(this->indexes[i] != -2){
          value = this->indexes[i];
        for(int j = i; j < this->indexes.size(); j++){
          if(this->indexes[j] == value){
          index_updated[j] = counter;
          this->indexes[j] = -2;
          }
        }
        counter++;
      }
    }

    for(int i = 0; i < index_updated.size(); i++){
      cout << index_updated[i] << " ";
    } 
}

int main() {
  int numStdnts;
  int numRelations;
  int originVertex;
  int endVertex;
  int counter = 1;

  cin >> numStdnts >> numRelations;
  Graph panelinhas = Graph(numStdnts);
  vector<int> SCCs;

  for(int i = 0; i < numRelations; i++){
    cin >> originVertex >> endVertex;
    panelinhas.addEdge(originVertex, endVertex);
  }


  panelinhas.printSCC( SCCs, &counter);

  
  cout << counter-1 << endl;
  panelinhas.printIndexes();
  

  return 0;
}