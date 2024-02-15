#include <iostream>
int **arr;
int *res;

int balanceoftheavl( int currentpos){
    int leftmax = 0;
    int rightmax = 0;

    if (arr[currentpos][1] == 0 and arr[currentpos][2] == 0 ){
        res [currentpos] = 0;
        return 1;
    }
    else if (arr[currentpos][1] == 0 ){
        rightmax =  balanceoftheavl(arr[currentpos][2] - 1);
        res [currentpos] = rightmax;}
    else if (arr[currentpos][2] == 0) {
        leftmax =  balanceoftheavl(arr[currentpos][1] - 1);
        res [currentpos] = 0 - leftmax;
    }

    else{leftmax = balanceoftheavl(arr[currentpos][2]- 1);
        rightmax = balanceoftheavl(arr[currentpos][1]- 1);
        res [currentpos] = leftmax - rightmax;}
    int mac = leftmax > rightmax ? leftmax : rightmax;
    return mac+1;

}


int main(){
    int numberofstrings;
    std::cin >> numberofstrings;
    res = (int*) malloc(numberofstrings*sizeof(int*));
    arr = (int**) malloc(numberofstrings*sizeof(int*));
    for (int i = 0; i < numberofstrings; i++ ){
        arr[i] = (int*) malloc(3*sizeof(int));
    }

    for (int i = 0; i < numberofstrings; i++){
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
        std::cin >> arr[i][2];
    }
    balanceoftheavl(0);
    for (int i = 0; i < numberofstrings; i++ ){
        std::cout << res[i] << '\n';
    }

    return 0;
}