#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;


int main(){

    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int number_of_cards;
    int number;
    cin >> number_of_cards >> number;

    vector<int> all_(number_of_cards);


    for(int i = 0; i < number_of_cards; i++){
        cin >> all_[i];
    }
    bool flag;
    int cnt;
    std::reverse(all_.begin(), all_.end());
    for(int i = number_of_cards/2; i < number_of_cards; i++){
        flag = 1;
        cnt = 1;
        for(int j = i; j < number_of_cards; j++ ){
            if(all_[i - cnt]!=all_[j]) {
                flag = 0;
                break;
            }
            cnt++;
        }
        if (flag) cout << i << ' ';
    }

    cout<< number_of_cards;
    return 0;

}
