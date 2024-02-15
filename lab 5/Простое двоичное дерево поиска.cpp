#include <iostream>
#include <string>

struct Node
{
    int data;
    Node *leftchild,*rightchild;
    Node(int val){
        leftchild = nullptr;
        rightchild = nullptr;
        data = val;
    }

};

struct Node *exists(int val, Node* root){
    if (root == nullptr){
        return nullptr;
    }
    if (root->data == val){
        return root;
    }
    else{
        if (root->data < val){
            return exists( val,root->rightchild);
        }
        else{
            return exists( val,root->leftchild);
        }
    }
}

struct Node *insetrval(int val, Node* root){
    if (root == nullptr){
        return new Node(val);
    }
    if (exists(val,root)!= nullptr){
        return root;
    }

    else{
        if (root->data < val){
            root->rightchild = insetrval( val,root->rightchild);
        }
        else{
            root->leftchild = insetrval( val,root->leftchild);
        }
    }
    return root;
}

struct Node *parent(int val, Node* root){
    if (root->data == val){
        return nullptr;
    }
    if ((root->rightchild!= nullptr &&(root->rightchild)->data == val) ||(root->leftchild!= nullptr &&(root->leftchild)->data == val) ){
        return root;
    }
    else{
        if (root->data < val){
            return parent( val,root->rightchild);
        }
        else{
            return parent( val,root->leftchild);
        }
    }
}


struct Node* next( Node* root, int val){
    struct Node* current = root;
    struct Node* successor = nullptr;
    while (current!= nullptr){
        if (current->data <= val){
            current = current->rightchild;
        }
        else{
            successor = current;
            current = current->leftchild;
        }
    }
    return successor;
}

struct Node* previous( Node* root, int val){
    struct Node* current = root;
    struct Node *successor = nullptr;
    while (current!= nullptr){
        if (current->data >= val){
            current = current->leftchild;
        }
        else{
            successor = current;
            current = current->rightchild;
        }
    }
    return successor;
}


struct Node * deleteval(int val, Node* root){
    if (exists(val,root) == nullptr){
        return root;
    }
    struct Node *parentofelement = parent(val,root);
    struct Node *element = exists(val,root);
    if (element->leftchild == nullptr && element->rightchild == nullptr){
        if (parentofelement == nullptr) {


            delete element;
            return nullptr;
        }
        if (parentofelement->leftchild!= nullptr && parentofelement->leftchild->data == val){
            parentofelement->leftchild = nullptr;
            return root;
        }
        else{
            parentofelement->rightchild = nullptr;
            return root;
        }
    }
    else if (element->leftchild == nullptr || element->rightchild == nullptr){
        if (parentofelement == nullptr) {
            if (element->leftchild == nullptr){
                element->data = element->rightchild->data;
                struct Node *temp = element->rightchild;

                element->rightchild = temp->rightchild;
                element->leftchild = temp->leftchild;
                return root;
            }
            else{
                element->data = element->leftchild->data;
                struct Node *temp = element->leftchild;
                element->leftchild = temp->leftchild;
                element->rightchild = temp->rightchild;
                return root;
            }
        }
        if (element->leftchild == nullptr){
            if (parentofelement->leftchild != nullptr && parentofelement->leftchild->data == val){
                parentofelement->leftchild = element->rightchild;
                return root;
            }
            else{
                parentofelement->rightchild = element->rightchild;
                return root;
            }
        }
        else{
            if ((parentofelement->leftchild!= nullptr) && parentofelement->leftchild->data == val){
                parentofelement->leftchild = element->leftchild;
                return root;
            }
            else{
                parentofelement->rightchild = element->leftchild;
                return root;
            }
        }
    }
    else{
        struct Node* successor = next(root,val);
        if (successor == nullptr) successor = previous(root,val);
        struct Node* successorparent = parent(successor->data,root);

        element->data = successor->data;

        if (successorparent->leftchild != nullptr && successorparent->leftchild == successor){
            successorparent->leftchild = successor->rightchild;
            successor->rightchild = nullptr;
        }
        else{
            successorparent->rightchild = successor->rightchild;
            successor->rightchild = nullptr;
        }
        return root;
    }
}


int main(){
    Node *root = nullptr;
    std::string command;
    int number;

    while (std::cin >> command) {
        if (command == "insert"){
            std::cin >> number;
            root = insetrval(number,root);
        }
        if (command == "exists"){
            std::cin >> number;
            if(exists(number,root)!= nullptr){
                std::cout << "true\n";
            }
            else{
                std::cout << "false\n";
            }
        }
        if (command == "next"){
            std::cin >> number;
            Node *res = next(root,number);
            if (res!= nullptr){
                std::cout << res->data << "\n";
            }
            else std::cout << "none" << "\n";
        }

        if (command == "prev"){
            std::cin >> number;
            Node *res = previous(root,number);
            if (res!= nullptr){
                std::cout << res->data << "\n";
            }
            else std::cout << "none" << "\n";
        }
        if (command == "delete"){
            std::cin >> number;
            root = deleteval(number,root);
        }
    }
    return 0;
}
