#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n){
    int i, j ;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1 ; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }

        }
    }
}
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
void insertionSort(int *arr  , int n){
    int i , key , j ;
    for(i = 1 ; i < n   ; i ++){
        key = arr[i];
        j = i - 1 ;
        while( j >= 0  and arr[j] > key ){
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = key ;
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