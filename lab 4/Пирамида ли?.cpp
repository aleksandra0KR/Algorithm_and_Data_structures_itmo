#include <iostream>

bool whetherpyramid(int array[], int numberofel){
    for (int i = 0; i < (numberofel/2); i++){
        if ((2*i+1) < (numberofel - 1) and array[i] > array[2*i+1]){
            return false;
        }
        if ((2*i+2) < (numberofel - 1) and array[i] > array[2*i+2]){
            return false;
        }
    }
    return true;
}

int main(){
    int numberofel;
    std::cin >> numberofel;
    int array[numberofel];

    for (int i = 0; i < numberofel; i++){
        std::cin >> array[i];
    }

    if (whetherpyramid(array, numberofel)) printf("YES");
    else printf("NO");

    return 0;
}