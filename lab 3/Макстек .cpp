#include <iostream>
#include <string>
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
void Delete(Stack *st)
{
    struct Item *previoustval = st->head->previoustval;
    delete st->head;
    st->head = previoustval;
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


int main() {
    Stack st;
    Stack Max;
    vector <int> res;
    int numberofel;
    string braces;
    int value;

    createStack(&st);
    createStack(&Max);

    cin >> numberofel;
    getchar();

    getline(cin,braces);

    value= std::atoi(&(braces[2]));
    Add(&st,value);
    Add(&Max,value);

    for (int i = 0;i<numberofel-1;i++){

        getline(cin,braces);

        if (braces[0] == '+'){
            value= std::atoi(&(braces[2]));
            Add(&st,value);
            if (value> outfromhead(&Max)){
                Add(&Max,value);
            }
            else{
                Add(&Max,outfromhead(&Max));
            }

        }
        else if (braces[0] == '-') {
            Delete(&Max);
            Delete(&st);
        }
        else{
            res.push_back(outfromhead(&Max));
        }

    }
    int leng = res.size();
    for (int i = 0;i<leng;i++){
        printf("%d\n",res[i]);
    }


}