#include "igraph.h"
#include <unordered_set>
#include <vector>

class SetGraph : public IGraph {
private:
    std::vector<std::unordered_multiset<int>> buffer_;
public:
    SetGraph(int vertices_count) ;

    SetGraph(const IGraph *graph);

    virtual ~SetGraph() override = default;

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;

    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
};