#include <iostream>
#include <string>

struct Node
{
    std::string name;
    int times;
    int people[3]= {0,0,0}; ;
    Node *leftchild,*rightchild;
    Node(std::string nameoffile) {
        leftchild = nullptr;
        rightchild = nullptr;
        name = nameoffile;
        times = 1;
    }
};

struct Node *exists(Node** root, std::string name, int person){
    if ((*root) == nullptr){
        (*root) =  new Node(name);
        (*root)->people[person] = 1;
        return (*root) ;
    }
    else if ( name == (*root) ->name){
        (*root) ->people[person] = 1;
        (*root) ->times = (*root) ->times + 1;
        return (*root) ;
    }
    else{
        if ((*root) ->name < name){
            return exists( &(*root) ->rightchild, name, person);
        }
        else{
            return exists( &(*root) ->leftchild, name,person);
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

    int numberofel;
    std::cin >> numberofel;
    std::string nameofafile = "";
    Node* root = nullptr;

    int res[3] = {0,0,0};

    for (int i = 0; i<3;i++){
        for (int j = 0; j<numberofel; j++){
            std::cin >> nameofafile;
            exists(&root,nameofafile, i);
        }
    }

    result(root,res);
    std::cout << res[0] << " " << res[1] << " " << res[2];

    return 0;
}