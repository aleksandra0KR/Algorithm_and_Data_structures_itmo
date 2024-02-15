#include <iostream>
int **arr;
int *t;

void buildatree(int pos, int &number, int numberofel) {
    if (arr[pos][0] == 0 and arr[pos][1] == 0) {
        t[pos] = number;
        number--;
        return;
    } else if (arr[pos][0] !=0 and arr[pos][1] == 0) {
        t[pos] = number;
        number--;
        buildatree(arr[pos][0]-1, number, numberofel);
        return;
    } else if (arr[pos][1]!=0 and arr[pos][0] == 0) {
        buildatree(arr[pos][1]-1, number, numberofel);
        t[pos] = number;
        number--;
        return;
    } else {
        buildatree(arr[pos][1]-1, number, numberofel);
        t[pos] = number;
        number--;
        buildatree(arr[pos][0]-1, number, numberofel);

        return;
    }
}


int main(){
    int numberofel;
    std::cin >> numberofel;

    arr = (int**) malloc(numberofel*sizeof(int*));
    for (int i = 0; i < numberofel; i++ ){
        arr[i] = (int*) malloc(2*sizeof(int));
    }
    for (int i = 0; i < numberofel; i++) {
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
    }
    int number = numberofel;
    t = (int*) malloc(number*sizeof(int*));
    buildatree(0,number, numberofel);

    for (int i = 0; i < numberofel; i++) {
        std::cout << t[i] << " ";

    }

    return 0;

}