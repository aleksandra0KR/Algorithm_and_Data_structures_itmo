#include <stdio.h>

int main() {
    int N;
    scanf("%i",&N);
    int arr[N][2];
    int key[2];


    for (int i = 0;i<N;i++){
        scanf("%i %i",&arr[i][0],&arr[i][1]);
    }
    int j;
    for (int i=1;i<N;i++){
        key[0] = arr[i][0];
        key[1] = arr[i][1];
        j = i-1;
        while (j>=0 && key[1]>arr[j][1]){
            arr[j+1][0] = arr[j][0];
            arr[j+1][1] = arr[j][1];
            j = j-1;
        }
        while (j>=0 && key[1]==arr[j][1] && key[0]<arr[j][0]){
            arr[j+1][0] = arr[j][0];
            arr[j+1][1] = arr[j][1];
            j = j-1;
        }
        arr[j+1][0] = key[0];
        arr[j+1][1] = key[1];

    }
    for (int i=0;i<N-1;i++){
        printf("%i %i\n",arr[i][0], arr[i][1]);
    }
    printf("%i %i",arr[N-1][0], arr[N-1][1]);


    return 0;
}