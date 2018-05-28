#ifndef CMatrixGraph_hpp
#define CMatrixGraph_hpp

#include "IGraph.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int count);
    MatrixGraph(const IGraph& graph);
    virtual ~MatrixGraph() = default;
    
    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to);
    
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
    
private:
    std::vector<std::vector<int>> adjacencyMatrix;
};

#endif /* CMatrixGraph_hpp */
