#include <stdio.h>

int main() {
    int N;
    scanf("%i",&N);
    int arr[N];
    for (int i =0;i<N;i++){
        scanf("%i",&arr[i]);
    }
    int key;
    for (int j = 1; j<N; j++){
        key = arr[j];
        int i = j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i -=1;

        }
        arr[i+1] = key;
    }
    for (int i = 0; i<N;i++){
        printf("%i ",arr[i]);
    }

    return 0;
}