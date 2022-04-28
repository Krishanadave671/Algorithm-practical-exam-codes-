#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<pair<int , int >, vector<pair<int , int >>, greater<pair <int , int>>> minheap;

int main(){
    int n, s;
    cout << "Enter no of vertices in the following graph "<<endl;
    cin >> n;
    int G[n][n];
    cout << "Enter the graph in matrix form "<<endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            cin >> G[i][j];
        }
    }
     
    int parent[n],key[n];
    bool MSTset[n];
    cout << "Enter the source vertex "<<endl;
    cin >> s;
    for(int i = 0 ; i < n ;i++) key[i] = INT_MAX , MSTset[i] = false;
    key[s] = 0;
    parent[s] = -1;
    minheap pq;
     pq.push({0, s});
     
     while (!pq.empty())
     {
         int u = pq.top().second;
         pq.pop();
         MSTset[u] = true;
         for(int i = 0; i < n; i++){
             if(G[u][i] != 0){
                 int v = i;
                 int weight = G[u][i];
                 if(MSTset[v] == false and weight < key[v]){
                     parent[v] = u;
                     key[v] = weight;
                     pq.push({key[v], v});
                 }
             }
         }

     }
     int cost = 0;

     for(int i = 0; i < n ; i++){
         if (i == s) continue;
         cout << parent[i]<<"-"<<i <<"\n ";
         cost += key[i];
     }
     cout <<"The cost of given graph is "<< cost <<endl;
    return 0;
}