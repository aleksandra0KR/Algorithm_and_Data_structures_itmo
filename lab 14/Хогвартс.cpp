#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;



int main(){


    int firstpos, secondpos, lengh, req;
    int first, second;
    cin >> lengh >> req;

    string str;
    cin >> str;
    int res = 0;

    for(int t = 0; t < req; t++) {
        bool flag = 1;
        cin >> firstpos >> secondpos >> lengh;
        for(int i = 0; i < lengh; i++){
            if(str[firstpos+i - 1] != str[secondpos+i -1]) flag = 0;
        }
        res+=flag;
    }
    cout << res;

    return 0;
}