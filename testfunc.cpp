#include "testfunc.h"

void TestFuncFromFile() {
    std::ifstream in;
    in.open("../tests/test4"); // test[1..5] номера тестов
    int vertex;
    int edges;
    in >> vertex >> edges;
    IGraph *igraph = new ListGraph(vertex); // создание графа любого из типов из входящих данных
    for (int i = 0; i < edges; ++i) {
        int from;
        int to;
        in >> from >> to;
        igraph->AddEdge(from, to);
    }
    std::vector<int> next_vertices;
    std::vector<int> prev_vertices;
    std::vector<int> check;
    int j = 0;
    for (int i = 0; i < vertex; ++i) {
        int result = 0;
        next_vertices.clear();
        prev_vertices.clear();
        igraph->GetNextVertices(i, next_vertices);   // получение результатов функций
        igraph->GetPrevVertices(i, prev_vertices);
        check.clear();
        for (int i = 0; i < next_vertices.size(); ++i) { // считывание ответа из файла
            int vertice;
            in >> vertice;
            check.push_back(vertice);
        }
        std::sort(next_vertices.begin(), next_vertices.end());
        assert(next_vertices == check);    // проверка результатов работы GetNextVertices
        ++j;
        std::cout << "test " << j << " is ok" << std::endl;
        std::sort(prev_vertices.begin(), prev_vertices.end());
        check.clear();
        for (int i = 0; i < prev_vertices.size(); ++i) {  // аналогичная процедура для проверки GetPrevVertices
            int vertice;
            in >> vertice;
            check.push_back(vertice);
        }
        assert(prev_vertices == check);
        ++j;
        std::cout << "test " << j << " is ok" << std::endl;
    }
        delete igraph;
        in.close();
}

bool TestGraph(const IGraph *graph,  std::vector<std::vector<int>> results) { // данная функция
    bool equal = true;                // сверяет ответы полученные для некоторого graph с эталонными
    std::vector<int> next_vertices;    // ответами, полученными от графа другого типа
    std::vector<int> prev_vertices;
    int j = 0;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        next_vertices.clear();
        prev_vertices.clear();
        graph->GetNextVertices(i, next_vertices);
        graph->GetPrevVertices(i, prev_vertices);
        std::sort(next_vertices.begin(), next_vertices.end());
        std::sort(prev_vertices.begin(), prev_vertices.end());
        if (next_vertices != results[j]) {
            return false;
        }
        ++j;
        if (prev_vertices != results[j]) {
            return false;
        }
        ++j;
    }
    return true;
}

void TestOnRandomVertices(int vertice) {
    srand(time(0));
    int vertex = abs(rand() % vertice) + 1;   // генерация случайного количества вершин и количества ребер
    int edges = abs(rand() % vertex) + 1 ;
    IGraph *graph = new ListGraph(vertex);
    for (int i = 0; i < edges; ++i) {
        int from = abs(rand() % vertex);   // добавление случайных ребер в граф
        int to = abs(rand() % vertex);
        graph->AddEdge(from, to);
    }
    std::vector<int> check;
    std::vector<std::vector<int>> results;  // вектор эталонных ответов на операции GetNextVertices и
    for (int i = 0; i < vertex; ++i) {                 // GetPrevVertices, полученный от ListGraph
        check.clear();
        graph->GetNextVertices(i, check);
        std::sort(check.begin(), check.end());
        results.push_back(check);
        check.clear();
        graph->GetPrevVertices(i, check);
        std::sort(check.begin(), check.end());
        results.push_back(check);
    }
    IGraph *matrixgraph = new MatrixGraph(graph);
    IGraph *setgraph = new SetGraph(matrixgraph);
    IGraph *arcgraph = new ArcGraph(graph);
    assert(TestGraph(matrixgraph, results));   // проверяем: одинаковы ли результаты выполнения одних и
    std::cout << "test matrixgraph is ok" << std::endl;   // тех же функций
    assert(TestGraph(setgraph, results));
    std::cout << "test setgraph is ok" << std::endl;
    assert(TestGraph(arcgraph, results));
    std::cout << "test arcgraph is ok" << std::endl;
    delete graph;
    delete matrixgraph;
    delete setgraph;
    delete arcgraph;
}
