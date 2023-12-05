#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

struct Trilha {
    int u, v, d;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        dist[u][v] = dist[v][u] = d;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    vector<int> lagos;
    for (int i = 1; i < n; i++) {
        lagos.push_back(i);
    }
    
    int min_distancia = INF;
    
    do {
        int distancia = 0;
        int lago_atual = 0;
        for (int i = 0; i < lagos.size(); i++) {
            int proximo_lago = lagos[i];
            distancia += dist[lago_atual][proximo_lago];
            lago_atual = proximo_lago;
        }
        
        min_distancia = min(min_distancia, distancia);
    } while (next_permutation(lagos.begin(), lagos.end()));
    
    if (min_distancia == INF) {
        cout << -1 << endl;
    } else {
        cout << min_distancia << endl;
    }
    
    return 0;
}
