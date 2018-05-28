#ifndef CArcGraph_hpp
#define CArcGraph_hpp

#include "IGraph.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <cassert>


class ArcGraph : public IGraph {
public:
    ArcGraph(int count);
    ArcGraph(const IGraph& graph);
    virtual ~ArcGraph() = default;
    
    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to);
    
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
    
private:
    std::vector<std::tuple<int, int, int>> arcs; // третий элемент в кортеже потенциально для обозначения веса ребра
    int verticesCount;
    int defaultWeight = 0;
};

#endif /* CArcGraph_hpp */
