// //Disciplina: Algoritmos Avançados - Exercicio 9
// //Nicholas Yudi Kurita Ikai - 13671852

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, K;
    cin >> n >> K;

    vector<vector<int>> aij(n + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> aij[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            int max_value = 0;
            for (int prev_j = 1; prev_j <= K; prev_j++) {
                if (prev_j != j) {
                    max_value = max(max_value, dp[i - 1][prev_j]);
                }
            }
            dp[i][j] = max_value + aij[i][j];
        }
    }

    int resultado = 0;
    for (int j = 1; j <= K; j++) {
        resultado = max(resultado, dp[n][j]);
    }

    cout << resultado << endl;

    return 0;
}
