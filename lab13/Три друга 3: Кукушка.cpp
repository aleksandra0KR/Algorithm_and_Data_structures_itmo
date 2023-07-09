#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;

class cuckoo_hashing{
private:
    int size_of_the_table = 5000;

    struct Node{
        string name = "None";
        vector<int> points = {0,0,0};
        Node(string n){
            name = n;
        }
        Node() = default;
    };

    vector<Node*> hesh_table;

public:

    cuckoo_hashing(int s){

        size_of_the_table = s;
        for(int i = 0; i < s; i++){
            hesh_table.push_back(nullptr);
        }
    }

    unsigned int const hash1(const string &str)  {

        unsigned int hash1 = 0;
        for (char s : str) {
            hash1 = (2713 * hash1 + s) % 2147483646;
        }
        return hash1 % size_of_the_table;
    }

    unsigned int const hash2(const string &str)  {

        unsigned int hash2 = 0;
        for (char s : str) {
            hash2 = ( hash2 * 27627 + s ) % 2147483646;
        }
        return hash2 % (size_of_the_table - 2) + 2;
    }

    void add(const string& str,  int& person){

        unsigned int hesh1_pos = hash1(str);
        unsigned int hesh2_pos = hash2(str);

        if(hesh_table[hesh1_pos]!= nullptr and hesh_table[hesh1_pos]->name == str){
            hesh_table[hesh1_pos]->points[person]++;
            return;
        }
        else if(hesh_table[hesh2_pos ]!= nullptr and hesh_table[hesh2_pos]->name == str){
            hesh_table[hesh2_pos]->points[person]++;
            return;
        }
        if(hesh_table[hesh1_pos] == nullptr){
            hesh_table[hesh1_pos ] = new Node(str);
            hesh_table[hesh1_pos ]->points[person]++;
            return;
        }
        else if(hesh_table[hesh2_pos] == nullptr){
            hesh_table[hesh2_pos ] = new Node(str);
            hesh_table[hesh2_pos ]->points[person]++;
            return;
        }
        else{
            int counter = 0;
            string temp = str;
            while(counter < size_of_the_table){
                counter++;
                hesh1_pos = hash1(temp);
                hesh2_pos = hash2(temp);
                if(hesh_table[hesh1_pos] == nullptr){
                    hesh_table[hesh1_pos ] = new Node(str);
                    hesh_table[hesh1_pos ]->points[person]++;
                    return;
                }
                else if(hesh_table[hesh2_pos] == nullptr){
                    hesh_table[hesh2_pos ] = new Node(str);
                    hesh_table[hesh2_pos ]->points[person]++;
                    return;
                }
                else{
                    temp = hesh_table[hesh2_pos]->name;
                    hesh_table[hesh2_pos]->name = str;
                }
                if (counter > size_of_the_table / 2 ){
                    rehash();
                }
            }
            return;
        }
    }

    void rehash(){

        size_of_the_table *= 2;

        Node* temp;

        for(int i = 0; i < size_of_the_table; size_of_the_table++){
            if (hesh_table[i] != nullptr) {
                temp = hesh_table[i];
                hesh_table[i] = nullptr;
                for(int j = 0; j < 3; j++) {
                    if (temp[i].points[j] != 0) add(temp[i].name, j);
                }
            }
        }
        delete temp;
    }

    Node* operator[](int t){
        return hesh_table[t];
    }
};


int amout_of_scores(cuckoo_hashing& hesh_table, int& pos){
    int cnt = 0;
    for(auto s:hesh_table[pos]->points ) cnt += s!=0;
    switch (cnt) {
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 0;
    }
}




int main()
{
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int amout_of_people;
    string str;
    cin >> amout_of_people;
    const int size = 100000 * 30;
    cuckoo_hashing hash_table = cuckoo_hashing(size);


    for(int i = 0; i < 3; i++){
        for( int j = 0; j < amout_of_people; j++){
            cin >> str;
            hash_table.add(str, i);
        }
    }

    int score1 = 0;
    int score2 = 0;
    int score3 = 0;
    int score;

    for( int i = 0; i < size ; i++) {

        if (hash_table[i] != nullptr) {

            score = amout_of_scores(hash_table, i);
            if (hash_table[i]->points[0] != 0) score1 += score;
            if (hash_table[i]->points[1] != 0) score2 += score;
            if (hash_table[i]->points[2] != 0) score3 += score;
        }
    }

    cout << score1  << " " << score2  << " " << score3 ;
    return 0;
}
