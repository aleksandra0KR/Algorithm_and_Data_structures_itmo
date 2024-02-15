#include <iostream>
using namespace std;


double minlasthightB(int numberoflights, double righthight)
{
    double left = 0;
    double right = righthight ;
    double otherlights[numberoflights];
    otherlights[0] = righthight;
    double prev,res;
    while(right-left>0.000001){
        otherlights[1] = (right+left)/2;
        bool is_higher_that_0 = true;

        for (int i = 2;i<numberoflights;i++){
            otherlights[i] = 2 * otherlights[i-1] - otherlights[i-2] + 2;
            if (otherlights[i] < 0){
                is_higher_that_0 = false;
                break;
            }

        }

        if (is_higher_that_0){
            right = otherlights[1];

        }
        else left = otherlights[1];
    }

    otherlights[1] =right;
    for (int i = 2;i<numberoflights;i++){
        otherlights[i] = 2 * otherlights[i-1] - otherlights[i-2] + 2;}
    return otherlights[numberoflights-1];
}

int main()
{
    int numberoflights ;
    cin >> numberoflights;
    double righthight;
    cin >> righthight;
    printf("%.2f", minlasthightB(numberoflights,righthight));
    return 0;
}