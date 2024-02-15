#include <iostream>
#include <vector>
int it = 1;
int **arr;
struct Node{
    int data;
    int hight;
    int pos;
    int balance;
    Node *leftchild,*rightchild;
    Node(int val){
        leftchild = nullptr;
        rightchild = nullptr;
        data = val;
        hight = 0;
        pos = 0;
        balance = 0;
    }
};

void fixheight(Node* root)
{
    int lefthight = 0;
    int rightheight = 0;
    if (root->leftchild!=NULL){
        lefthight = root->leftchild->hight;
    }
    if (root->rightchild!=NULL){
        rightheight = root->rightchild->hight;
    }
    root->hight = (lefthight>rightheight?lefthight:rightheight)+1;
    root->balance = rightheight - lefthight;
}

Node* rotateright(Node* root)
{
    Node* temp = root->leftchild;
    root->leftchild = temp->rightchild;
    temp->rightchild = root;
    fixheight(root);
    fixheight(temp);
    return temp;
}

Node* rotateleft(Node* root)
{
    Node* temp = root->rightchild;
    root->rightchild = temp->leftchild;
    temp->leftchild = root;
    fixheight(root);
    fixheight(temp);
    return temp;
}

Node* balance(Node* root){
    if( root->rightchild->balance < 0 )
        root->rightchild = rotateright(root->rightchild);
    return rotateleft(root);}

Node * filltree(Node *root, int val, int pos){
    if (root == nullptr){
        root = new Node(val);}
    if (arr[pos][1] == 0 and arr[pos][2] == 0)  {
        root->hight = 1;
        root->balance = 0;
        return root;
    }
    else if (arr[pos][2]==0){
        root->leftchild = filltree(root->leftchild,arr[arr[pos][1]-1][0],  arr[pos][1]-1);
        root->hight = root->leftchild->hight + 1;
        root->balance = 0 - root->leftchild->hight;
    }
    else if (arr[pos][1]==0){
        root->rightchild =filltree(root->rightchild,arr[arr[pos][2]-1][0], arr[pos][2]-1);
        root->hight = root->rightchild->hight + 1;
        root->balance = root->rightchild->hight;
    }
    else{
        root->leftchild = filltree(root->leftchild,arr[arr[pos][1]-1][0],  arr[pos][1]-1);
        root->rightchild =filltree(root->rightchild,arr[arr[pos][2]-1][0], arr[pos][2]-1);
        root->hight = (root->leftchild->hight > root->rightchild->hight ? root->leftchild->hight:root->rightchild->hight) + 1;
        root->balance = root->rightchild->hight - root->leftchild->hight;
    }
    return root;
}


void position(Node* root){
    if (root == nullptr) return;
    else{
        root->pos = it;
        it++;
        position(root->leftchild);
        position(root->rightchild);
        return;
    }}

void printavl(Node* root){
    if (root == nullptr) return;
    if(root->leftchild == nullptr && root->rightchild == nullptr){
        std::cout << root->data << " " << 0 << " " << 0 << "\n";}
    else if (root->rightchild == nullptr){
        std::cout << root->data << " " << root->leftchild->pos << " " << 0 << "\n";
        printavl(root->leftchild);}
    else if (root->leftchild == nullptr){
        std::cout << root->data << " " << 0 << " " << root->rightchild->pos << "\n";
        printavl(root->rightchild);}
    else if (root->leftchild != nullptr && root->rightchild != nullptr){
        std::cout << root->data << " " << root->leftchild->pos << " " << root->rightchild->pos << "\n";
        printavl(root->leftchild);
        printavl(root->rightchild);
    }
    return;}




int main() {

    int numberofinputstrings;
    std::cin >> numberofinputstrings;

    Node *tree = nullptr;

    std::vector<int> result;
    for (int i = 0; i <numberofinputstrings; i++){
        result.push_back(0);
    }

    arr = (int**) malloc(numberofinputstrings*sizeof(int*));
    for (int i = 0; i < numberofinputstrings; i++ ){
        arr[i] = (int*) malloc(3*sizeof(int));
    }

    for (int i = 0; i < numberofinputstrings; i++) {
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
        std::cin >> arr[i][2];
    }

    if (numberofinputstrings == 1){
        std::cout << numberofinputstrings<< "\n";
        std::cout << arr[0][0] <<" ";
        std::cout << arr[0][1]<< " ";
        std::cout << arr[0][2];
        return 0;
    }

    tree = filltree(tree,arr[0][0],0);
    tree = balance(tree);

    std::cout << numberofinputstrings<< "\n";
    position(tree);
    printavl(tree);


    return 0;
}