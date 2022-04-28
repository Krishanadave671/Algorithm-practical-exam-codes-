#include <bits/stdc++.h>
using namespace std;
int k[10][10];
int wt[10], p[10];
void knapsack(int m , int n){
    int k[n + 1][m + 1];
    for(int i = 0; i <= n ; i++){
        for(int w = 0; w <= m ; w++ ){
            if( i == 0 || w == 0) k[i][w] = 0;
            else if (wt[i] <= w){
                k[i][w] = max(p[i] + k[i -1][w - wt[i]] , k[i -1][w]);
            }
            else k[i][w] = k[i - 1][w];
        }
    }
    cout <<"\nThe maximum profit is  "<<k[n][m]<<endl;
    int i = n , j = m;
    cout << "\nelements position that  are added : ";
    while (i > 0 and j > 0){
        if(k[i][j] != k[i - 1][j]){
            cout <<(i + 1)<<" ";
            j -=  wt[i];
            i--;
            
        }else {
            i--;
        }
    }
    
}
int main(){
    int m, n;
    cout <<"Enter total weight of object"<<endl;
    cin >> m;
    cout <<"Enter total number of objects "<<endl;
    cin >> n;
    cout <<"Enter the weight and value of object  below "<<endl;
    for(int i = 0 ; i < n ; i++){
        cout <<"Enter the weight of object and value for object"<<(i + 1)<<" ";
        cin>>wt[i]>>p[i];
    }
    knapsack(m , n);

    return 0;
}