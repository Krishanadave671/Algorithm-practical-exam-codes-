/*
Algorithm 
Rabin_Karpmatcher(T, P,q, d)
n = t.length
m = p.length
h = dm-1 mod q
p = 0
t0 = 0
for i = 1 to m
    p = (dp + p[i]) mod q
    t0 = (dt0 + t[i]) mod q
for s = 0 to n - m
    if p = ts
        if p[1.....m] = t[s + 1..... s + m]
            print "pattern found at position" s
    If s < n-m
        ts + 1 = (d (ts - t[s + 1]h) + t[s + m + 1]) mod q
    if ts + 1 < 0 
        ts+1 += q
   Time Complexity = O(n - m + 1)
*/


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