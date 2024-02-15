#include <stdio.h>

int main() {
    int N;
    scanf("%i",&N);
    int arr[N];
    for (int i =0;i<N;i++){
        scanf("%i",&arr[i]);
    }
    int key;
    int flag;
    for (int j = 1; j<N; j++){
        flag = 0;
        key = arr[j];
        int i = j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i -=1;
            flag = 1;
        }
        arr[i+1] = key;
        if (flag==1){
            for (int i = 0; i<N-1;i++){
                printf("%i ",arr[i]);
            }
            printf("%i\n",arr[N-1]);}
    }

    return 0;
}