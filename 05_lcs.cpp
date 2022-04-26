#include<bits/stdc++.h>
using namespace std;
string LCS_Algo(string x, string y){
    string result;
    int m = x.length();
    int n = y.length();
    int dp[m + 1][n + 1];
    for(int i = 0; i<= m ; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;
    for(int i = 1 ; i <= m ;i++){
        for(int j = 1; j <= n; j++){
            if(x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else if(dp[i - 1][j] >= dp[i][j - 1]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i][j - 1];
        }
    }
    int i = m, j = n;
    while(i >= 0 && j >= 0){
        if(x[i - 1] == y[j - 1]) result.insert(result.begin(),x[i - 1]), i-- , j--;
        else if(dp[i - 1][j] > dp[j][i - 1]) i--;
        else j--;
    }
    return result;
}

int main(){
    string x, y;
    cout << "Enter the first string ";
    cin >> x;
    cout << "Enter the second string ";
    cin >> y;
    cout << " The resultant string is "<<LCS_Algo(x, y)<< "  and length is "<<LCS_Algo(x,y).length()<<endl;








    return 0;
}