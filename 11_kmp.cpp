#include <bits/stdc++.h>
using namespace std;
int primeno;

void ComputeLPSarray(string pattern , int m, int *lps){
    int k = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < m){
        if(pattern[i] == pattern[k]){
            k++;
            lps[i] = k;
            i++;
        }else{
            if(k != 0){
                k = lps[k - 1];
            }else{
                lps[i++] = 0;
            }
        }
    }
}


void KMPsearch(string pattern ,string txt){
    int m = pattern.length();
    int n = txt.length();
    int lps[m];
    ComputeLPSarray(pattern, m , lps);
    int i = 0, j = 0;
    while(i < n){
        if(pattern[j] == txt[i]){
            j++;
            i++;
        }
        if(j == m){
            cout << "Pattern found at index "<<(i - j);
            j = lps[j - 1];
        }
        else if(i < n and pattern[j] != txt[i]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }

}
int main(){
    string txt , pattern;
    cout <<"Enter the text"<<endl;
    getline(cin , txt);
    cout <<"Enter the pattern "<<endl;
    getline(cin , pattern);
    KMPsearch(pattern ,txt);


    return 0;

}