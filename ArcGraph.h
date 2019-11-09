#include "igraph.h"

class ArcGraph : public IGraph {
private:
    std::vector<std::pair<int, int>> buffer_;
    int vertice_count_;
public:
    ArcGraph(int vertices_count);

    ArcGraph(const IGraph *graph);

    virtual ~ArcGraph() override = default;

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;

    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
};
