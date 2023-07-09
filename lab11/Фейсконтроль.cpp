#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;

struct edge {
    int start, end, worth;
    edge(int s, int e, int w){
        start = s;
        end = e;
        worth = w;
    }
};

void ford(vector<edge>& incident, vector<int>& dist, vector<int>& parents, int n, int m, int K) {

    int x = -1;
    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        bool change = false;
        for (int j = 0; j < m; j++){
            if (dist[incident[j].start] + incident[j].worth < dist[incident[j].end]) {
                dist[incident[j].end] = dist[incident[j].start] + incident[j].worth;
                parents[incident[j].end] = incident[j].start;
                change = true;
                x = incident[j].end;
            }
        }
        if (!change) {
            cout <<  "YES\n";
            return;
        }
    }

    int start = x;
    for (int i=0; i < n; i++)
        start = parents[start];

    int cnt = 0;
    int cur=start;
    while(cur != start or cnt == 0){
        cnt++;
        cur=parents[cur];
    }
    cnt++;
    if (cnt <= K) cout << "YES\n";
    else cout << "NO\n";
    return;

}

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    for(int e = 0; e < N; e++) {

        int n, m;
        int start, end, worth;

        cin >> n >> m;
        vector<edge> incident;
        vector<int> parents(n, -1);
        vector<int> dist(n, 1000000000);

        for (int r = 0; r < m; r++) {
            cin >> start >> end >> worth;
            incident.push_back(edge(start - 1, end - 1, worth));
            parents[end - 1] = start - 1;
        }


        ford(incident, dist, parents, n, m, K);


    }
    return 0;
}
