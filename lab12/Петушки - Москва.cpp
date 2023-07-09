#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

bool dfs(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<int>& matching, int number_of_vertex){ // поиск пути

    if (visited[u]) return false;

    visited[u] = true;
    for (auto v: graph[u]){
        if (!visited[v]){

            if (matching[v] == -1 or dfs(graph, matching[v], visited, matching, number_of_vertex)){ // если вершина свободная или есть доп путь
                matching[v] = u;
                return true; }
        }
    }
    return false;
}

int max_matching(vector<vector<int>>& graph, int number_of_vertex, int col)
{
    vector<int> matching(number_of_vertex * col,-1);

    int result = 0;

    for (int i = 0; i < number_of_vertex * col; i++){

        vector<bool> visited(number_of_vertex * col, false);

        if (dfs(graph, i, visited, matching, number_of_vertex * col)) result++;
    }
    return result;
}


int main()
{

    int col, row;
    int x_coordinats, y_coordinats, number_of_crosses;

    cin >> col >> row;
    cin >> number_of_crosses;

    vector<vector<bool>> all_(col, vector<bool> (row, 1));
    vector<vector<int>> graph(col*row);

    for(int i = 0; i < number_of_crosses; i++){
        cin >> x_coordinats >> y_coordinats;
        all_[x_coordinats-1][y_coordinats-1] = 0;
    }

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {

            if (all_[i][j] != 0) {
                if (i + 1 < col and all_[i + 1][j]) {
                    graph[i * row + j].push_back((i + 1) * row + j);
                }
                if (i - 1 >= 0 and all_[i - 1][j]) {
                    graph[i * row + j].push_back((i - 1) * row + j);
                }
                if (j - 1 >= 0 and all_[i][j - 1]) {
                    graph[i * row + j].push_back(i * row + (j - 1));
                }
                if (j + 1 < row  and all_[i][j + 1]) {
                    graph[i * row + j].push_back(i * row + (j + 1));
                }
            }
        }
    }

    cout << max_matching(graph, row, col);

    return 0;
}
