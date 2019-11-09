#include <vector>
#include "igraph.h"

class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> matrix_;
public:
    MatrixGraph(int vertices_count);

    MatrixGraph(const IGraph *graph);

    virtual ~MatrixGraph() override = default;

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;

    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
};
