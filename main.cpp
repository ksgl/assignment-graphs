/*
 Написать различные представления графов.
 */

#include "IGraph.hpp"
#include "CListGraph.hpp"
#include "CMatrixGraph.hpp"
#include "CArcGraph.hpp"
#include "CSetGraph.hpp"

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

void BFS(const IGraph& graph, int vertex, std::function<void(int)> visit) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visit(current);
        std::vector<int> adjacentVertices;
        graph.GetNextVertices(current, adjacentVertices);
        for( int i = 0; i < adjacentVertices.size(); i++ ) {
            if (!visited[adjacentVertices[i]]) {
                q.push(adjacentVertices[i]);
                visited[adjacentVertices[i]] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    {
        std::cout << "Start test case 1: inititalizing a list graph, adding 7 edges, BFS-ing from 0-th vertex" << std::endl;
        ListGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        std::cout << "Output: ";
        BFS(graph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         1: 0 1 5 2 3 6 4
         */
    }
    
    {
        std::cout << "Start test case 2: inititalizing a list graph, adding 7 edges, BFS-ing from 5-th vertex" << std::endl;
        ListGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        std::cout << "Output: ";
        BFS(graph, 5, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         2: 5 4 6 3 2
         */
    }
    
    {
        std::cout << "Start test case 3: inititalizing a matrix graph, adding 7 edges, BFS-ing from 0-th vertex" << std::endl;
        MatrixGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        std::cout << "Output: ";
        BFS(graph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         3: 0 1 5 2 3 6 4
         */
    }
    
    {
        std::cout << "Start test case 4: inititalizing a list graph, then calling MatrixGraph(IGraph* graph) on it, BFS-ing from 0-th vertex" << std::endl;
        ListGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        MatrixGraph matrGraph(graph);
        
        std::cout << "Output: ";
        BFS(matrGraph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         4: 0 1 5 2 3 6 4
         */
    }
    
    {
        std::cout << "Start test case 5: inititalizing an arc-graph, BFS-ing from 0-th vertex" << std::endl;
        ArcGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        MatrixGraph matrGraph(graph);
        
        std::cout << "Output: ";
        BFS(graph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         5: 0 1 5 2 3 6 4
         */
    }
    
    {
        std::cout << "Start test case 6: inititalizing a list graph, then calling ArcGraph(IGraph* graph) on it, BFS-ing from 0-th vertex" << std::endl;
        ListGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        ArcGraph arcGraph(graph);
        
        std::cout << "Output: ";
        BFS(arcGraph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         6: 0 1 5 2 3 6 4
         */
    }
    
    {
        std::cout << "Start test case 7: inititalizing a matrix graph, then calling ArcGraph(IGraph* graph) on it, BFS-ing from 0-th vertex" << std::endl;
        MatrixGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        ArcGraph arcGraph(graph);
        
        std::cout << "Output: ";
        BFS(arcGraph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         7: 0 1 5 2 3 6 4
         */
    }
    
    {
        std::cout << "Start test case 8: inititalizing a set graph, adding 7 edges, BFS-ing from 0-th vertex" << std::endl;
        SetGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        std::cout << "Output: ";
        BFS(graph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         8: 0 5 1 6 4 3 2
         */
    }
    
    {
        std::cout << "Start test case 9: inititalizing a list graph, then calling SetGraph(IGraph* graph) on it, BFS-ing from 0-th vertex" << std::endl;
        ListGraph graph(7);
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 5);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(3, 2);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 3);
        graph.AddEdge(5, 4);
        graph.AddEdge(5, 6);
        graph.AddEdge(6, 4);
        
        SetGraph setGraph(graph);
        
        std::cout << "Output: ";
        BFS(setGraph, 0, [](int vertex){ std::cout << vertex << " "; });
        std::cout << std::endl << std::endl;
        
        /* Expected output:
         8: 0 5 1 6 4 3 2
         */
    }
    
    return EXIT_SUCCESS;
}
