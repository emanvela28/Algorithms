#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


void DFS(vector<int>* graph, int vertex, bool* visited, int* finishTime, int& currentTime) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) { 
        if (!visited[neighbor]) { 
            DFS(graph, neighbor, visited, finishTime, currentTime);
        }
    }
    finishTime[vertex] = currentTime++;
}


void collectSCC(vector<int>* transposedGraph, int vertex, bool* visited, vector<int>& scc) {
    visited[vertex] = true; 
    scc.push_back(vertex); 
    for (int neighbor : transposedGraph[vertex]) {
        if (!visited[neighbor]) {
            collectSCC(transposedGraph, neighbor, visited, scc);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int>* graph = new vector<int>[vertices];
    vector<int>* transposedGraph = new vector<int>[vertices];
    
    for (int i = 0; i < edges; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        transposedGraph[end].push_back(start);
    }

    bool* visited = new bool[vertices]();
    int* finishTime = new int[vertices]();
    int currentTime = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, finishTime, currentTime);
        }
    }

    fill(visited, visited + vertices, false);
    vector<vector<int>> sccList;
    vector<int> order(vertices);
    
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) { return finishTime[a] > finishTime[b]; });

    for (int i : order) {
        if (!visited[i]) {
            vector<int> scc;
            collectSCC(transposedGraph, i, visited, scc);
            sccList.push_back(scc);
        }
    }

    int* result = new int[vertices];
    for (auto& scc : sccList) {
        int sccID = *min_element(scc.begin(), scc.end());
        for (int vertex : scc) {
            result[vertex] = sccID;
        }
    }

    for (int i = 0; i < vertices; i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}

