#include <iostream>
#include <string>
using namespace std;

struct Item{
    char val;
    struct Item *previoustval;
};

struct Stack{
    Item  *head;
};

void createStack(Stack *st){
    st->head = NULL;
}

void pop(Stack *st){
    Item *p = st->head->previoustval;
    delete st->head;
    st->head = p;
}
void clear(Stack *st){
    while(!(st->head == NULL)){
        pop(st);
    }
}

char outfromhead(Stack *st){
    if (st->head!=NULL){
        char res = st->head->val;
        pop(st);
        return(res);
    }
    else{
        return '0';
    }


}

void Add(Stack *st, char val)
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
    string braces;
    int flag = 0;
    int leng;
    char temp;
    while (cin >> braces){

        flag = 0;
        leng = braces.length();

        for (int i = 0;i < leng;i++){

            if (braces[i]==')'){

                temp = outfromhead(&st);
                if (temp== '0' or temp != '('){
                    cout << "NO\n";
                    flag = 1;

                    goto exit;
                }
            }

            else if (braces[i]==']'){
                temp = outfromhead(&st);
                if (temp== '0' or temp != '['){
                    cout << "NO\n";
                    flag = 1;

                    goto exit;
                }
            }
            else{
                Add(&st,braces[i]);
            }


        }
        exit:
        if (flag==0 and st.head == NULL) cout << "YES\n";
        else {
            if (flag == 0){
                cout << "NO\n";
            }

        }
        clear(&st);
    }
}
