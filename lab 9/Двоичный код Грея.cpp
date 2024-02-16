#include <iostream>
#include <cmath>

void grey_code(int n){
    int amout_of_cods = pow(2,n);
    std::string res;
    int code;

    for(int i = 0; i < amout_of_cods; i++){

        res = "";
        code = (i ^ (i >> 1));

        while(code > 0){
            res += (code % 2) == 1 ? '1' : '0';
            code/=2;
        }

        if(res.length() < n){
            for(int j = 0; j < n- res.length(); j++){
                std::cout << '0';
            }
        }

        std::reverse(res.begin(), res.end());
        std::cout << res << "\n";

    }
}

int main(){
    int number;
    std::cin >> number;
    grey_code(number);
    return 0;
}