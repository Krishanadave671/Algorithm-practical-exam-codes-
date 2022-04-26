#include <bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
    int objno;
};
void printTable(struct Item arr[], int n){
    cout <<"\n\nThe given data is as follows"<<endl;
    cout <<"\nObjNo.   Weight    value "<<endl;
    for(int i = 0 ; i < n; i++){
        cout <<" "<<arr[i].objno <<"\t  "<<arr[i].weight <<"\t    "<<arr[i].value<<endl;
    }
}
bool comparator(struct Item a, struct Item b){
    double r1 = ((double)a.value)/a.weight;
    double r2 = ((double)b.value)/b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n){
    // sorting ;
    sort(arr , arr + n , comparator);
    cout <<"\nThe data after sorting according to value /weight "<<endl;
    printTable(arr, n);
    double finalvalue = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }else{
            finalvalue += arr[i].value*(((double)W)/arr[i].weight);
            break;
        }
    }

    return finalvalue;

}


int main(){
    int W , n;
    cout <<"Enter total weight "<<endl;
    cin >> W;
    cout <<"Enter the number of objects"<<endl;
    cin >> n;
    Item arr[n];
    cout <<"Enter the weight and value of objects :- "<<endl;
    for(int i = 0 ; i < n; i++){
        cout <<"Enter the weight and value of object "<<(i + 1)<<": ";
        cin >> arr[i].weight>>arr[i].value;
        arr[i].objno = i + 1;
    }
    printTable(arr, n);
   int result =fractionalKnapsack(W, arr,n);
   cout <<"The maximum profit is "<<result <<endl;



    return 0;
}