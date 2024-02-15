#include <iostream>
int **arr;
int maxhightofatree( int currentpos, int pos){

    if (arr[currentpos][pos] == 0) {
        return 0;
    }
    else{
        int lefthight = maxhightofatree(arr[currentpos][pos]-1, 1);
        int righthight = maxhightofatree(arr[currentpos][pos]-1, 2);

        int mac = (lefthight >= righthight ? lefthight : righthight);
        return 1 + mac;}

}

int main(){


    int numberofinputstrings;
    std::cin >> numberofinputstrings;


    arr = (int**) malloc(numberofinputstrings*sizeof(int*));
    for (int i = 0; i < numberofinputstrings; i++ ){
        arr[i] = (int*) malloc(3*sizeof(int));
    }

    for (int i = 0; i < numberofinputstrings; i++){
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
        std::cin >> arr[i][2];
    }

    if (numberofinputstrings == 0){
        std::cout << 0;
        return 0;
    }
    if (numberofinputstrings == 1){
        std::cout << 1;
        return 0;
    }

    int leftans = maxhightofatree( 0, 1) + 1;
    int rightans = maxhightofatree( 0, 2) + 1;
    std::cout << (leftans >= rightans ? leftans : rightans);

    return 0;}