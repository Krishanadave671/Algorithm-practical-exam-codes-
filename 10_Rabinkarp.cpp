#include <bits/stdc++.h>
using namespace std;
int primeno;

void Search(string pattern , string txt){
    int m = pattern.length();
    int n = txt.length();
    int i, j ;
    int d = 256;
    int h = 1;
    int p = 0 , t = 0;
      for (i = 0; i < m - 1; i++)
        h = (h * d) % primeno;

     for(i = 0 ; i < m; i++){
         t = (d * t + pattern[i])%primeno;
         p = (d * p + txt[i] )%primeno;
     }

     for(i = 0; i < n - m ; i++){
        
         if(p == t){
             for(j = 0 ; j < m; j++){
             if(txt[i + j]!= pattern[j]){
                 break;
             } 
         }
         if(j == m) cout <<"Pattern found at index "<<i<<endl;
         }

         if(i < n - m){
             t = (d*(t - txt[i]*h) + txt[i + m]) %primeno;
             if(t < 0) t = t + primeno;
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
    Search(pattern , txt);


    return 0;
}