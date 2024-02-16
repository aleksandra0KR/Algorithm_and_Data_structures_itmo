#include <iostream>
#include <vector>
#include <queue>
using  std::cin;
using  std::cout;
using  std::vector;
using  std::string;
using  std::queue;

void bfs(vector<string>& all_symbols, vector<vector<bool>>& visited, int parenti,int parentj,  int m, int n){

    visited[parenti][parentj] = true;
    queue<vector<int>> Q;
    Q.push({parenti,parentj});
    while(!Q.empty()){
        vector<int> v = Q.front();
        Q.pop();
        int row = v[0];
        int column = v[1];

        int neibori =  1;
        int nrow = row + neibori;
        int ncolumn = column;
        if(( n > nrow and  nrow > -1 ) and ( m > ncolumn and ncolumn > -1) and all_symbols[nrow][ncolumn] == '.' and visited[nrow][ncolumn] == false){
            visited[nrow][ncolumn] = true;
            Q.push({nrow,ncolumn});}

        neibori =  -1;
        nrow = row + neibori;
        ncolumn = column;
        if(( n > nrow and  nrow > -1 ) and ( m > ncolumn and ncolumn > -1) and all_symbols[nrow][ncolumn] == '.' and visited[nrow][ncolumn] == false){
            visited[nrow][ncolumn] = true;
            Q.push({nrow,ncolumn});}

        int neiborj = 1;
        nrow = row;
        ncolumn = column + neiborj;
        if(( n > nrow and  nrow > -1 ) and ( m > ncolumn and ncolumn > -1) and all_symbols[nrow][ncolumn] == '.' and visited[nrow][ncolumn] == false){
            visited[nrow][ncolumn] = true;
            Q.push({nrow,ncolumn});}

        neiborj = -1;
        nrow = row;
        ncolumn = column + neiborj;
        if(( n > nrow and  nrow > -1 ) and ( m > ncolumn and ncolumn > -1) and all_symbols[nrow][ncolumn] == '.' and visited[nrow][ncolumn] == false){
            visited[nrow][ncolumn] = true;
            Q.push({nrow,ncolumn});}

    }

}

int main() {

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> all_symbols;
    string str_of_symbols;
    int counter = 0;
    vector<vector<bool>> visited;

    for(int i = 0; i < n; i++){
        visited.push_back({});
        for(int j = 0; j < m; j++) {
            visited[i].push_back(false);
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> str_of_symbols;
        all_symbols.push_back(str_of_symbols);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(all_symbols[i][j] == '.' and visited[i][j] == false){

                bfs(all_symbols,visited, i,j, m,n);
                counter++;

            }
        }
    }
    std::cout << counter;
    return 0;
}