#include <iostream>
#include <fstream>
#include <limits.h>
#include <list>
#include <vector>
#include <queue>


using namespace std;
# define INF 0x3f3f3f3f


typedef pair<int, int> iPair;

class Graph
{
    int V;
    list< pair<int, int> >* adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}


void Graph::shortestPath(int src)
{
    priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    ofstream file1("C:\\Tests\\path.out");
    for (int i = 0; i < V; ++i)
        file1 << dist[i] << " ";
    file1.close();
}

int main()
{
    ifstream file("C:\\Tests\\path.in");
    int number_of_veretexes, edges;
    file >> number_of_veretexes >> edges;
    Graph g(number_of_veretexes);
    int _first_, _second_, _third_;
    for (int i = 0; i < edges; i++) {
        file >> _first_ >> _second_ >> _third_;
        g.addEdge( _first_ - 1, _second_ - 1, _third_);
    }
    g.shortestPath(0);
    file.close();
    return 0;
}
