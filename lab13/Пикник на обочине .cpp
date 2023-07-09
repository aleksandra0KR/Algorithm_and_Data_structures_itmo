#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::min;
using std::max;

struct Node {

    unsigned int val = 1;
    int number_of_numbers = 0;
    int diff = 0;

    Node(int n, int nn, int d) {
        val = n;
        number_of_numbers = nn;
        diff = d;
    }
    Node() = default;
};


unsigned int hash_function(unsigned int &helper1, unsigned int &helper2, unsigned int &helper3, unsigned int &helper4, int mic, int mac, int now) {

    unsigned int hash;
    now = (now ^ (now >> 3) ^ (now << 9)) * UINT64_C(0x319642b2d24d8ec3);
    now = (now ^ (now >> 10) ^ (now >> 5)) * UINT64_C(0x96de1b173f119089);
    now = now ^ (now >> 20) ^ (now << 11);
    helper1 *= now;
    helper2 *= now;
    helper3 += now;
    helper4 ^= now;
    hash = (helper1 ^ helper2 ^ helper3 ^ helper4 ^ mac ^ mic);
    return hash;
}

class hash_table_with_open_adressing {
public:

    vector<Node*> arr;
    int size = 50000;

    hash_table_with_open_adressing(int s) {
        size = s;
        for (int i = 0; i < size; i++) {
            arr.push_back(nullptr);
        }
    }

    void insert(unsigned int hash, int n, int diff) {

        unsigned int pos = hash % 7034567;

        if (arr[pos] == nullptr) {
            arr[pos] = new Node(hash, n, diff);
            return;
        }

        pos++;
        pos %= size;

        while (arr[pos] != nullptr) {
            pos++;
            pos %= size;
        }

        if (arr[pos] == nullptr) {
            arr[pos] = new Node(hash, n, diff);
            return;
        }
    }

    int get(unsigned int hash, int number_of_el, int diff) {

        unsigned int pos = hash % 7034567;
        int counter = 0;

        if (arr[pos] != nullptr and arr[pos]->val == hash and arr[pos]->number_of_numbers == number_of_el and arr[pos]->diff == diff) {
            return arr[pos]->number_of_numbers;
        }

        while (arr[pos] != nullptr) {

            counter++;
            if (counter >= size) return -1;

            pos++;
            pos %= size;

            if (arr[pos] != nullptr and arr[pos]->val == hash and arr[pos]->number_of_numbers == number_of_el and arr[pos]->diff == diff) {
                return arr[pos]->number_of_numbers;
            }
        }
        return -1;
    }
};


int main() {

    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int number_of_el_of_the_first, number_of_el_of_the_second;


    int val;
    int counter;
    vector<int> all_1;
    vector<int> all_2;
    hash_table_with_open_adressing first(7034567);

    cin >> number_of_el_of_the_first;
    for (int i = 0; i < number_of_el_of_the_first; i++) {
        cin >> val;
        all_1.push_back(val);
    }

    cin >> number_of_el_of_the_second;
    for (int i = 0; i < number_of_el_of_the_second; i++) {
        cin >> val;
        all_2.push_back(val);
    }

    unsigned int hash;
    int mic;
    int mac;
    unsigned int helper1;
    unsigned int helper2;
    unsigned int helper3;
    unsigned int helper4;


    for (int i = 0; i < number_of_el_of_the_first; i++) {

        helper1 = 512232;
        helper2 = 42338;
        helper3 = 5641273;
        helper4 = 112212;
        counter = 1;
        mic = all_1[i];
        mac = all_1[i];
        hash = hash_function(helper1, helper2, helper3, helper4, mic, mac, all_1[i]);
        first.insert(hash, counter, mac - mic);

        for (int j = i + 1; j < number_of_el_of_the_first; j++) {
            counter++;
            mic = min(all_1[j], mic);
            mac = max(all_1[j], mac);
            hash = hash_function(helper1, helper2, helper3, helper4, mic, mac, all_1[j]);
            first.insert(hash, counter, mac - mic);
        }
    }

    int res = 0;
    int lengh;

    for (int i = 0; i < number_of_el_of_the_second; i++) {

        counter = 1;
        mic = all_2[i];
        mac = all_2[i];
        helper1 = 512232;
        helper2 = 42338;
        helper3 = 5641273;
        helper4 = 112212;
        hash = hash_function(helper1, helper2, helper3, helper4, mic, mac, all_2[i]);
        lengh = first.get(hash, counter, mac - mic);

        if (lengh != -1) res = max(lengh, res);

        for (int j = i + 1; j < number_of_el_of_the_second; j++) {

            if (counter > number_of_el_of_the_first) break;

            counter++;
            mic = min(all_2[j], mic);
            mac = max(all_2[j], mac);
            hash = hash_function(helper1, helper2, helper3, helper4, mic, mac, all_2[j]);
            lengh = first.get(hash, counter, mac - mic);

            if (lengh != -1) res = max(lengh, res);

        }

    }

    cout << res;
    return 0;
}
