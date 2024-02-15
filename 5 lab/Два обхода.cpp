#include <iostream>

struct Node{
    int data;
    Node *leftchild,*rightchild;
    Node(int val){
        leftchild = nullptr;
        rightchild = nullptr;
        data = val;
    }
};

int buildatree(int arr[], Node* current, int pos, int numberofel, int min, int max){
    if (pos == numberofel || arr[pos]< min || arr[pos] > max){
        return pos;
    }
    if (arr[pos] < current->data){
        current->leftchild = new Node(arr[pos]);
        pos++;
        pos = buildatree(arr,current->leftchild, pos, numberofel,min, current->data-1);
        if (pos == numberofel || arr[pos]< min || arr[pos] > max){
            return pos;
        }
    }
    current->rightchild = new Node(arr[pos]);
    pos++;
    pos = buildatree(arr,current->rightchild, pos, numberofel,current->data+1, max);
    return pos;
}

void postorderTraversal(Node* root){
    if (root!= nullptr){
        postorderTraversal(root->leftchild);
        postorderTraversal(root->rightchild);
        std::cout << root->data << " ";
    }
    return;
}

int main() {

    int numberofel;
    std::cin >> numberofel;

    int arr[numberofel];
    for (int i = 0; i < numberofel; i++) {
        std::cin >> arr[i];
    }
    struct Node *root = new Node(arr[0]);

    buildatree(arr, root, 1, numberofel, INT_MIN, INT_MAX);

    postorderTraversal(root);

    return 0;
}