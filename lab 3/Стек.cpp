#include <iostream>
#include <vector>
using namespace std;

struct Item{
    int val;
    struct Item *previoustval;
};

struct Stack{
    Item  *head;
};

void createStack(Stack *st){
    st->head = NULL;
}


int outfromhead(Stack *st){
    return(st->head->val);
}
void Add(Stack *st, int val)
{
    if(st->head == NULL){
        st->head = new Item;
        st->head->val = val;
        st->head->previoustval = NULL;
    }
    else{
        Item *newItem = new Item;
        newItem -> val = val;
        newItem -> previoustval = st->head;
        st->head = newItem;
    }

}

void Delete(Stack *st)
{
    if (st->head->previoustval!= NULL){
        Item *p = st->head->previoustval;
        delete st->head;
        st->head = p;
    }
    else{
        delete st->head;
        st->head = NULL;
    }

}

int main(){
    Stack st;
    int val;
    vector <int> result;
    createStack(&st);
    int numberofoperation;
    cin >> numberofoperation;
    char operation;
    for (int i = 0; i<numberofoperation;i++){
        cin >> operation;
        if (operation == '+'){
            cin >> val;
            Add(&st,val);
        }
        else{
            result.push_back(outfromhead(&st));
            Delete(&st);
        }
    }
    for (int i = 0; i< result.size();i++){
        printf("%d\n", result[i]);
    }

}