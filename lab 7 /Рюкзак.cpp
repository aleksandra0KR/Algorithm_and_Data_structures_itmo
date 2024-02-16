#include <iostream>

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    int s;
    int n;
    std::cin >> s;
    std::cin >> n;
    int num;
    int weights[n];

    for (int i = 0; i<n; i++){
        std::cin >> num;
        weights[i] = num;
    }
    int** resarr = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        resarr[i] = new int[s + 1];
    }

    for (int i = 0; i <n+1;i++){
        for (int j = 0; j <s+1;j++){
            if (i == 0 || j == 0) resarr[i][j] = 0;
            else{
                if (j>=weights[i-1]){
                    resarr[i][j] = max(resarr[i-1][j], resarr[i-1][j-weights[i-1]]+weights[i-1]);
                }
                else resarr[i][j] = resarr[i-1][j];}
        }
    }
    std::cout << resarr[n][s];
    return 0;
}