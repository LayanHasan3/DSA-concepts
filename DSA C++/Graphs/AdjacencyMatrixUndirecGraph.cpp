#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"enter no. of vertex and edges for directed graph: ";
    cin>>n>>m;
    const int MAX=100;
    int adj[MAX][MAX]={0};
    for(int i=1;i<=m;i++){
        int u,v;
        cout<<"enter edge: ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=0;
    }
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}