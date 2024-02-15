#include <iostream>
#include <string>

struct Node
{
    std::string name;
    int times;
    int balance;
    int hight;
    int people[3]= {0,0,0}; ;
    Node *leftchild,*rightchild;
    Node(std::string nameoffile) {
        leftchild = nullptr;
        balance = 0;
        hight = 1;
        rightchild = nullptr;
        name = nameoffile;
        times = 1;
    }
};
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

struct Node *exists(Node* root, std::string name, int person){
    if (root == nullptr){
        root =  new Node(name);
        root->people[person] = 1;
        root->hight = 1;
        root->balance = 0;
        return balance(root);
    }
    else if ( name == root -> name){
        root->people[person] = 1;
        root ->times = root ->times + 1;
        return balance(root);
    }
    else{
        if (root -> name < name){
            root ->rightchild =  exists( root ->rightchild, name, person);
            root->hight = root->rightchild->hight + 1;
            if (root->leftchild!= nullptr) (root)->balance = (root)->rightchild->hight - (root)->leftchild->hight;
            else (root)->balance = 0 - (root)->rightchild->hight;
            return balance(root);
        }
        else{
            (root)->leftchild =  exists( root ->leftchild, name, person);
            (root)->hight = (root)->leftchild->hight + 1;
            if ((root)->rightchild!= nullptr) (root)->balance = (root)->rightchild->hight - (root)->leftchild->hight;
            else (root)->balance =(root)->leftchild->hight;
            return balance(root);
        }
    }
}

void result(Node *root,  int *res){
    if (root == nullptr){
        return;
    }
    else{
        if (root->times == 1){
            if (root->people[0]!=0){
                res[0]+=3;
            }
            else if (root->people[1]!=0){
                res[1]+=3;
            }
            else{
                res[2]+=3;
            }
        }
        if (root->times == 2){
            if (root->people[0]!=0){
                res[0]+=1;
            }
            if (root->people[1]!=0){
                res[1]+=1;
            }
            if (root->people[2]!=0){
                res[2]+=1;
            }
        }
        result(root->leftchild,res);
        result(root->rightchild,res);
        return;
    }
}

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int numberofel;
    std::cin >> numberofel;
    std::string nameofafile = "";
    Node* root = nullptr;

    int res[3] = {0,0,0};

    for (int i = 0; i<3;i++){
        for (int j = 0; j<numberofel; j++){
            std::cin >> nameofafile;
            root = exists(root,nameofafile, i);
        }
    }

    result(root,res);
    std::cout << res[0] << " " << res[1] << " " << res[2];

    return 0;
}