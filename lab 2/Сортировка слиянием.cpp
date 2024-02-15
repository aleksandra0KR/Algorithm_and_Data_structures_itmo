#include <iostream>

using namespace std;

void merge(int a[], int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    int result[right-left + 1];
    while ( ( (left + it1) < (mid) ) and ((mid + it2) < right)){
        if (a[left+it1] <= a[mid+it2]){
            result[it1+it2] = a[left+it1];
            it1++;
        }
        else{
            result[it1+it2] = a[mid+it2 ];
            it2++;
        }
    }
    while (left+it1 <mid ){
        result[it1+it2] = a[left+it1];
        it1++;
    }
    while (mid+it2 < right){
        result[it1+it2] = a[mid+it2 ];
        it2++;
    }
    for (int i = 0;i<it1+it2;i++){
        a[left+i] = result[i];
    }
}
void mergsortrec(int a[],int left, int right){
    if (left + 1 >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergsortrec(a,left,mid);
    mergsortrec(a,mid,right);
    merge(a,left,mid,right);
}

int main()
{
    int n;
    cin >>n;
    int arr[n];
    for (int i = 0;i<n;++i){
        cin >>arr[i];
    }
    mergsortrec(arr,0,n);
    for (int i = 0;i<n; ++i){
        cout << arr[i]<<' ';
    }
    return 0;}