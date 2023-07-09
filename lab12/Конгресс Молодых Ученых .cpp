#include <iostream>
#include <vector>
using  std::cin;
using  std::cout;
using  std::vector;
using std::pair;

void init(vector<int>& parent, int number_of_vertex, vector<int>& rang) { // инициализация массива предков и ранга
    for (int i = 0; i <= number_of_vertex; i++) {
        parent[i] = i;
        rang[i] = 0;
    }
}

int get_root(int v, vector<int>& parent) { // поиска предка
    if (parent[v] == v) {
        return v;
    } else {
        return parent[v] = get_root(parent[v], parent);
    }
}

void union_(int a, int b, vector<int>& parent, vector<int>& rang) { // объединение

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

    int worth, firstworth = 0;
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
    init(parent, number_of_vertex, rang);
    for (int i=0; i < number_of_edges; i++) {

        start = all_[i].second.first;
        end = all_[i].second.second;
        cost = all_[i].first;

        if (get_root(start,parent) != get_root(end,parent)) {
            firstworth += cost;
            res.push_back (all_[i].second);
            union_ (start, end,parent,rang);
        }
    }

    int prevworth;
    worth = INT32_MAX;
    for (int j=0; j < number_of_edges; j++) {

        init(parent,number_of_vertex, rang);
        prevworth = 0;

        for (int i = 0; i < number_of_edges; i++) {
            if (i == j) continue; // не рассматриваем одно из ребер, чтобы найти другое mst
            start = all_[i].second.first;
            end = all_[i].second.second;
            cost = all_[i].first;

            if (get_root(start,parent) != get_root(end,parent)) {
                prevworth += cost;
                res.push_back (all_[i].second);
                union_ (start, end,parent,rang);
            }
        }
        if (prevworth != firstworth) worth = std::min(prevworth, worth);
    }

    cout << firstworth << " " <<  worth;
    return 0;
}