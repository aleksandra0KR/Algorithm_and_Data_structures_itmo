#include <vector>
#include <iostream>
#include <cstring>
using std::vector;
using std::cout;
using std::cin;

struct Node{
    int data;
    int comp;
    char color;
    short int unsafe;
    Node(int num){
        data = num;
        color = 'W';
        unsafe = 0;
        comp = 0;
    }
};

void dfs(vector<vector<Node>>& list_of,int i, int component, vector<int>& unsafe, vector<int>& res, int position_res){
    list_of[i][0].color =  'G';
    list_of[i][0].comp = component;
    if (unsafe[i] == 1) res[position_res] = 1;
    if (unsafe[i] == 1) list_of[i][0].unsafe = 1;
    int pos;
    for(int j = 1; j < list_of[i].size(); j++){
        pos = list_of[i][j].data;
        if(list_of[pos][0].color == 'W'){
            dfs(list_of,pos, component, unsafe, res, position_res);
        }
    }

    list_of[i][0].color = 'B';
}

int main(){

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    vector<vector<Node>> list_of;
    for(int i = 0; i < n; i++){
        list_of.push_back({Node(i)});
    }

    int a,b;
    vector<int> unsafe;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        list_of[a-1].push_back({Node(b-1)});
        list_of[b-1].push_back({Node(a-1)});
    }

    for(int i = 0; i < n; i++){
        cin >> a;
        unsafe.push_back(a);
    }
    vector<int> res;
    int componenet = 0;
    int position_res = -1;
    for(int i = 0; i < n; i++){
        if(list_of[i][0].color == 'W'){
            componenet++;
            res.push_back(0);
            position_res++;
            dfs(list_of,i,componenet,unsafe, res,position_res);}
    }

    cout << componenet << "\n";


    for(int i = 0; i < n; i++){
        cout << list_of[i][0].comp << " ";
    }

    cout << "\n";
    for(auto u: res){
        cout << u << " ";
    }

    return 0;
}
