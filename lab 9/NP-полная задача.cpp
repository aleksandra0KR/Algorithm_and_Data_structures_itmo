#include <iostream>
#include <vector>
#include <queue>

struct Node{
    int data;
    Node(int number){
        data = number;
    }
};

std::vector<int> bfs(std::vector<std::vector<Node>>& list_of, std::vector<int>& destination, int i){
    std::queue<int> Q;
    Q.push(i);
    int u;
    destination[i] = 0;
    while (!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int j = 1; j < list_of[u].size(); j++){
            int pos = list_of[u][j].data;
            if (destination[pos] == -1){
                destination[pos] = destination[u] + 1;
                Q.push(pos);
            }
        }

    }
    int max_destination = 0;
    int index = 0;


    for (int j = 0; j < list_of.size(); j++)
    {
        if (destination[j] > max_destination)
        {
            max_destination = destination[j];
            index = j;
        }
    }
    std::vector<int> result;
    result.push_back(max_destination);
    result.push_back(index);
    return result;
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
        destination.push_back(-1);
    }

    int number;
    int root;
    for(int i = 0; i < m; i++){
        std::cin >> root;
        std::cin >> number;
        list_of[root-1].push_back(list_of[number-1][0]);
        list_of[number-1].push_back(list_of[root-1][0]);
    }


    std::vector<int> res = bfs(list_of,destination,0);
    for(int i = 0; i< n; i++){
        destination[i] = -1;
    }
    res = bfs(list_of,destination,res[1]);

    if(res[0] + 1 == n) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}