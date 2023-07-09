#include <iostream>
#include <vector>
using  std::cin;
using  std::cout;
using  std::vector;
using std::pair;

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

    int number_of_vertex, number_of_edges;
    cin >> number_of_vertex >> number_of_edges;

    int start, end, cost;
    vector<int> parent;
    parent.resize(number_of_vertex + 1);
    vector<int> rang;
    rang.resize(number_of_vertex + 1);
    vector < pair <int, pair<int,int> > > all_;
    vector < pair<int,int> > res;

    for(int i = 0; i < number_of_edges; i++){
        cin >> start >> end >> cost;
        all_.push_back(std::make_pair(cost, std::make_pair(start, end)));
    }
    sort (all_.begin(), all_.end());

    init(parent,number_of_vertex, rang);
    int worth = 0;

    for (int i=0; i<number_of_edges; ++i) {
        start = all_[i].second.first;
        end = all_[i].second.second;
        cost = all_[i].first;
        if (get_root(start,parent) != get_root(end,parent)) {
            worth += cost;
            res.push_back (all_[i].second);
            union_ (start, end,parent,rang);
        }
    }
    cout << worth;

    return 0;
}