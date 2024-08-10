#pragma once
#include <vector>
#include <list>

class Graph {
public:
    Graph(unsigned numVertices) : m_numVertices(numVertices)
    {
        adjList.resize(numVertices);
    }

    //TODO, STUDENTS: Implement this func
    void addEdge(unsigned x, unsigned y);

    //TODO, STUDNETS: Implement modified BFS algo to return path from start to destination only
    //no need to traverse the whole Graph
    std::vector<unsigned> bfs(unsigned start, unsigned destination);

private:
    unsigned m_numVertices;
    std::vector<std::list<unsigned>> adjList;
};
