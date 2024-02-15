#include <iostream>
using namespace std;


void arrfiller(int *arr,int n, int A, int B, int C){
    for (int i=2; i<n; i++){
        arr[i] = A * arr[i-2] + B * arr[i-1] + C;
    }
}
int finderK(int arr[],int k, int n){
    int left = 0;
    int right = n-1;
    while(left<=right){

        if (right <=left+1){
            if (right == left+1 && arr[right] < arr[left]){
                swap(arr[left],arr[right]);
            }
            return arr[k];
        }
        if (arr[left] > arr[right]){
            swap(arr[left],arr[right]);
        }
        if (arr[left + 1] > arr[right]){
            swap(arr[left + 1],arr[right]);
        }
        if (arr[left] > arr[left + 1]){
            swap(arr[left],arr[left + 1]);
        }
        int num = arr[left + 1];
        int i = left + 1;
        int j = right;
        while (i<=j){
            while(arr[++i] < num);
            while(arr[--j] > num);
            if (i > j){
                break;
            }
            swap(arr[i],arr[j]);
        }
        swap(arr[j],arr[left + 1]);
        if(j>=k){
            right = j -1;
        }
        if(i<=k){
            left = i;
        }
    }

}


int main()
{
    int n,k;
    cin >> n >>k;
    int A,B,C;
    cin >> A >> B >> C;
    int* arr;
    arr = (int*)malloc(n*sizeof(int));
    cin >> arr[0] >> arr[1];
    arrfiller(arr,n,A,B,C);

    int res = finderK(arr,k-1,n);
    cout << res;
    free(arr);
    return 0;
}