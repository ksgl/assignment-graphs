#include "CMatrixGraph.hpp"


MatrixGraph::MatrixGraph(int count) {
    assert(count > 0);
    
    adjacencyMatrix.resize(count);
    for (auto it = adjacencyMatrix.begin(); it != adjacencyMatrix.end(); ++it) {
        it->resize(count, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph) {
    adjacencyMatrix.clear();
    adjacencyMatrix.resize(graph.VerticesCount());
    for (auto& row : adjacencyMatrix) {
        row.resize(graph.VerticesCount(), 0);
    }
    
    for (int from = 0; from < adjacencyMatrix.size(); ++from) {
        std::vector<int> nextVertices;
        graph.GetNextVertices(from, nextVertices);
        for (auto& vertex : nextVertices) {
            adjacencyMatrix[from][vertex] = 1;
        }
    }
}


void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencyMatrix.size());
    assert(to >= 0 && to < adjacencyMatrix.size());
    
    adjacencyMatrix[from][to] = 1; // в дальнейшем можно добавлять вес ребра, а не 1
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

// массив вершин, к котором мы имеем доступ из вершины vertex
void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    assert((adjacencyMatrix.size() > 0) == (vertex >= 0));
    // условие того, что матрица пуста, и вертекс < 0 происходят одновремененно
    for (auto& row : adjacencyMatrix) {
        assert(row.size() == adjacencyMatrix.size());
    }
    
    vertices.clear();
    for (int to = 0; to < adjacencyMatrix[vertex].size(); ++to) {
        if (adjacencyMatrix[vertex][to] != 0) {
            vertices.push_back(to);
        }
    }
}

// массив вершин, из которых мы имеем доступ к вершине vertex
void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    assert((adjacencyMatrix.size() > 0) == (vertex >= 0));
    // условие того, что матрица пуста, и вертекс < 0 происходят одновремененно
    for (auto& row : adjacencyMatrix) {
        assert(row.size() == adjacencyMatrix.size());
    }
    
    vertices.clear();
    for (int from = 0; from < adjacencyMatrix.size(); ++from) {
        if (adjacencyMatrix[from][vertex] != 0) {
            vertices.push_back(from);
        }
    }
}
