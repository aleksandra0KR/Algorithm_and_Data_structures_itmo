#include <iostream>


using namespace std;
void swap(int* a,int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void antiquicksort(int *arr, int n)
{
    for (int i=2;i<n;i++)
        swap(arr[i],arr[i/2]);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
        arr[i] = i+1;
    antiquicksort(arr, n);
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}