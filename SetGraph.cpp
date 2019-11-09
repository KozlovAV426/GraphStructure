#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count) : buffer_(vertices_count) {}

SetGraph::SetGraph(const IGraph *graph) : buffer_(graph->VerticesCount()) {
    std::vector<int> next_vertices;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        graph->GetNextVertices(i, next_vertices);
        for (auto vertex : next_vertices) {
            buffer_[i].insert(vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    buffer_[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(buffer_.size());
}

void SetGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (auto vertice : buffer_[vertex]) {
        vertices.push_back(vertice);
    }
}

void SetGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (int i = 0; i < static_cast<int>(buffer_.size()); ++i) {
        for (auto vertice : buffer_[i]) {
            if (vertice == vertex) {
                vertices.push_back(i);
            }
        }
    }
}
