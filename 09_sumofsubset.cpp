#include<bits/stdc++.h>
using namespace std;
int w[10] ;
int m , n;
int x[10] ={0};
int cnt = 0 , noofsoln = 0;
void display(int x[], int k){
    noofsoln += 1;
    cout <<"\n\n Solution : {"<<noofsoln;
    for(int i = 0 ; i <= k ; i++){
        cout <<" "<<x[i]<<" ";
    }
    



}
void sumofsubset(int s , int r, int k){
    cnt += 1;
    x[k] = 1;
    if(s + w[k] == m) display(x, k);
    else if( s + w[k] + w[k + 1] <= m) 
     sumofsubset(s + w[k], r - w[k], k + 1);

     if((s + r - w[k] >= m) and (s + w[k + 1] <= m)){
         x[k] = 0;
         sumofsubset(s, r - w[k], k + 1);
     }
}
int main(){

    cout <<"Enter total sum required : ";
    cin >>m;
    cout <<"Enter number of elements in subset : ";
    cin >> n;
    int r= 0;
    for(int i = 0; i < n; i++){
        cout <<"Enter element "<<(i + 1);
        cin >> w[i];
        r+= w[i];
    }

    sumofsubset(0 , r, 0);
    cout <<"\n No of nodes (call to sum subset procedure )"<<cnt;
}