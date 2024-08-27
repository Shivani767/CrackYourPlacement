#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v, int graph[][21], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(int graph[][21], int color[], int m, int V, int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V) == true) {
            color[v] = c;
            if (graphColoringUtil(graph, color, m, V, v + 1) == true)
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int graph[][21], int m, int V) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, color, m, V, 0))
        return false;

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int graph[21][21];
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        if (graphColoring(graph, m, n))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
