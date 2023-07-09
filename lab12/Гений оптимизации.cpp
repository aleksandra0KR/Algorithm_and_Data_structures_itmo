#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int bfs(vector<vector<int>>& all_, vector<bool>& visited, int u, int t, int f) {
    if (u == t) return f; // дошли до конца

    visited[u] = true;
    for (int v = 0; v < visited.size(); v++)
        if (!visited[v] && all_[u][v] > 0) {

            int df = bfs(all_, visited, v, t, std::min(f, all_[u][v])); // мин пропускная способность на путь
            if (df > 0) {
                all_[u][v] -= df;  // уменьшаем прямое ребро
                all_[v][u] += df;  // увеличиваем остаточную сеть
                return df;
            }
        }
    return 0;
}

int max_flow(vector<vector<int>>& all_, int s, int t, int number_of_vertex) {
    vector<int> parents(number_of_vertex,-1);

    int maxflow = 0;
    int flow;
    int df = 1;

    while(df>0) { // пока есть путь

        vector<bool> visited(number_of_vertex,false);
        flow = 1000000000;
        df = bfs(all_, visited, s, t, flow);
        maxflow += df;
    }
    return maxflow;
}



int main() {
    int number_of_vertex, number_of_edges, start, end, capacity;
    cin >> number_of_vertex >> number_of_edges;

    vector<vector<int>> all_(number_of_vertex, vector<int>(number_of_vertex,0));

    for (int i = 0; i < number_of_edges; i++) {
        cin >> start >> end >> capacity;
        all_[start-1][end-1] = capacity;
    }

    cout << max_flow(all_, 0,number_of_vertex-1,number_of_vertex);
    return 0;
}
