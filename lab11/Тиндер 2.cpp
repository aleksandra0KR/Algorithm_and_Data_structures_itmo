#include <iostream>
#include <vector>
using  std::cin;
using  std::cout;
using  std::vector;

void init(vector<int>& parent, int number_of_vertex, vector<int>& rang) {
    for (int i = 0; i <= number_of_vertex; i++) {
        parent[i] = i;
        rang[i] = 0;
    }
}

int get_root(int v, vector<int>& parent) {
    if (parent[v] == v) {
        return v;
    } else {
        return parent[v] = get_root(parent[v], parent);
    }
}


void union_(int a, int b, vector<int>& parent, vector<int>& rang) {

    int ra = get_root(a,parent);
    int rb = get_root(b,parent);

    if (ra == rb) return;

    else {
        if (rang[ra] < rang[rb]) {
            parent[ra] = rb;
        } else if (rang[rb] < rang[ra]) {
            parent[rb] = ra;
        } else {
            parent[ra] = rb;
            rang[rb]++;
        }

    }

}
int main(){

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int number_of_vertex, number_of_edges, Q;
    cin >> number_of_vertex >> number_of_edges >> Q;
    int start, end;
    vector<int> parent;
    parent.resize(number_of_vertex + 1);
    vector<int> rang;
    rang.resize(number_of_vertex + 1);
    vector<vector<int>> all_(number_of_vertex,vector<int>());
    vector<std::tuple<char, int, int>> arr;

    for(int i = 0; i < number_of_edges; i++){
        cin >> start >> end;
        all_[start - 1].push_back(end - 1);
    }

    char command;
    for(int i = 0; i < Q; i++){

        cin >> command;
        cin >> start >> end;
        arr.emplace_back(command, start - 1, end-1);
        if(command == '-') {

            for(int t = 0; t < all_[start - 1].size(); t++){
                if(all_[start - 1][t] == end - 1) {
                    all_[start - 1][t] = start - 1;
                    break;
                }}

            for(int t = 0; t < all_[end - 1].size(); t++){
                if(all_[end - 1][t] == start - 1) {
                    all_[end - 1][t] = end - 1;
                    break;
                }}
        }
    }

    init(parent,number_of_vertex, rang);
    for(int i = 0; i  < number_of_vertex; i++){

        for(int j = 0; j < all_[i].size(); j++){
            union_(i,all_[i][j],parent, rang);
        }
    }


    vector<int> result(Q+1, 0);
    for(int i = Q - 1; i >= 0; i--)
    {
        if (std::get<0>(arr[i]) == '?') result[i] = ((get_root(std::get<1>(arr[i]),parent)) == (get_root(std::get<2>(arr[i]),parent)));
        else union_(std::get<1>(arr[i]),std::get<2>(arr[i]),parent,rang);

    }

    for(int i = 0; i < Q; i++){
        if ((std::get<0>(arr[i]) == '?')){
            if(result[i]) cout << "YES\n";
            else cout << "NO\n";}
    }

    return 0;
}