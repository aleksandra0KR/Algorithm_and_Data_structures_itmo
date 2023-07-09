#include <iostream>
#include <vector>
#include <cmath>
using  std::cin;
using  std::cout;
using  std::vector;
using  std::pair;
using std::endl;


int parents____[200000];
vector<bool> visited(200000);
vector<pair<int, pair<int, int>> > grapgh[200000];

vector<int> parents(200000);
vector<int> rang(200000);
vector<pair<int, int> > all_[200000];

vector<int> level(200000);
vector<vector<int>> weights(200000,vector<int>(30)), lca(200000,vector<int>(30));


long long max(long long a, long long b, long long c){
    long long temp = (a > b ? a : b);
    return temp > c ?  temp: c;
}
int max(int a, int b, int c){
    int temp = (a > b ? a : b);
    return temp > c ?  temp: c;
}

void init( int number_of_vertex) {
    for (int i = 0; i < number_of_vertex; i++) {
        parents[i] = i;
        rang[i] = 1;
    }
}
int get_root(int v) {

    if (parents[v] == v) {
        return v;
    } else {
        return parents[v] = get_root(parents[v]);
    }
}
void union_(int a, int b) {

    int ra = get_root(a);
    int rb = get_root(b);

    if (ra == rb) return;

    else {
        if (rang[ra] < rang[rb]) {
            parents[ra] = rb;
        } else if (rang[rb] < rang[ra]) {
            parents[rb] = ra;
        } else {
            parents[ra] = rb;
            rang[rb]++;
        }

    }
}


void dfs(int u, int par, int w, int l, int number_of_edges) {

    level[u] = l;
    lca[u][0] = par;
    weights[u][0] = w;

    for(int i = 1; i < std::log2(number_of_edges); i++){
        lca[u][i] = lca[lca[u][i - 1]][i - 1],
                weights[u][i] = std::max(weights[u][i - 1], weights[lca[u][i - 1]][i - 1]);}

    for(int i = 0; i < all_[u].size(); i++) {
        if (all_[u][i].first != lca[u][0]){
            dfs(all_[u][i].first, u, all_[u][i].second, l + 1, number_of_edges);}
    }
}

long long LCA(int u, int v, int number_of_edges) {

    if(level[u] > level[v]) std::swap(u, v);
    int val = -1000000000;

    for(int i = std::log2(number_of_edges); i >= 0; i--) {
        if (level[lca[v][i]] >= level[u]) {
            val = std::max(val, weights[v][i]);
            v = lca[v][i];
        }
    }

    if(u == v) return val;

    for(int i = std::log2(number_of_edges); i >= 0; i--) {
        if (lca[u][i] != lca[v][i]) {
            val = max(val, weights[u][i], weights[v][i]);
            u = lca[u][i];
            v = lca[v][i];
        }
    }

    return max(val, weights[v][0], weights[u][0]);
}

void ans(int number_of_edges, long long result){

    for(int i = 0; i < number_of_edges; i++) {
        if(visited[i]) cout << result << endl;
        else cout <<  result + (grapgh[i][0].first)- LCA(grapgh[i][0].second.first, grapgh[i][0].second.second, number_of_edges) << endl;
    }

}

int main() {

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int i, number_of_vertex, number_of_edges;
    int start, end, cost;
    long long  result = 0;

    cin >> number_of_vertex >> number_of_edges;

    for(i = 0; i < number_of_edges; i++) {
        parents____[i] = i;
        cin >> start >> end >> cost;
        start--;
        end--;
        grapgh[i].push_back(std::make_pair(cost, std::make_pair(start,end)));
    }

    init(number_of_vertex);
    std::sort(parents____, parents____ + number_of_edges, [](int i, int j) { return grapgh[i][0].first < grapgh[j][0].first; });

    for(i = 0; i < number_of_edges; i++){

        int start = grapgh[parents____[i]][0].second.first;
        int  end = grapgh[parents____[i]][0].second.second;
        long long cost = grapgh[parents____[i]][0].first;
        if (get_root(start) != get_root(end)) {
            result += cost;
            union_ (start, end);
            all_[start].push_back(std::make_pair(end, cost));
            all_[end].push_back(std::make_pair(start, cost));
            visited[parents____[i]] = true;
        }
    }

    dfs(0, 0, -1000000000, 0, number_of_edges);
    ans(number_of_edges,  result);
}