#include<stdio.h>
#include<string.h>
int b[100][100];

void print_lcs(int b[100][100],char x[],int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==3)
	{
		print_lcs(b,x,i-1,j-1);
		printf("%c ",x[i-1]);
	}
	else if(b[i][j]==1)
	{
		print_lcs(b,x,i-1,j);
	}
	else
	{
		print_lcs(b,x,i,j-1);
	}
}

void lcs(char x[],char y[])
{
	int m,n,i,j;
	m=strlen(x);
	n=strlen(y);
	//int b[m+1][n+1],
	int c[m+1][n+1];
	for(i=0;i<m+1;i++)
		c[i][0]=0;
	for(i=1;i<n+1;i++)
		c[0][i]=0;
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=3;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=2;
			}
		}
	}
	printf("\nTotal length of characters: %d\n",c[m][n]);
	printf("%s\n",x);
	print_lcs(b,x,m,n);
	printf("\n");
}

void main()
{
	char x[100],y[100];
	printf("Enter first string: ");
	gets(x);
	printf("Enter second string: ");
	gets(y);
	lcs(x,y);
}



// #include <stdio.h>
// #include <string.h>

// int i, j, m, n, LCS_table[20][20];
// char S1[20] = "ACADB", S2[20] = "CBDA", b[20][20];

// void lcsAlgo() {
//   m = strlen(S1);
//   n = strlen(S2);

//   // Filling 0's in the matrix
//   for (i = 0; i <= m; i++)
//     LCS_table[i][0] = 0;
//   for (i = 0; i <= n; i++)
//     LCS_table[0][i] = 0;

//   // Building the mtrix in bottom-up way
//   for (i = 1; i <= m; i++)
//     for (j = 1; j <= n; j++) {
//       if (S1[i - 1] == S2[j - 1]) {
//         LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
//       } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
//         LCS_table[i][j] = LCS_table[i - 1][j];
//       } else {
//         LCS_table[i][j] = LCS_table[i][j - 1];
//       }
//     }

//   int index = LCS_table[m][n];
//   char lcsAlgo[index + 1];
//   lcsAlgo[index] = '\0';

//   int i = m, j = n;
//   while (i > 0 && j > 0) {
//     if (S1[i - 1] == S2[j - 1]) {
//       lcsAlgo[index - 1] = S1[i - 1];
//       i--;
//       j--;
//       index--;
//     }

//     else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
//       i--;
//     else
//       j--;
//   }

//   // Printing the sub sequences
//   printf("S1 : %s \nS2 : %s \n", S1, S2);
//   printf("LCS: %s", lcsAlgo);
// }

// int main() {
//   lcsAlgo();
//   printf("\n");
// }
