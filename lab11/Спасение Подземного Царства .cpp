#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using  std::cin;
using  std::cout;
using  std::vector;
using  std::stack;
using  std::unordered_map;

struct Node{
    int value;
    int worth;
    Node(int v, int w){
        value = v;
        worth = w;
    }
};

void dfs(vector<bool>& visited, unordered_map<int, vector<Node>>& adg_list, int i, stack<int>& sorted_vertex){
    visited[i] = true;
    int pos;
    for(int j = 0; j< adg_list[i].size(); j++){
        pos = adg_list[i][j].value;
        if (!visited[pos]) dfs(visited,adg_list,pos,sorted_vertex);
    }
    sorted_vertex.push(i);
}

void top_sort(vector<bool>& visited, unordered_map<int, vector<Node>>& adg_list, int n, stack<int>& sorted_vertex){
    for(int  i = 0; i < n; i++){
        if (!visited[i]) dfs(visited,adg_list,i, sorted_vertex);
    }
}

void DAG(stack<int>& sorted_vertex, vector<int>& dist, unordered_map<int, vector<Node>>&  adg_list, int start){


    dist[start] = 0;
    while (sorted_vertex.empty() == false)
    {
        int u = sorted_vertex.top();
        sorted_vertex.pop();

        if (dist[u] != INT32_MAX)
        {
            for (int i = 0; i < adg_list[u].size(); i++){
                if (dist[adg_list[u][i].value] > dist[u] + adg_list[u][i].worth)
                    dist[adg_list[u][i].value] = dist[u] + adg_list[u][i].worth;
            }

        }
    }
}

int main(){
    int number_of_vertexs, number_of_edges;
    int vertex, edge, worth;
    int start, end;
    unordered_map<int, vector<Node>> adg_list;
    vector<bool> visited;

    cin >> number_of_vertexs;
    cin >> number_of_edges;
    cin >> start;
    cin >> end;

    vector<int> dist(number_of_vertexs,INT32_MAX);

    for(int i = 0; i < number_of_vertexs; i++){
        adg_list.insert({i,{}});
        visited.push_back(false);
    }

    for(int i = 0; i < number_of_edges; i++){
        cin >> vertex;
        cin >> edge;
        cin >> worth;
        adg_list[vertex - 1].push_back(Node(edge-1, worth));
    }

    stack<int> sorted_vertex;
    top_sort(visited,adg_list,number_of_vertexs,sorted_vertex);
    DAG( sorted_vertex, dist, adg_list, start-1);
    cout << (dist[end - 1] != INT32_MAX ? dist[end - 1] : -1);

    return 0;
}