#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX

using namespace std;

void dijkstra(vector<vector<int>> &graph, int source)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[source] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        int u = -1;
        for (int j = 0; j < V; ++j)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] && dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; ++i)
    {
        if ((i == source) || (dist[i] == INT_MAX))
            continue;
        else
            cout << source << "->" << i << " : " << dist[i] << endl;
    }
}

int main()
{
    int n, x;

    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the source node: ";
    cin >> x;
    dijkstra(graph, x);
    return 0;
}
