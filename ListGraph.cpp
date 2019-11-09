#include <list>
#include "ListGraph.h"

ListGraph::ListGraph(int vertices_count) : vertices_neighbours_(vertices_count) {};

ListGraph::ListGraph(const IGraph *graph) : vertices_neighbours_(graph->VerticesCount()) {
    std::vector<int> next_vertices;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        graph->GetNextVertices(i, next_vertices);
        for (auto vertex : next_vertices) {
            vertices_neighbours_[i].push_back(vertex);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    vertices_neighbours_[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(vertices_neighbours_.size());
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for(auto apex:vertices_neighbours_[vertex]) {
        vertices.push_back(apex);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (int i = 0; i < static_cast<int>(vertices_neighbours_.size()); ++i) {
        for (auto apex:vertices_neighbours_[i]) {
            if (apex == vertex) {
                vertices.push_back(i);
            }
        }
    }
}


