#include <vector>
#include <iostream>
#include <stack>
using std::stack;
using std::vector;
using std::cin;
using std::cout;


struct Node{
    int data;
    int comp;
    char color;
    Node(int number){
        data = number;
        color = 'W';
        comp = 0;
    }
};

void dfs_G(vector<vector<Node>>& list_of, int i, stack<int>& st){
    list_of[i][0].color = 'B';

    for(int j = 1; j < list_of[i].size(); j++){
        int pos = list_of[i][j].data;
        if(list_of[pos][0].color == 'W'){
            dfs_G(list_of,pos,st);
        }
    }

    st.push(list_of[i][0].data);
}

void dfs_H(vector<vector<Node>>& list_of, int i, int counter){
    list_of[i][0].comp = counter;

    for(int j = 1; j < list_of[i].size(); j++){
        int pos = list_of[i][j].data;
        if(list_of[pos][0].comp == 0){
            dfs_H(list_of,pos, counter);
        }
    }
}

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<Node>> list_of;
    vector<vector<Node>> list_of_H;

    for(int i = 0; i < n; i++){
        list_of.push_back({Node(i)});
        list_of_H.push_back({Node(i)});
    }

    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        list_of[a-1].push_back(Node(b-1));
        list_of_H[b-1].push_back(Node(a-1));
    }

    stack<int> st;
    for(int i = 0; i < n; i++){
        if(list_of[i][0].color == 'W'){
            dfs_G(list_of,i,st);
        }
    }

    int count = 1;
    int pos;
    while(!st.empty()){
        pos = st.top();
        st.pop();
        if(list_of_H[pos][0].comp == 0){
            dfs_H(list_of_H,pos, count);
            count++;
        }
    }

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout <<((list_of_H[a-1][0].comp == list_of_H[b-1][0].comp) ? "YES\n" : "NO\n");
    }

    return 0;
}
