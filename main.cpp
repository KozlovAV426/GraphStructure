#include "testfunc.h"
#include "MatrixGraph.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {

    IGraph *graph = new MatrixGraph(5);
    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(0, 3);
    std::vector<int> next;
    graph->GetNextVertices(0, next);
    for (auto v : next) {
        cout << v << " ";
    }

    /*TestFuncFromFile();
    TestOnRandomVertices(100);*/
    return 0;
}


