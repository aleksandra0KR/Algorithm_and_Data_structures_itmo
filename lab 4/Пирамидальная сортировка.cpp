#include <iostream>

void siftDown(int heap[], int i, int size){
    while (2 * i + 1 < size){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < size and heap[right] < heap[left]){
            j = right;
        }
        if (heap[i] <= heap[j]){
            break;
        }
        std::swap(heap[i],heap[j]);
        i = j;
    }
}

int main(){
    int numberofel;
    std::cin >> numberofel;
    int heap[numberofel];

    for (int i = 0 ; i < numberofel; i++){
        std::cin >> heap[i];
    }

    for (int i = (numberofel / 2) - 1; i >= 0; i--){
        siftDown(heap,i, numberofel);
    }

    for (int i = numberofel - 1; i >= 0; i--){
        std::cout << heap[0] << " ";
        std::swap(heap[0],heap[i]);
        siftDown(heap,0, i);
    }
}