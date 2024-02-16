#include <iostream>
#include <vector>
#include <queue>

struct Node{
    int data;
    char color;
    Node(int number){
        data = number;
        color = 'W';
    }
};

std::vector<int> bfs(std::vector<std::vector<Node>>& list_of, std::vector<int>& destination, int i){
    std::queue<int> Q;
    Q.push(i);
    int u;
    while (!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int j = 1; j < list_of[u].size(); j++){
            int pos = list_of[u][j].data;
            if (destination[pos] == 0){
                destination[pos] = destination[u] + 1;
                Q.push(pos);
            }
        }
    }
    return destination;
}

int main(){

    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<Node>> list_of;
    std::vector<Node> temp;
    std::vector<int> destination;
    for(int i = 0; i < n; i++){
        temp.clear();
        temp.push_back((Node(i)));
        list_of.push_back(temp);
        destination.push_back(0);
    }

    int number;
    int root;

    for(int i = 0; i < m; i++){
        std::cin >> root;
        std::cin >> number;
        list_of[root-1].push_back(list_of[number-1][0]);
        list_of[number-1].push_back(list_of[root-1][0]);
    }

    int u,v;
    std::cin >> u >> v;


    destination = bfs(list_of, destination,u-1);
    if(destination[v-1] != 0) std::cout << (destination[v-1]);
    else std::cout << -1;

    return 0;}