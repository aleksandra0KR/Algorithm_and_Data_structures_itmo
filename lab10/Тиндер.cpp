#include <vector>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;

void dfs(unordered_map<int, vector<int>>& list_of, vector<char>& colors, int i){
    colors[i] = 'G';
    for(int j = 0; j < list_of[i].size(); j++){
        int pos = list_of[i][j];
        if(colors[pos] == 'W'){
            dfs(list_of,colors,pos);
        }
    }
    colors[i] = 'B';
}

int main(){
    
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n,m,q;
    cin >> n >> m >> q;
    unordered_map<int, vector<int>> list_;
    vector<char> colors;

    for(int i = 0; i < n; i++){
        list_.insert({i,{}});
        colors.push_back('W');
    }

    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        list_[a-1].push_back(b-1);
        list_[b-1].push_back(a-1);
    }

    char command;
    for(int i = 0; i < q; i++){
        cin >> command;
        cin >> a >> b;
        if(command == '?'){
            dfs(list_,colors,a-1);
            if (colors[b-1] != 'W') cout << "YES\n";
            else cout << "NO\n";
            for(int t = 0; t < n; t++){
                colors[t] = 'W';
            }
        }
        else{
            auto it = std::remove(list_[a-1].begin(), list_[a-1].end(),b-1);
            list_[a-1].erase(it, list_[a-1].end());
            it = std::remove(list_[b-1].begin(), list_[b-1].end(),a-1);
            list_[b-1].erase(it, list_[b-1].end());
        }
    }
    return 0;
}
