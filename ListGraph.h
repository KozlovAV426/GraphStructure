#pragma once
#include<list>
#include "igraph.h"

class ListGraph : public IGraph {
private:
    std::vector<std::list<int>> vertices_neighbours_;
public:
    ListGraph(int vertices_count);

    ListGraph(const IGraph* graph);

    virtual ~ListGraph() override = default;

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;

    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
};