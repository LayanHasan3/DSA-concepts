#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cout<<"enter no. of vertices: "<<endl;
    cin>>n;
    cout<<"enter no.  of edges: "<<endl;
    cin>>m;
    cout<<"the number of vertices are: "<<n<<endl;
    cout<<"the number of edges are: "<<n<<endl;
    
   vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout<<"enter the edges: ";
        cin>>u>>v;
        adj[u].push_back(v);// on u index store v
        adj[v].push_back(u); // on v index store u
    }
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <=n; i++)
    {
        cout << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}