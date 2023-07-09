#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using  std::cin;
using  std::cout;
using  std::vector;
using  std::priority_queue;
using  std::unordered_map;

struct Node{
    int value;
    int worth;
    Node(int v, int w){
        value = v;
        worth = w;
    }
};


void Deikstra(vector<int>& dist, unordered_map<int, vector<Node>>&  adg_list, int start, int number_of_vertexs){

    dist[start] = 0;
    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>,std::greater<>> Q;
    Q.emplace(0, start);

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for (int v = 0; v < adg_list[u].size(); v++){
            if (dist[u] + adg_list[u][v].worth < dist[adg_list[u][v].value]){
                dist[adg_list[u][v].value] = dist[u] + adg_list[u][v].worth;
                Q.emplace(dist[adg_list[u][v].value], adg_list[u][v].value);}
        }
    }

}

int main() {
    int number_of_vertexs, number_of_edges, Q;
    int vertex, edge, worth;
    int start;


    cin >> number_of_vertexs;
    cin >> number_of_edges;
    cin >> Q;
    cin >> start;

    vector<int> dist(number_of_vertexs, 1000000000);
    unordered_map<int, vector<Node>> adg_list(number_of_vertexs);
    for (int i = 0; i < number_of_vertexs; i++) {
        adg_list.insert({i, {}});
    }

    for (int i = 0; i < number_of_edges; i++) {
        cin >> vertex;
        cin >> edge;
        cin >> worth;
        adg_list[edge - 1].push_back(Node(vertex - 1, worth));
        adg_list[vertex - 1].push_back(Node(edge - 1, worth));
    }
    Deikstra(dist, adg_list, start - 1, number_of_vertexs);
    for(int i = 0; i < Q; i++){
        cin >> start;
        cout << (dist[start - 1] != 1000000000 ? dist[start - 1] : -1) << '\n';
    }

    return 0;

}