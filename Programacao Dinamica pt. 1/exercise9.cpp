#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
    int length = 0;
    cin >> length;
    long long int temp = 0;
    long long int temp2 = 0;
    vector<long long int> tracklist(length + 1);
    vector<long long int> difficultyLevel(length);



    for(int i = 0; i <= length; i++){
        cin >> difficultyLevel[i];
    }
    tracklist[0] = 0;
    tracklist[1] = abs(difficultyLevel[0] - difficultyLevel[1]);

    for(int i = 2; i <= length; i++){
        temp = tracklist[i-2] +  abs(difficultyLevel[i-2] - difficultyLevel[i]);
        temp2 = tracklist[i-1] + abs(difficultyLevel[i-1] - difficultyLevel[i]);
        tracklist[i] = min(temp, temp2);
    }

    cout << tracklist[length-1];



    return 0;
}

