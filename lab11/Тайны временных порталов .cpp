#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;

void floyd( int n, vector<vector<int>>& dist, int k){

    for(int i = 0; i < n; i++){
        for(int u = 0; u < n; u++){
            if(abs(u-i) > k) continue;
            for(int v = 0; v < n; v++){
                if (abs(v-i) <= k and dist[u][i] + dist[i][v] < dist[u][v]){
                    dist[u][v] = dist[u][i] + dist[i][v];
                }
            }
        }
    }

}

int main(){

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n,m,k;
    cin >> n >> m >> k;

    int start, end, worth;

    vector<vector<int>> dist(n, vector<int>(n, 1000000000));


    for (int r = 0; r < m; r++) {
        cin >> start >> end >> worth;
        dist[start - 1][end - 1] = worth;
    }
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
    }

    int q;
    cin >> q;
    floyd(n, dist, k);
    for(int i = 0; i < q; i++){
        cin >> start >> end;
        cout << (dist[start-1][end - 1] != 1000000000 ? dist[start-1][end - 1] : -1) << '\n';
    }


    return 0;
}