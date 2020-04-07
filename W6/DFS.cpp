#include <iostream>
#include <list>
using namespace std;
 
class Graph
{
    int node_count;
 
    list<int> *adj;
 
public:
    Graph(int node_count)
    {
        this->node_count = node_count;
        adj = new list<int>[node_count];
    }
 
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
 
    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
 
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }
 
    void DFS(int v)
    {
        bool *visited = new bool[node_count];
        for (int i = 0; i < node_count; i++)
            visited[i] = false;
 
        DFSUtil(v, visited);
    }
};
 
int main()
{
 
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 7);
    g.addEdge(3, 8);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(5, 6);
    g.addEdge(7, 8);
 
    cout << "Depth First Traversal";
    cout << " (Mulai dari Node 1) \n";
    g.DFS(1);
 
    return 0;
}
