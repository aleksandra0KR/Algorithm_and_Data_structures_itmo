#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {

    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int n, m,q;
    cin >> n >> m;
    vector<vector<int>> all_(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> all_[i][j];
        }
    }

    cin >> q;
    int x1, y1, x2, y2, x3, x4, y3, y4;
    bool flag;
    int p,t, cnt;
    const int e = 15;
    for(int w = 0; w < q; w++){

        cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3 >> y4 >> x4;
        if(y1 == y3 and x1 == x3 and y2 == y4 and x2 == x4) {
            cout << "YES\n";
            continue;
        }

        flag = true;
        p = 0;
        t = 0;
        cnt = x1;

        for (int i = y3 - 1; i < y4; i++) {
            for(int j = x3 - 1; j < x4; j++){

                p = (e * p + all_[i][j]) % 8966;
                t = (e * t + all_[y1 - 1][x1 - 1]) % 8966;
                x1++;

                if (p!=t){
                    cout << "NO\n";
                    flag = false;
                    break;
                }
            }

            if(!flag) break;
            x1 = cnt;
            y1++;
        }

        if (flag) cout << "YES\n";
    }

}

/*
 4 3
1 1 1
2 2 2
1 2 2
2 2 2
1
2 1 2 3 4 1 4 3
 */