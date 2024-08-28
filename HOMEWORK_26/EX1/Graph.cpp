#include "Graph.h"
#include <queue>
#include <unordered_map>

//TODO, STUDENTS: Implement this func
void Graph::addEdge(unsigned x, unsigned y)
{
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}


//TODO, STUDENTS: Implement modified BFS algo to return path from start to destination only
//no need to traverse the whole Graph
std::vector<unsigned> Graph::bfs(unsigned start, unsigned destination)
{
    std::vector<unsigned> path;
    std::vector<bool> visited(adjList.size(), false);
    std::unordered_map<unsigned, unsigned> parent;
    std::queue<unsigned> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        unsigned node = q.front();
        q.pop();

        if (node == destination)
        {
            for (unsigned v = destination; v != start; v = parent[v])
            {
                path.push_back(v);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (unsigned neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    return path;
}
