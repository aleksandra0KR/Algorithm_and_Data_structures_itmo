#include <iostream>
#include <vector>
using  std::cin;
using  std::cout;
using  std::vector;

struct Node{
    int isu = -1;
    int score = -1;
    Node(int k, int v){
        isu = k;
        score = v;
    }
    Node() = default;
};

class hash_table_with_open_adressing{
public:
    vector<Node> arr;
    int size = 500;

    hash_table_with_open_adressing(){
        size = 500;
        for(int i = 0; i < size; i++){
            arr.push_back(Node());
        }
    }

    int hash_fuction(int key){
        const int k = 123;

        return abs((key + 78) * k)  % size;
    }

    void insert(int isu, int score){
        int hash =  hash_fuction(isu);

        if (arr[hash].isu == -1 or arr[hash].isu == -2) {
            arr[hash].isu = isu;
            arr[hash].score = score;
            return;
        }

        hash++;
        hash %= size;

        while (arr[hash].isu != -1 and arr[hash].isu != -2 ) {
            hash++;
            hash %= size;
        }

        if (arr[hash].isu == -1 or arr[hash].isu == -2) {
            arr[hash].isu = isu;
            arr[hash].score = score;
            return;
        }
    }

    void delete_val(int k)
    {
        int hash = hash_fuction(k);

        if (arr[hash].isu == k) arr[hash].isu = -2;

        while (arr[hash].isu != -1) {

            hash++;
            hash%=size;

            if (arr[hash].isu == k) arr[hash].isu = -2;
        }
    }

    int average(){

        int people = 0;
        int summa = 0;

        for(int i = 0; i < size; i++){
            if(arr[i].isu != -1 and arr[i].isu != -2 ){
                people++;
                summa+= arr[i].score;
            }
        }

        if(people == 0) return 0;
        return summa/people;
    }

    int maximum(){

        int max_val = 0;

        for(int i = 0; i < size; i++){
            if(arr[i].isu != -1 and arr[i].isu != -2 ){
                max_val =(max_val > arr[i].score ? max_val : arr[i].score);
            }
        }

        return max_val;
    }
};


class hash_table{
public:

    vector<hash_table_with_open_adressing*> arr;
    int size;

    hash_table(int s){
        size = s;
        for(int i = 0; i < s; i++){
            arr.push_back( nullptr);
        }
    }

    int hash_fuction(int key){
        const int k = 7;

        return abs(key * k)  % size;
    }

    void insert(int group, int isu, int score){
        int hash =  hash_fuction(group);

        if (arr[hash] == nullptr) {
            hash_table_with_open_adressing* h = new hash_table_with_open_adressing();
            arr[hash] = h;
            arr[hash]->insert(isu, score);
            return;
        }

        else{
            arr[hash]->insert(isu, score);
            return;
        }
    }

    void delete_val(int group, int isu)
    {
        int hash = hash_fuction(group);

        arr[hash]->delete_val(isu);

    }

    int average(int group){
        int hash = hash_fuction(group);

        return arr[hash]->average();
    }

    int maximum(int group){
        int hash = hash_fuction(group);

        return arr[hash]->maximum();
    }
};


int main()
{
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int number_of_grops, number_of_commands;
    std::string command;
    int group, isu, score;
    cin >> number_of_grops >> number_of_commands;
    hash_table h =  hash_table(number_of_grops * 7);

    for(int i = 0; i < number_of_commands; i++){

        cin >> command;

        if(command == "+"){
            cin >>  group >> isu >> score;
            h.insert(group, isu,score);
        }

        else if(command == "m"){
            cin >> group;
            cout << h.maximum(group) << '\n';
        }

        else if(command == "a"){
            cin >> group;
            cout << h.average(group) << '\n';
        }

        else if(command == "-"){
            cin >> group >> isu;
            h.delete_val(group,isu) ;
        }
    }

    return 0;
}