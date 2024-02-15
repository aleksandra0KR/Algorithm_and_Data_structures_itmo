#include <iostream>



bool MinMaxSum(long long largest, long long array[], long long n, long long k){
    long long  subarray = 0;
    long long curSum = 0;
    for (int i = 0; i < n; i++){
        curSum += array[i];
        if (curSum > largest){
            subarray++;
            curSum = array[i];
        }
    }
    return subarray + 1 <= k;
}


void split (long long largest, long long summa,long long array[], long long n, long long k){
    long long l = largest;
    long long r = summa;

    long long res = r;
    while (l <= r){
        long long  mid = l + ((r - l) / 2);
        if (MinMaxSum(mid, array, n, k)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }

    long long subarray = 0;
    long long curSum = 0;
    long long ans[k-1];
    std::fill(ans, ans + (k-1), 0);
    long long  j = 0;
    for (int i = 0; i < n; i++){
        curSum += array[i];
        if (curSum > res){
            subarray++;
            curSum = array[i];
            ans[j] = i;
            j++;
        }
    }


    long long itans = 0;
    long long it = k - 2;
    long long untakenpos = 1;

    while (ans[it] == 0){
        if(untakenpos != ans[itans]){
            ans[it] = untakenpos;
            it--;
        }
        untakenpos++;
        if (untakenpos > ans[itans]){
            itans++;
        }

    }
    std::sort(ans,ans+(k-1));

    for (int i = 0; i < k - 1; i++){
        std::cout <<ans[i] << ' ' ;
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    long long n;
    long long k;

    std::cin >> n;
    std::cin >> k;
    long long array[n];
    long long maxval = 0;
    long long summa = 0;

    for (int i = 0; i < n; i++){
        std::cin >> array[i];
        if (array[i]>maxval){
            maxval = array[i];
        }
        summa+=array[i];
    }
    split(maxval,summa,array,n,k);

    return 0;
}