#include <iostream>
#include <vector>
int res = 0;
struct Node
{
    std::string name;
    int uniclleters;
    int balance;
    int hight;
    Node *leftchild,*rightchild;
    Node(std::string nameoffile) {
        leftchild = nullptr;
        balance = 0;
        hight = 1;
        uniclleters = 0;
        rightchild = nullptr;
        name = nameoffile;
    }
};

int unicletters(std::string str){
    int counter = 0;
    std::vector <char> unicvector;
    for (int i = 0; i< str.length(); i++){
        if (std::count(unicvector.begin(), unicvector.end(), str[i])){
            continue;
        }
        else{
            unicvector.push_back(str[i]);
            counter++;
        }
    }
    return counter;


}
void fixheight(Node* root)
{
    if (root == nullptr) return;
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
    if (root == nullptr) return root;
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



struct Node *exists(Node* root, std::string name){
    if (root == nullptr){
        root =  new Node(name);
        root->uniclleters = (unicletters(name));
        root->hight = 1;
        root->balance = 0;
        return balance(root);
    }
    else if ( name == root -> name){
        res+= root->uniclleters;
        return root;
    }
    else{
        if (root -> name < name){
            root ->rightchild =  exists( root ->rightchild, name);
            root->hight = root->rightchild->hight + 1;
            if (root->leftchild!= nullptr) (root)->balance = (root)->rightchild->hight - (root)->leftchild->hight;
            else (root)->balance = 0 - (root)->rightchild->hight;
            return balance(root);
        }
        else{
            (root)->leftchild =  exists( root ->leftchild, name);
            (root)->hight = (root)->leftchild->hight + 1;
            if ((root)->rightchild!= nullptr) (root)->balance = (root)->rightchild->hight - (root)->leftchild->hight;
            else (root)->balance =(root)->leftchild->hight;
            return balance(root);
        }
    }
};

int main(){
    int numberofel;
    std::cin >> numberofel;
    std::string nameofafile = "";
    Node* root = nullptr;
    std::string name;
    for (int i = 0; i< numberofel ;i++){
        std::cin >> nameofafile;
        root = exists(root,nameofafile);

    }
    std::cout << res;
    return 0;

}