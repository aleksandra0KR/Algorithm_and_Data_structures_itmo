#include <iostream>
#include <vector>
using  std::cin;
using  std::cout;
using  std::vector;


class hash_table_with_open_adressing{
public:
    vector<int> arr;
    int size;

    hash_table_with_open_adressing(int s){
        size = s;
        for(int i = 0; i < s; i++){
            arr.push_back(-100000);
        }
    }

    int hash_fuction(int key){
        const int k = 11;

        return abs((key * k))  % size;
    }

    int insert(int k){
        int counter = 0;
        int hash =  hash_fuction(k);

        if (arr[hash] == -100000) {
            arr[hash] = k;
            return counter;
        }

        while (arr[hash] != -100000) {
            if(arr[hash] == k) counter++;
            hash++;
            hash %= size;
        }

        arr[hash] = k;
        return counter;

    }



};
int main()
{
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int number_of_elements;
    int value;
    cin >> number_of_elements;
    hash_table_with_open_adressing h =  hash_table_with_open_adressing(2 * number_of_elements );

    vector<int> all_;
    int counter = 0;

    for(int i = 0; i < number_of_elements; i++){
        cin >> value;
        counter += h.insert(value - i );
    }

    cout << counter;

    return 0;
}