#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count) : vertice_count_(vertices_count) {
    buffer_.reserve(vertices_count);
}

ArcGraph::ArcGraph(const IGraph *graph) {
    buffer_.reserve(graph->VerticesCount());
    vertice_count_ = graph->VerticesCount();
    std::vector<int> next_vertices;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        graph->GetNextVertices(i, next_vertices);
        for (auto vertex : next_vertices) {
            buffer_.emplace_back(i, vertex);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    buffer_.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertice_count_;
}

void ArcGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (auto vertice: buffer_) {
        if (vertice.first == vertex) {
            vertices.push_back(vertice.second);
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (auto vertice : buffer_) {
        if (vertice.second == vertex) {
            vertices.push_back(vertice.first);
        }
    }
}
