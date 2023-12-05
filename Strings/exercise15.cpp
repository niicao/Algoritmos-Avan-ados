#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void computeLPSArray(string pat, int M, vector<int> &lps) 
{ 
    int len = 0; 
  
    lps[0] = 0; 
  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
  
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}


int main(){
    vector<string> list;
    int ammountInputs;
    int option;
    string word;
    cin >> ammountInputs;
    int patLen;
    int txtLen;
    int ocurrences;


    for(int i = 0; i < ammountInputs; i++){
        cin >> option >> word;
        vector<int> lps(word.size());

        switch (option)
        {
        case 1:
            list.push_back(word);
            break;
        case 2:
            list.erase(remove(list.begin(), list.end(), word), list.end());
            break;
        case 3:
            
            patLen = word.size();
            computeLPSArray(word, word.size(), lps);
            ocurrences = 0;
            for(int i = 0; i < list.size(); i++){
                if(list[i].size() < word.size()){
                    continue;
                }
                txtLen = list[i].size();

                int patIndex = 0;
                int txtIndex = 0;

                while(txtLen - txtIndex >= patLen - patIndex){
                    if(list[i][txtIndex] == word[patIndex]){
                        txtIndex++;
                        patIndex++;
                    }
                    if(patIndex == patLen){
                        ocurrences++;
                        break;
                    }
                    else if(txtIndex < txtLen && list[i][txtIndex] != word[patIndex]){
                        // if(patIndex != 0){
                        //     patIndex = lps[patIndex - 1];
                        // }
                        // else{
                        //     txtIndex++;
                        // }
                        break;
                    }
                }
            }
            cout << ocurrences << endl;
            break;
        
        case 4:
            sort(list.begin(), list.end());
            for(int i = 0; i < list.size(); i++){
                cout << list[i] << endl;
            }
            break;
        default:
            break;
        }

    }
    
    

    
    return 0;
}