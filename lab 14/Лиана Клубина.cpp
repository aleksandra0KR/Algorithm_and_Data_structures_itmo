#include <iostream>
#include <vector>
using std::string;
using std::cin;
using std::vector;
using std::cout;

vector<int> prev(string str){
    int j = 0;
    int n = str.length();
    vector<int> pr (n);

    for (int i = 1; i < n; i++) {
        j = pr[i-1];
        while (j > 0 and str[i] != str[j]) {
            j = pr[j - 1];
        }
        if (str[i] == str[j])  j++;
        pr[i] = j;
    }
    return pr;
}

int main() {

    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    vector<int> res = prev(str);

    for(auto s: res){
        cout << s << " ";
    }
}