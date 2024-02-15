#include <iostream>

struct Node{
    int data;
    int hight;
    int balance;
    Node *leftchild,*rightchild;
    Node(int val){
        leftchild = nullptr;
        rightchild = nullptr;
        data = val;
        hight = 1;
        balance = 0;
    }
};

struct Node *exists(Node* root, int val){
    if (root == nullptr){
        return nullptr;
    }
    if (root->data == val){
        return root;
    }
    else{
        if (root->data < val){
            return exists(root->rightchild, val);
        }
        else{
            return exists( root->leftchild, val);
        }
    }
}

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
    root->balance =  rightheight - lefthight ;
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
Node* balance(Node* root)
{
    fixheight(root);
    if( root->balance == 2 )
    {
        if( root->rightchild->balance < 0 )
            root->rightchild = rotateright(root->rightchild);
        return rotateleft(root);
    }
    if( root->balance == -2 )
    {
        if( root->leftchild->balance  > 0  )
            root->leftchild = rotateleft(root->leftchild);
        return rotateright(root);
    }
    return root;
}
Node* insert(Node *root, int number){
    if (exists(root, number)) return root;
    if (root == nullptr){
        return new Node(number);
    }
    if( number<root->data )
        root->leftchild = insert(root->leftchild,number);
    else
        root->rightchild = insert(root->rightchild, number);
    return balance(root);
}

Node* searchmin(Node* root){
    if (root->leftchild == nullptr)
        return root;
    return  searchmin(root->leftchild);
}

Node* searchmax(Node* root){
    if (root->rightchild == nullptr)
        return root;
    return  searchmax(root->rightchild);
}

Node* deletemin(Node* root)
{
    if( root->leftchild==0 )
        return root->rightchild;
    root->leftchild = deletemin(root->leftchild);
    return balance(root);
}

Node* deletemax(Node* root)
{
    if( root->rightchild==0 )
        return root->leftchild;
    root->rightchild = deletemax(root->rightchild);
    return balance(root);
}
Node* deleteel(Node* root, int number)
{
    if( number < root->data )
        root->leftchild = deleteel(root->leftchild,number);
    else if( number > root->data )
        root->rightchild = deleteel(root->rightchild,number);
    else
    {
        if (root->leftchild == nullptr and root->rightchild == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->leftchild == nullptr) {
            Node* temp = root->rightchild;
            delete root;
            root =temp;
            return (balance(root));
        }
        if (root->rightchild == nullptr) {
            Node* temp = root->leftchild;
            delete root;
            root =temp;
            return (balance(root));
        }
        Node* y = root->leftchild;
        Node* z = root->rightchild;
        delete root;
        Node* max = searchmax(y);
        max->leftchild = deletemax(y);
        max->rightchild = z;

        return balance(max);
    }
    return balance(root);
}

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int numberofstrings;
    char command;
    int number;
    Node *tree = nullptr;
    std::cin >> numberofstrings;
    for (int i = 0; i< numberofstrings; i++){
        std::cin >> command;
        if (command == 'A'){
            std:: cin >> number;
            tree = insert(tree,number);
            std:: cout << tree->balance << "\n";
        }
        else if(command == 'D'){
            std:: cin >> number;
            if (tree == nullptr){
                std:: cout << 0 << "\n";
            }
            else{
                if (!exists(tree,number)){
                    std:: cout << tree->balance << "\n";
                }
                else{
                    tree = deleteel(tree,number);
                    if (tree == nullptr) std:: cout << 0 << "\n";
                    else std:: cout << tree->balance << "\n";}}
        }
        else if(command == 'C'){
            std:: cin >> number;
            if(exists(tree,number)!= nullptr){
                std::cout << "Y" << "\n";
            }
            else{
                std::cout << "N" << "\n";
            }
        }
    }
    return 0;
}

