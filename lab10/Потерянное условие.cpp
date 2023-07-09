#include <vector>
#include <iostream>
#include <stack>
using std::stack;
using std::vector;
using std::cin;
using std::cout;

void dfs(vector<vector<int>>& list_of, vector<bool>& visited, stack<int>& ans, int i) {
    visited[i] = true;
    int pos;

    for (int j = 1; j < list_of[i].size(); j++) {
        pos = list_of[i][j];
        if (!visited[pos])
            dfs(list_of, visited, ans,pos);
    }

    ans.push(i);
}

void top_sort(vector<vector<int>>& list_of, vector<bool>& visited, stack<int>& ans, int n) {

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(list_of, visited, ans,i);
    }

}

int main(){

    int n,m;
    cin >> n >> m;
    vector<vector<int>> list_of;
    vector<bool> visited;
    stack<int> ans;
    vector<int> res;

    for(int i = 0; i < n; i++){
        list_of.push_back( { i });
        visited.push_back(false);
        res.push_back(0);
    }

    int a,b;
    for(int i = 0; i < m; i++){
        std::cin >> a >> b;
        list_of[a-1].push_back(b-1);
    }

    top_sort(list_of,visited,ans,n);

    int pos;
    int init_pos = 0;
    while(!ans.empty()){
        pos = ans.top();
        ans.pop();
        res[pos] = list_of[init_pos++][0] + 1;
    }

    for(auto u: res){
        cout << u << " ";
    }

    return 0;
}


