/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

//Brute Force
int minCostPath(int **input,int m,int n,int i,int j)
{
    //base cases
    if(i==m-1 && j==n-1)
    return input[i][j];

    if(i>=m || j>=n)
    return INT_MAX;

    //recursive calls
    int x=minCostPath(input,m,n,i,j+1);
    int y=minCostPath(input,m,n,i+1,j+1);
    int z=minCostPath(input,m,n,i+1,j);

    //small calculation
    int ans=min(x,min(y,z))+input[i][j];
    return ans;
}

int minCostPath(int **input,int m,int n)
{
    return minCostPath(input,m,n,0,0);
}

//Using Memoization
int minCostPath2(int **input,int m,int n,int i,int j,int **output)
{
    //base cases
    if(i==m-1 && j==n-1)
    return input[i][j];

    if(i>=m || j>=n)
    return INT_MAX;

    //check if ans already exists
    if(output[i][j]!=-1)
    return output[i][j];

    //recursive calls
    int x=minCostPath(input,m,n,i,j+1);
    int y=minCostPath(input,m,n,i+1,j+1);
    int z=minCostPath(input,m,n,i+1,j);

    //small calculation
    int a=min(x,min(y,z))+input[i][j];

    //save ans for future use
    output[i][j]=a;
    
    return a;
}

int minCostPath2(int **input,int m,int n)
{
    int **output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            output[i][j]=-1;
        }
    }   
    return minCostPath2(input,m,n,0,0,output);
}

//Using DP: O(m*n) : T.C. & S.C.

int minCostPath3(int **input,int m,int n)
{
    int **output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
    }
    
    //fill last cell i.e., destination
    output[m-1][n-1]=input[m-1][n-1];

    //fill last row(right to left)
    for(int j=n-2;j>=0;j--)
    {
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }

    //fill last column(bottom to top)
    for(int i=m-2;i>=0;i--)
    {
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }

    //fill remaining cells
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
        }
    }

    return output[0][0];
}

int main()
{
    int m,n;
    cin>>m>>n;
    int **input=new int*[m];
    for(int i=0;i<m;i++)
    {
        input[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }
    }   
    // cout<<minCostPath(input,m,n)<<endl; //brute force
    // cout<<minCostPath2(input,m,n)<<endl; //memoisation
    cout<<minCostPath3(input,m,n)<<endl; //DP
}

/*
I/P:
3 3
8 10 3
2 0 4
1 6 5

O/P:
13
*/