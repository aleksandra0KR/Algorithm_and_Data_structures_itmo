#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct Node {
    int x = 0;
    int y = 0;

    Node(int x_, int y_) {
        x = x_;
        y = y_;
    }
};

class hash_table_with_open_adressing {
public:
    vector<Node*> arr;
    int size = 5000;

    hash_table_with_open_adressing(int s) {
        size = s;
        for (int i = 0; i < size; i++) {
            arr.push_back(nullptr);
        }
    }

    int hash_fuction(int k) {
        return abs(k * 9123) % size;
    }

    void insert(int x, int y) {

        int hashx = hash_fuction(x);

        if (arr[hashx] == nullptr) {
            arr[hashx] = new Node(x, y);
        }
        else {
            hashx++;
            hashx %= size;

            while (arr[hashx] != nullptr) {
                hashx++;
                hashx %= size;
            }

            if (arr[hashx] == nullptr) {
                arr[hashx] = new Node(x, y);
            }
        }

        int hashy = hash_fuction(y);

        if (arr[hashy] == nullptr) {
            arr[hashy] = new Node(x, y);;
        }
        else {
            hashy++;
            hashy %= size;

            while (arr[hashy] != nullptr) {
                hashy++;
                hashy %= size;
            }
            if (arr[hashy] == nullptr) {
                arr[hashy] = new Node(x, y);
            }
        }
    }

    bool get(int x, int y) {

        int hashx = hash_fuction(x);

        if (arr[hashx] != nullptr and (arr[hashx]->x == x)) return 1;
        while (arr[hashx] != nullptr) {

            hashx++;
            hashx %= size;

            if (arr[hashx] != nullptr and (arr[hashx]->x == x)) return 1;
        }

        int hashy = hash_fuction(y);

        if (arr[hashy] != nullptr and (arr[hashy]->y == y)) return 1;

        while (arr[hashy] != nullptr) {

            hashy++;
            hashy %= size;

            if (arr[hashy] != nullptr and (arr[hashy]->y == y)) return 1;
        }
        return 0;
    }

};


int main() {

    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int number_of_el;
    int mac = 0;
    int x_, y_;
    vector<std::pair<int, int>> all_;
    cin >> number_of_el;
    hash_table_with_open_adressing h = hash_table_with_open_adressing(50000);

    for (int i = 0; i < number_of_el; i++) {

        cin >> y_ >> x_;

        if (h.get(y_, x_) == 0) {
            h.insert(y_, x_);
            mac++;
        }
    }

    if (mac <= 3) cout << "YES";
    else cout << "NO";


    return 0;
}
