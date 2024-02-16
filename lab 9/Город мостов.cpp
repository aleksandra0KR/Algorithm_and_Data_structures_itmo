#include <iostream>
#include <vector>

struct Node{
    int data;
    char color;
    Node(int number){
        data = number;
        color = 'W';
    }
};

int cycle(std::vector<std::vector<Node>>& list_of, int i, int parent){
    list_of[i][0].color = 'G';

    for(int j = 1; j < list_of[i].size(); j++){

        int pos = list_of[i][j].data;
        if(list_of[pos][0].color == 'W'){
            cycle(list_of, list_of[pos][0].data, list_of[i][0].data);
        }

        else if(list_of[pos][0].color == 'G' and list_of[pos][0].data != parent){
            return 1;
        }
    }

    list_of[i][0].color = 'B';
    return 0;
}

int main(){

    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<Node>> list_of;
    std::vector<Node> temp;
    for(int i = 0; i < n; i++){
        temp.clear();
        temp.push_back((Node(i)));
        list_of.push_back(temp);
    }

    int number;
    int root;

    for(int i = 0; i < m; i++){
        std::cin >> root;
        std::cin >> number;
        list_of[root-1].push_back(list_of[number-1][0]);
        list_of[number-1].push_back(list_of[root-1][0]);
    }

    int res = 0;
    for(int i = 0; i < n; i++){

        if( cycle(list_of, i, i) == 1) res = 1;

    }

    if (res == 1) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}