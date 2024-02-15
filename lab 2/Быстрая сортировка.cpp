#include <iostream>

using namespace std;
void swap(int* a,int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void quicksort(int *arr,int first,int last){
    if (first<last){
        int left = first;
        int right = last;
        int middle =  arr[(left + right)/2];

        do {
            while (arr[left]< middle)
                left++;
            while (arr[right] > middle)
                right--;
            if (left<=right){
                swap(&arr[left],&arr[right]);
                left++;
                right--;
            }
        }while (left<right);
        quicksort(arr,first,right);
        quicksort(arr,left,last);
    }
    return;
}

int main()
{
    int n;
    cin >>n;
    int arr[n];
    for (int i = 0;i<n;++i){
        cin >>arr[i];
    }
    quicksort(arr,0,n-1);
    for (int i = 0;i<n; ++i){
        cout << arr[i]<<' ';
    }
    return 0;}