#include <iostream>

using namespace std;
void swap(int* a,int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void quicksort(int (*arr)[2],int first,int last){
    if (first<last){
        int left = first;
        int right = last;
        int middle =  arr[(left + right)/2][0];

        do {
            while (arr[left][0] < middle)
                left++;
            while (arr[right][0] > middle)
                right--;
            if (left<=right){
                swap(&arr[left][0],&arr[right][0]);
                swap(&arr[left][1],&arr[right][1]);
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
    int n, a1;
    cin >> n;
    int arr[n][2];
    for(int i = 0; i < n; ++i){
        for (int j = 0; j<2 ; ++j){
            cin >> a1;
            arr[i][j] = a1;

        }
    }
    quicksort(arr,0,n-1);
    int res = arr[0][1]-arr[0][0] + 1;
    int max = arr[0][1];

    for (int i = 1; i < n; ++i){
        if (arr[i][0] > max) {
            res += arr[i][1]-arr[i][0] + 1;
            max = arr[i][1];
        } else {
            if (arr[i][1] > max) {
                res += arr[i][1] - max;
                max = arr[i][1];
            }
        }
    }

    cout << res;
    return 0;
}