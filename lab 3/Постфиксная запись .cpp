#include <iostream>


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
    int res = st->head->val;
    struct Item *previoustval = st->head->previoustval;
    delete st->head;
    st->head = previoustval;
    return(res);
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


int main(){
    Stack st;
    createStack(&st);
    std::string operation;

    std::getline(std::cin,operation);
    int i = operation.length();
    for (int j = 0 ;j<i;j+=2){

        if (operation[j] == '+'){
            Add(&st, outfromhead(&st)+ outfromhead(&st));

        }
        else if(operation[j] == '-'){

            Add(&st, outfromhead(&st) - outfromhead(&st));
            Add(&st, outfromhead(&st) * (-1) );

        }
        else if(operation[j] == '*'){
            Add(&st, outfromhead(&st) * outfromhead(&st));

        }
        else{
            Add(&st,int(operation[j])-48);
        }

    }

    printf("%d", outfromhead(&st));


}
