#include "CSetGraph.hpp"


SetGraph::SetGraph(int count) {
    adjacencySets.resize(count);
}

SetGraph::SetGraph(const IGraph& graph) {
    adjacencySets.resize(graph.VerticesCount());
    for (int vertex = 0; vertex < adjacencySets.size(); ++vertex) {
        std::vector<int> nextVertices;
        graph.GetNextVertices(vertex, nextVertices);
        for (auto it = nextVertices.begin(); it != nextVertices.end(); ++it) {
            (*this).AddEdge(vertex, *it);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencySets.size());
    assert(to >= 0 && to < adjacencySets.size());
    
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacencySets.size();
}

void SetGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    assert(vertex >= 0 && vertex < adjacencySets.size());
    
    vertices.clear();
    for (auto it = adjacencySets[vertex].begin(); it != adjacencySets[vertex].end(); ++it) {
        vertices.push_back(*it);
    }
}

void SetGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    assert(vertex >= 0 && vertex < adjacencySets.size());
    
    vertices.clear();
    for (int i = 0; i < adjacencySets.size(); ++i) {
        if (adjacencySets[i].find(vertex) != adjacencySets[i].end()) {
            vertices.push_back(i);
        }
    }
}
