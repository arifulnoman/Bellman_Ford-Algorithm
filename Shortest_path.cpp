#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u,w,v;
};
#define inf 10000
vector<node> graph;
int dis[100];
int source;
void get_edges(int edge)
{
    int i;
    for(i = 0;i < edge;i++)
    {
        node temp;
        cin >> temp.u >> temp.w >> temp.v;
        graph.push_back(temp);
    }
}
void initialize(int vertex)
{
    int i;
    for(i = 0;i < vertex;i++)
    {
        dis[i] = inf;
    }
}
void bellman_ford(int vertex)
{
    int i,j;
    for(i = 0;i < vertex-1;i++)
    {
        for(j = 0;j < graph.size();j++)
        {
            node extract = graph[j];
            int u = extract.u;
            int w = extract.w;
            int v = extract.v;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }
}
bool check_negative_cycle()
{
    int i;
    for(i = 0;i < graph.size();i++)
    {
        node extract = graph[i];
        int u = extract.u;
        int w = extract.w;
        int v = extract.v;
        if(dis[v] > dis[u] + w)
        {
            return false;
        }
    }
    return true;
}
void print_graph(int vertex)
{
    int i;
    for(i = 0;i < vertex;i++)
    {
        cout << "Distance from " << source << " to " << i << " ----> " << dis[i] << endl;
    }
}
int main()
{
    int vertex,edge;
    cout << "Enter the number of vertexes: ";
    cin >> vertex;
    cout << "Enter number of edges: ";
    cin >> edge;
    initialize(vertex);
    get_edges(edge);
    cout << "Enter the source vertex: ";
    cin >> source;
    dis[source] = 0;
    bellman_ford(vertex);
    bool check = check_negative_cycle();
    if(check == true)
    {
        print_graph(vertex);
    }
    else
    {
        cout << "There is a negative cycle in the graph";
    }
    return 0;
}