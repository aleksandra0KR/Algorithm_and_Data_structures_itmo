#include <stdio.h>

int main() {
    int N;
    int num,pos;
    scanf("%i",&N);
    int arr[N+1];
    for (int i=0; i<N;i++){
        scanf("%i",&arr[i]);
    }
    scanf("%i %i",&num, &pos);
    for (int i=N; i>pos-1;i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1] = num;
    for (int i = 0;i<N;i++){
        printf("%i ",arr[i]);
    }
    printf("%i ",arr[N]);

    return 0;
}