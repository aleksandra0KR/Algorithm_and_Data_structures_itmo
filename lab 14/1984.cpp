#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;



int main(){

    string poem, name;
    cin >> poem >> name;

    string connected = name + '#' + poem;
    int size_of_connected = connected.size();

    vector<int> z(size_of_connected, 0);
    int left = 0;
    int right = 0;

    for (int i = 1; i < size_of_connected; i++){
        if (i <= right){
            z[i] = std::min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < size_of_connected and connected[z[i]] == connected[z[i] + i]) {
            z[i]++;
        }
        if (i + z[i] - 1 > right){
            left = i;
            right = i + z[i] - 1;
        }
    }

    vector<int> ans;
    for(int i = name.size(); i < z.size(); i++){
        if(z[i] == name.size()){
            ans.push_back(i - name.size() - 1);
        }
    }

    cout << ans.size() << '\n';
    for (auto n : ans){
        cout << n << " ";
    }
    return 0;
}