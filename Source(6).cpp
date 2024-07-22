#include <iostream>
using namespace std;
class GraphSearch 
{
private:
    int V;
    int** adj;

public:
    GraphSearch(int value) 
    {
        V = value;
        adj = new int* [value];
        for (int i = 0; i < value; ++i) 
        {
            adj[i] = new int[value];
            for (int j = 0; j < value; ++j)
            {
                adj[i][j] = 0;
            }
        }
    }
    void add_edg(int v, int w)
    {
        adj[v][w] = 1;
    }
    void bfs(int s)
    {
        cout << "BFS from start vertex " << s << ":\n";
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i)
        {
            visited[i] = false;
        }
        visited[s] = true;
        cout << s << " ";
        for (int i = 0; i < V; ++i) 
        {
            if (adj[s][i] && !visited[i]) 
            {
                visited[i] = true;
                cout << i << " ";
            }
        }
        delete[] visited;
    }

    void dfs(int s)
    {
        cout << "DFS traversal starting from vertex " << s << ":\n";
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i)
        {
            visited[i] = false;
        }
        cout << s << " ";
        visited[s] = true;
        for (int i = 0; i < V; ++i) 
        {
            if (adj[s][i] && !visited[i]) 
            {
                dfs(i);
            }
        }
        delete[] visited;
    }

    ~GraphSearch()
    {
        for (int i = 0; i < V; ++i)
        {
            delete[] adj[i];
        }
        delete[] adj;
    }

};

int main()
{
    GraphSearch graph(4);
    graph.add_edg(0, 1);
    graph.add_edg(0, 2);
    graph.add_edg(1, 2);
    graph.add_edg(2, 0);
    graph.add_edg(2, 3);
    graph.add_edg(3, 3);
    graph.bfs(2);
    cout << "\n";
    graph.dfs(2);
    return 0;
}
