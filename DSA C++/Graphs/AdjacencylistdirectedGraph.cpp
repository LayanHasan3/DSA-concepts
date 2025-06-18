#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    int n, m;
    cout << "enter no. of vertices: " << endl;
    cin >> n;
    cout << "enter no. of edges: " << endl;
    cin >> m;
    cout << "the number of vertices are: " << n << endl;
    cout << "the number of edges are: " << m << endl;

    vector<vector<int>> adj(n + 1); // 1-based indexing

    for (int i = 0; i < m; i++)
    {
        int u, v;
        // for directed graph u ---> v
        cout << "enter the edges: ";
        cin >> u >> v;
        adj[u].push_back(v); // store v in u's list
    }

    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= n; i++) // changed from 0 to 1
    {
        cout << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // BFS traversal
    vector<bool> visited(n + 1, false);
    int start;
    cout << "enter the starting vertex for bfs: " << endl;
    cin >> start;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;

    // DFS traversal
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    cout << "enter the starting vertex for dfs: " << endl;
    cin >> start;
    stack<int> s;
    s.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;

    return 0;
}
