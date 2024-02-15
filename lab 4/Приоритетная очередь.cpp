#include <iostream>
#include <vector>

void siftDown(std::vector <int> &heap){

    int size = heap.size();
    int i = 0;
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
    return;
}

void siftUp (std::vector <int> &heap, int pos){
    int i = pos;
    while ((i-1)/2 >=0 && heap[i] < heap[(i-1)/2]){
        std::swap(heap[i],heap[(i-1)/2]);
        i = (i-1)/2;
    }
    return;
}



void extractmin(std::vector <int> &heap){
    int size = heap.size();
    if (size == 0){
        std::cout << '*' << "\n";
        return ;
    }

    std::cout << heap[0] << "\n";
    std::swap(heap[0],heap[size-1]);
    heap.pop_back();
    if (size-1 > 1) siftDown(heap);

    return;
}

void decreasekey(std::vector <int> &heap, int position, int val, std::vector <int> &positionofheap ){
    int pos = 0;
    while(heap[pos]!= positionofheap[position - 1]){
        pos++;
    }
    heap[pos] = val;
    positionofheap[position - 1] = val;
    siftUp(heap, pos);
    return;
}

int main(){

    std::vector <int> heap;
    std::vector <int> positionsforheap;
    std::string str;
    int number;
    int position;

    while (std::cin >> str){

        if ( str[0] == 'p'){

            std::cin >> number;
            positionsforheap.push_back(number);
            heap.push_back(number);
            siftUp(heap, heap.size()-1);

        }
        else if ( str[0] == 'e'){
            extractmin(heap);
            positionsforheap.push_back(NULL);
        }
        else if (str[0] == 'd'){
            std::cin >> position;
            std::cin >> number;
            decreasekey(heap, position,number,positionsforheap);
            positionsforheap.push_back(NULL);
        }

    }

    return 0;
}