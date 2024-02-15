#include <iostream>

int **arr;
int it = 1;

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
        hight = 1;
        pos = 0;
        balance = 0;
    }
};

void fixheight(Node* p)
{
    int lefthight = 0;
    if (p->leftchild!=NULL){
        lefthight = p->leftchild->hight;
    }
    int rightheight = 0;
    if (p->rightchild!=NULL){
        rightheight = p->rightchild->hight;
    }

    p->hight = (lefthight>rightheight?lefthight:rightheight)+1;
    p->balance = rightheight - lefthight;
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

Node* balance(Node* p)
{
    fixheight(p);
    if( p->balance==2 )
    {
        if( p->rightchild->balance < 0 )
            p->rightchild = rotateright(p->rightchild);
        return rotateleft(p);
    }
    if( p->balance==-2 )
    {
        if( p->leftchild->balance > 0  )
            p->leftchild = rotateleft(p->leftchild);
        return rotateright(p);
    }
    return p;
}

Node* insert(Node* p, int k)
{
    if( !p ) return new Node(k);
    if( k<p->data )
        p->leftchild = insert(p->leftchild,k);
    else
        p->rightchild = insert(p->rightchild,k);
    return balance(p);
}

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


int main(){

    int numberofinputstrings;
    std::cin >> numberofinputstrings;

    arr = (int**) malloc(numberofinputstrings*sizeof(int*));
    for (int i = 0; i < numberofinputstrings; i++ ){
        arr[i] = (int*) malloc(3*sizeof(int));
    }

    for (int i = 0; i < numberofinputstrings ; i++) {
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
        std::cin >> arr[i][2];
    }
    int numberforinsert;
    std::cin >> numberforinsert;
    Node *tree = nullptr;
    if (numberofinputstrings == 0){
        std:: cout << 1<< "\n" << numberforinsert << " " << 0 << " " << 0 << " ";
        return 0;
    }

    tree = filltree(tree,arr[0][0],0);

    tree = insert(tree,numberforinsert);

    std::cout << numberofinputstrings + 1 << "\n";
    position(tree);
    printavl(tree);

    return 0;
}