#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int num_testcases;
    cin >> num_testcases;
    int num_piles;
    for(int i = 0; i < num_testcases; i++){
        cin >> num_piles;
        int nim_sum = 0;
        for(int j = 0; j < num_piles; j++){
            int pile_size;
            cin >> pile_size;
            nim_sum ^= pile_size;
        }
        if(nim_sum == 0){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}