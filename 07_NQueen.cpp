/*





*/


#include <bits/stdc++.h>
using namespace std;

bool issafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        // checking for column
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    // checking for left upper diagonal
    int row = x, col = y;
    while (row >= 0 and col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    // checking for right upper diagonal
    row = x, col = y;
    while (row >= 0 and col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (issafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }
            // backtracking
            arr[x][col] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    cout << "Q"
                         << " ";
                }else{
                     cout << arr[i][j] << " ";
                }
               
            }
            cout << endl;
        }
    }

    return 0;
}