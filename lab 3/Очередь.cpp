#include <iostream>
#include <vector>
using namespace std;

struct Item{
    int val;
    struct Item *nextval;
};

struct Queue{
    Item  *head = NULL;
    Item *tail = NULL;
};


int outfromhead(Queue *que){
    return(int(que->head->val));
}
void Add(Queue *que, int val)
{
    if(que->head == NULL && que->tail == NULL){
        que->head = new Item;
        que->head->val = val;
        que->head->nextval = NULL;
        que->tail = que->head;
    }
    else{
        que->tail->nextval=new Item;
        que->tail= que->tail->nextval;
        que->tail->val = val;
        que->tail->nextval= NULL;
    }

}

void Delete(Queue *que)
{
    if (que->head->nextval!= NULL){
        Item *p = que->head->nextval;
        delete que->head;
        que->head = p;
    }
    else{
        delete que->head;
        que->head = NULL;
        que->tail = NULL;
    }

}

int main(){
    Queue Q;
    int val;
    vector <int> result;
    int numberofoperation;
    cin >> numberofoperation;
    char operation;
    for (int i = 0; i<numberofoperation;i++){
        cin >> operation;
        if (operation == '+'){
            cin >> val;
            Add(&Q,val);
        }
        else{
            result.push_back(int(outfromhead(&Q)));
            Delete(&Q);
        }
    }
    for (int i = 0; i< result.size();i++){
        printf("%d\n", result[i]);
    }
}