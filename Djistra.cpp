#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX

using namespace std;

void met(vector<vector<int>> &graph, int source, int destination) // Corrected template argument list
{
    int V = graph.size();
    if (source >= V || destination >= V)
    {
        cout << "Not possible";
        return;
    }
    vector<int> dist(V, INT_MAX);
    vector<bool> splset(V, false);
    vector<int> pred(V, -1);
    dist[source] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = min_element(dist.begin(), dist.end()) - dist.begin();
        splset[u] = true;
        for (int v = 0; v < V; ++v)
        {
            if (!splset[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }

    if (dist[destination] == INT_MAX)
    {
        cout << "No path exists";
        return;
    }

    cout << "Shortest distance: " << dist[destination] << endl;
    cout << "Shortest path: ";
    vector<int> path;
    for (int i = destination; i != -1; i = pred[i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    for (int i : path)
        cout << i << "->";
}

int main()
{
    int n, x, y;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout<<"Enter the cost matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout<<"Enter the source and destination node: ";
    cin >> x >> y;
    met(graph, x, y);
    return 0;
}
