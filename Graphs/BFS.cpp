//BFS - Breadth First Search
#include<iostream>
using namespace std;
#include<queue>

void printBFS(int ** edges,int n,int sv)
{
    queue<int>pendingVertices;
    bool * visited=new bool[n];

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty())
    {
        int currVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currVertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==currVertex)
            continue;

            if(edges[currVertex][i]==1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
delete []visited;
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

    printBFS(edges,n,0);

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
7
8
0 1
0 2
1 3
1 4
3 5
4 5
2 6
5 6

O/P:
0
1
2
3
4
6
5
*/