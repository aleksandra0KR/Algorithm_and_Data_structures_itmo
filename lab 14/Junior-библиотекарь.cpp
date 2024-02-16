#include <iostream>
#include <vector>

using std::cin;
using std::string;
using std::endl;
using std::cout;

struct Node {
    string name = "";
    int value = 1;
    Node *left_child = nullptr;
    Node *right_child = nullptr;

    Node(string n) {
        name = n;
    };
    ~Node() = default;

};

Node* add(Node *root, const std::string &name) {
    if (root == nullptr) {
        return new Node(name);
    }
    if (name <= root->name) {
        root->left_child = add(root->left_child, name);
    } else if (name > root->name) {
        root->right_child = add(root->right_child, name);
    }

    root->value = 1;
    if (root->left_child != nullptr and root->right_child != nullptr) {
        root->value += root->left_child->value + root->right_child->value;
    } else if (root->right_child != nullptr) {
        root->value += root->right_child->value;
    } else if (root->left_child != nullptr) {
        root->value += root->left_child->value;
    }

    return root;
}

string answer(Node *root, int position) {
    if (root == nullptr) {
        return "";
    }

    if (root->left_child != nullptr and position <= root->left_child->value) {
        return answer(root->left_child, position);
    }
    else if(position == (root->left_child != nullptr ? root->left_child->value : 0) + 1){
        return root->name;
    }
    else if (root->left_child == nullptr) {
        return answer(root->right_child, position - 1);
    }
    else {
        return answer(root->right_child, position - root->left_child->value - 1);
    }

}

int main() {

    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    Node* root = nullptr;
    int number_of_str;
    cin >> number_of_str;
    string commant;
    int position;

    for (int i = 0; i < number_of_str; i++) {
        cin >> commant;
        if (!std::isdigit(commant[0])) {
            root = add(root, commant);
        } else {
            position = std::stoi(commant);
            cout << answer(root, position) << endl;
        }
    }
    return 0;

}