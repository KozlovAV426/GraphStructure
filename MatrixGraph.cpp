#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count): matrix_(vertices_count, std::vector<int>(vertices_count, 0)) {}

MatrixGraph::MatrixGraph(const IGraph *graph) : matrix_(graph->VerticesCount(), std::vector<int>(graph->VerticesCount(), 0)) {
    std::vector<int> next_vertices;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        graph->GetNextVertices(i, next_vertices);
        for (auto vertex : next_vertices) {
           matrix_[i][vertex] += 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix_[from][to] += 1;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix_.size());
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (int i = 0; i < static_cast<int>(matrix_[vertex].size()); ++i) {
        for (int j = 0; j < matrix_[vertex][i]; ++j) {
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (int i = 0; i < static_cast<int>(matrix_.size()); ++i) {
        for (int j = 0; j < matrix_[i][vertex]; ++j) {
            vertices.push_back(i);
        }
    }
}