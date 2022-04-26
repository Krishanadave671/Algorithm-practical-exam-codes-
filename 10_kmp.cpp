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
int main(){
    string txt , pattern;
    cout <<"Enter the text"<<endl;
    cin >> txt;
    cout <<"Enter the pattern "<<endl;
    cin >> pattern;
    cout <<"Enter a prime number"<<endl;
    cin >> primeno;



    return 0;

}