#include <iostream>
#include <vector>

std::vector<int> findLIS(std::vector<int> a, int n){
    int prev[n];
    int d[n];
    for (int i = 0; i<n; i++){
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++){
            if (a[j] < a[i] and d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    int lengh = d[0];
    for (int i = 0; i<n ; i++){
        if (d[i] > lengh){
            pos = i;
            lengh = d[i];
        }
    }
    std::vector<int> ans;
    while(pos != -1){
        ans.push_back(a[pos]);
        pos = prev[pos];
    }
    std::reverse(std::begin(ans),std::end(ans));
    return ans;
}
int main(){
    int number;
    std::cin >> number;
    std::vector<int> arr;
    std::vector<int> ans;
    int num;
    for (int i = 0; i< number;i++){
        std::cin >> num;
        arr.push_back(num);
    }
    ans = findLIS(arr,number);
    std::cout << ans.size() << "\n";
    for (int i = 0; i< ans.size();i++){
        std::cout << ans[i] << " ";
    }
    return 0;
}