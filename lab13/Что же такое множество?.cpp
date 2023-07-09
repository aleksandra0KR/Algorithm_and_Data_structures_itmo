#include <iostream>
#include <math.h>
#include <vector>
using std::cin;
using std::cout;
using std::vector;


int main(){
    int number_of_numbers;
    cin >> number_of_numbers;

    vector<int> first_numbers(number_of_numbers);
    for(int i = 0; i < number_of_numbers; i++){
        cin >> first_numbers[i];
    }
    std::sort(first_numbers.begin(), first_numbers.end());

    vector<int> second_numbers(number_of_numbers);
    for(int i = 0; i < number_of_numbers; i++){
        cin >> second_numbers[i];
    }
    std::sort(second_numbers.begin(), second_numbers.end());


    const int k = 30, mod = pow(2,31)-1;

    long long hesh1 = 0;
    int alf1 = 1;
    for (int x: first_numbers) {
        hesh1 = (hesh1 + alf1 * x) % mod;
        alf1 = (alf1 * k) % mod;
    }

    long long hesh2 = 0;
    int alf2 = 1;
    for (int x: second_numbers) {
        hesh2 = (hesh2 + alf2 * x) % mod;
        alf2 = (alf2 * k) % mod;
    }

    if(hesh1 == hesh2) cout << "YES";
    else cout << "NO";
    return 0;
}
