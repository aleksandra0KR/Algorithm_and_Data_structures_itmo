#include <iostream>
#include <math.h>

int *tree;
int sum = 0;

void update_summary(int pos){
    if (pos<1){
        return ;
    }
    tree[pos] = tree[2 * pos ] + tree[2 * pos + 1];
    update_summary(pos/2);
}

void get_summary(int L, int R)
{
    if (L>R) return;
    if (L%2!=0) sum+= tree[L];
    if (R%2==0) sum+= tree[R];
    get_summary((L+1)/2, (R-1)/2);
    return;

}

int main(){
    int cats;
    std::cin >> cats;

    int numberofstrings;
    std::cin >> numberofstrings;

    int roofs = (cats + log2(cats-1)+1)*2;
    tree = (int*) malloc(roofs*sizeof(int));
    for (int i = 0; i< roofs ; i++){
        tree[i] = 0;
    }

    char action;
    int j,k;
    int L,R;
    cats+= log2(cats-1)+1;
    for(int i = 0; i < numberofstrings; i++) {
        std::cin >> action;
        if (action == '+'){
            std:: cin >> j ;
            std::cin >> k;
            tree[j+cats-1] += k;
            update_summary((j+cats-1)/2);
        }
        else if (action == '-'){
            std:: cin >> j ;
            std::cin >> k;
            tree[j+cats-1] -= k;
            tree[j+cats-1] = tree[j+cats-1]>0?tree[j+cats-1]:0;
            update_summary((j+cats-1)/2);
        }
        else{
            sum = 0;
            std:: cin >> L ;
            std::cin >> R;
            get_summary(L+cats-1,R+cats-1);
            std::cout << sum << "\n";
        }
    }

    return 0;
}