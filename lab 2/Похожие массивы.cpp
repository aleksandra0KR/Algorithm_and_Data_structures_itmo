#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int left, int mid, int right){
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
void mergsortrec(vector <int>& a,int left, int right){
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
    int n, m, a1;
    cin >> n;
    vector<int> arr1;
    vector<int> arr2;
    for(int i = 0; i < n; ++i){
        cin >> a1;
        arr1.push_back(a1);
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> a1;
        arr2.push_back(a1);
    }
    mergsortrec(arr2,0,m);
    mergsortrec(arr1,0,n);




    for(int i = 0; i < arr1.size() - 1; ++i){
        if(arr1[i] == arr1[i + 1]){
            arr1.erase(arr1.begin() + i + 1);
            --i;
        }
    }
    for(int i = 0; i < arr2.size() - 1 ; ++i){
        if(arr2[i] == arr2[i + 1]){
            arr2.erase(arr2.begin() + i + 1);
            --i;
        }
    }

    int res = (arr1==arr2);
    if(res ==1){
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}