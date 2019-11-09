#include "igraph.h"
#include "SetGraph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "ArcGraph.h"
#include <algorithm>
#include <fstream>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void TestFuncFromFile(); // тестирование из файлов папка tests

void TestOnRandomVertices(int vertice);   // тестирование на случайных данных, на вход поступает количество требуемых
                                             // вершин
bool TestGraphs(const IGraph *graph,  std::vector<std::vector<int>> results); // вспомогательная функция
                                                                    // для TestOnRandomVertices