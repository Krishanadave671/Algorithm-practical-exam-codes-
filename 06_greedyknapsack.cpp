#include <bits/stdc++.h>
using namespace std;
struct Item{
  int objectid;
  int weight;
  int value;
};

bool comparator(struct Item a , struct Item b){
   double r1 = a.value/a.weight;
   double r2 = b.value/b.weight;
   return r1 > r2; 

}

void printTable(struct Item arr[], int n){
  cout <<"\n object no     value     weight  "<<endl;
  for(int i = 0; i < n;i++){
     cout <<"\t "<<arr[i].objectid<<"\t   "<<arr[i].value<<"\t "<<arr[i].weight<<endl;
  }
}
double fractionalknapsack(struct Item arr[], int W , int n){
      sort(arr,arr + n , comparator);
      double finalprofit = 0;

      for(int i = 0; i < n; i++){
        if(arr[i].weight <= W){
           finalprofit += arr[i].value;
           W -= arr[i].weight;
        }else{
          finalprofit += arr[i].value*(((double)W)/arr[i].weight);
          break;
        }
      }

    return finalprofit;

}


int main(){
  int n,W;
  cout <<"Enter the knapsack weight"<<endl;
  cin >>W;
  cout << "Enter the no of objects"<<endl;
  cin >> n;

  Item arr[n];
  cout <<"Enter the data items"<<endl;
  for(int i = 0; i < n ; i++){
      cout <<"Enter the profit and weight of object no"<<(i + 1)<<" ";
      cin >> arr[i].value>>arr[i].weight;
      arr[i].objectid = i + 1;
  }

    double result = fractionalknapsack(arr, W, n);
    cout <<"The total profit is "<<result;
  
   

  return 0;
}