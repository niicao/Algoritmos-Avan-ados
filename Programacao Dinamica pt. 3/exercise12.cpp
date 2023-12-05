#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Trilha {
    int u, v, d;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Trilha> trilhas(m);
    
    for (int i = 0; i < m; i++) {
        cin >> trilhas[i].u >> trilhas[i].v >> trilhas[i].d;
    }
    
    vector<int> lagos;
    for (int i = 2; i <= n; i++) {
        lagos.push_back(i);
    }
    
    int min_distancia = -1;
    
    do {
        int distancia = 0;
        int lago_atual = 1;
        for (int i = 0; i < lagos.size(); i++) {
            int proximo_lago = lagos[i];
            
            auto it = find_if(trilhas.begin(), trilhas.end(), [lago_atual, proximo_lago](const Trilha& t) {
                return (t.u == lago_atual && t.v == proximo_lago) || (t.u == proximo_lago && t.v == lago_atual);
            });
            
            if (it != trilhas.end()) {
                distancia += it->d;
                lago_atual = proximo_lago;
            } else {
                distancia = -1;
                break;
            }
        }
        
        if (distancia != -1) {
            if (min_distancia == -1 || distancia < min_distancia) {
                min_distancia = distancia;
            }
        }
    } while (next_permutation(lagos.begin(), lagos.end()));
    
    cout << min_distancia << endl;
    
    return 0;
}
