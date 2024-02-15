#include <iostream>
#include <vector>

// находим максимум в массиве, чтобы узнать алфавит
int getMax(std::string array[], int numberofelements,int exp)
{
    int amax = array[0][exp];
    for (int i = 1; i < numberofelements; i++)
        if (array[i][exp] > amax)
            amax = array[i][exp];

    return amax;
}

// находим минимум в массиве, чтобы узнать алфавит
int getMin(std::string array[], int numberofelements, int exp)
{
    int amin = array[0][exp];
    for (int i = 0; i < numberofelements; i++)
        if (array[i][exp] < amin)
            amin = array[i][exp];

    return amin;
}

// подсчет
void countSort(std::string array[], int numberofelements, int exp)
{
    std::string result[numberofelements]; // результат сортировки подсчетом для одного разряда

    int minchar = getMin(array,numberofelements,exp);
    int maxchar = getMax(array,numberofelements,exp);

    std::vector <int> counter(maxchar - minchar + 1, 0 ); // вектор для подсчета

    for (int i = 0; i < numberofelements; i++){ // заполняем массив с кол-ом букв с каждой из строк
        counter[int((array[i][exp])) - minchar]++;
    }

    for (int i = 1; i < (maxchar-minchar+1); i++){ //присваиваем верные позиции, опираясь на позицию предыдущего эл-та
        counter[i] += counter[i - 1];
    }

    for (int i = numberofelements - 1; i >= 0; i--){ // заполняем результат сортировки подсчетом для одного разряда
        result[counter[int(array[i][exp]) - minchar] - 1] = array[i];
        counter[int(array[i][exp]) - minchar]--;
    }

    for (int i = 0; i < numberofelements; i++){ //переписываем наш исходный массив, чтобы следующий разряд сортировался с уже отсортированным предыдущем массивом
        array[i] =  result[i] ;
    }
}

//функция вывода
void printarr(std::string array[], int numberofelements)
{
    for (int i = 0; i < numberofelements; i++)
        std::cout << array[i] << "\n";
}

// Сортировка по разрядам
void radixsort(std::string arr[], int numberofelements, int k, int m)
{
    int phase = 0; // фаза цифровой сортировки
    int exp =  m-1; // разряд

    while (phase < k and exp >= 0){
        countSort(arr, numberofelements, exp);
        phase++;
        exp--;
    }
}




int main()
{
    int n;
    int m;
    int k;

    std::cin >> n;
    std::cin >> m;
    std::cin >> k;

    std::string arr[n];

    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    radixsort(arr, n, k, m); // функция сортировки
    printarr(arr, n); //функция вывода

    return 0;
}