#ifndef CSetGraph_hpp
#define CSetGraph_hpp

#include "IGraph.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

class SetGraph : public IGraph {
public:
    SetGraph(int count);
    SetGraph(const IGraph& graph);
    virtual ~SetGraph() = default;
    
    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to);
    
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
    
private:
    std::vector<std::unordered_set<int>> adjacencySets;
};

#endif /* CSetGraph_hpp */
