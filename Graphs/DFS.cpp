//DFS - Depth First Search
#include<iostream>
using namespace std;

void print(int ** edges,int n,int sv, bool* visited)
{
    cout<<sv<<endl; //second vertex
    visited[sv]=true; //vertex is visited
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        continue;

        if(edges[sv][i]==1)
        {
            if(visited[i])
            continue;

            print(edges,n,i,visited);
        }

    }
}

int main()
{
    int n; //vertices
    int e; //edges
    cin>>n>>e;
    int ** edges=new int *[n]; 
    //Matrix intialized with 0
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0; //edge from i to j
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s; //first vertex and second vetex respectively
        cin>>f>>s; 
        //Replacing 0 with 1 for every new edge connected
        edges[f][s]=1; 
        edges[s][f]=1;

    }

    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    print(edges,n,0,visited);

    //delete all the memory
    delete []visited;
    for(int i=0;i<n;i++)
    {
        delete []edges[i];
    }
    delete [] edges;
}

/*
I/P:
4
3
0 2
2 1
1 3

O/P:
0
2
1
3
*/