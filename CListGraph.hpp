#ifndef CListGraph_hpp
#define CListGraph_hpp

#include "IGraph.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>

class ListGraph : public IGraph {
public:
    ListGraph(int count);
    ListGraph(const IGraph& graph);
    virtual ~ListGraph() = default;
    
    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to);
    
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
    
private:
    std::vector<std::vector<int>> adjacencyLists;
};


#endif /* CListGraph_hpp */
