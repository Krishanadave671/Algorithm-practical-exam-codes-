#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n){
     int i, j;
    for (i = 0; i < n-1; i++){
        int minidx = i;
        for( j = i + 1; j < n ; j++){
            if( arr[j] < arr[minidx]){      
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);
    }
}

void printarray(int *arr , int n){
     
     for(int i = 0 ; i < n ; i++){
         cout<<arr[i]<<" ";
     }
    
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    selectionSort(arr , n);
    printarray(arr , n);
    
   
    
}