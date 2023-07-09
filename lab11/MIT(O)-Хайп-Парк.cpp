#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;


void floyd( int n, vector<vector<int>>& dist){

    for(int i = 0; i < n; i++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if ( dist[u][i] + dist[i][v] < dist[u][v]){
                    dist[u][v] = dist[u][i] + dist[i][v];}
            }
        }
    }
    return;
}

int main(){

    int n,m;
    int start, end, worth;

    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 1000000000));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) graph[i][i] = 0;
        }

    }

    for(int r = 0; r < m; r++){
        cin >> start >> end >> worth;
        graph[start-1][end-1] = worth;
        graph[end-1][start-1] = worth;
    }


    floyd(n, graph);
    int mac = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] > mac and graph[i][j] != 1000000000) mac = graph[i][j];
        }
    }
    cout << mac;

    return 0;
}
