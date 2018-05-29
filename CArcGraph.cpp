#include "CArcGraph.hpp"

int binomial_coefficient(int n, int k) {
    int res = 1;

    if (k > n - k) {
        k = n - k;
    }

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// get<0> -- from
// get<1> -- to
// get<2> -- weight

ArcGraph::ArcGraph(int count) : verticesCount(count) {
    if (verticesCount != 0) {
        arcs.reserve(binomial_coefficient(verticesCount, 2)); 
        // полагаем, что потенциально могут быть все пути из всех вершин, то есть С^2_N
    }
}

ArcGraph::ArcGraph(const IGraph& graph) {
    verticesCount = graph.VerticesCount(); // мб вынести в список инициализации?
    
    for (int vertex = 0; vertex < verticesCount; ++vertex){
        std::vector<int> nextVertices;
        graph.GetNextVertices(vertex, nextVertices);
        for (auto it = nextVertices.begin(); it != nextVertices.end(); ++it) {
            (*this).AddEdge(vertex, *it);
        }
    }    
}

void ArcGraph::AddEdge(int from, int to) {
    // если существует такое ребро, не создаём его
    for (auto it = arcs.begin(); it != arcs.end(); ++it) {
        if (std::get<0>(*it) == from && std::get<1>(*it) == to) {
            return;
        }
    }
    
    arcs.push_back(std::make_tuple(from, to, defaultWeight));
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

void ArcGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    for (auto it = arcs.begin(); it != arcs.end(); ++it) {
        if (std::get<0>(*it) == vertex) {
            vertices.push_back(std::get<1>(*it));
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    for (auto it = arcs.begin(); it != arcs.end(); ++it) {
        if (std::get<1>(*it) == vertex) {
            vertices.push_back(std::get<0>(*it));
        }
    }
}
