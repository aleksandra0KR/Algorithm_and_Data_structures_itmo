#include <iostream>
int BinarySearchlastin(int arr[],int x,int n){
    int left = -1;
    int right = n;
    int mid;
    while (right>left+1){
        mid = (left+right)/2;
        if (arr[mid]<=x){
            left = mid;
        }
        else right = mid ;
    }
    if (arr[left] == x) return left+1;
    return -1;

}
int BinarySearchfirstin(int arr[],int x,int n){
    int left = -1;
    int right = n;
    int mid;
    while (right>left+1){
        mid = (left+right)/2;
        if (arr[mid]<x){
            left = mid;
        }
        else right = mid;
    }
    if (right<n and arr[right] == x) return right+1;
    return -1;

}

int main(){
    int lengthofarr;
    std::cin >> lengthofarr;
    int arr[lengthofarr];
    for (int i = 0;i<lengthofarr;i++){
        std::cin >> arr[i];
    }
    int lengthofrequests;
    std::cin >> lengthofrequests;
    int arrreq[lengthofrequests];
    for (int i = 0;i<lengthofrequests;i++){
        std::cin >> arrreq[i];
    }
    for (int i = 0;i<lengthofrequests;i++){
        printf("%d %d\n",BinarySearchfirstin(arr,arrreq[i],lengthofarr),BinarySearchlastin(arr,arrreq[i],lengthofarr) );

    }
}