#include <iostream>

using namespace std;

void bubbleSort(int list[], int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
        if (list[i] > list[i + 1])
            swap(list[i], list[i + 1]);

    bubbleSort(list, n - 1);
}

void print(int list[], int n)
{
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
    cout << "\n";
}

int main()
{
    int list[10] = {2, 31, 44, 1, 51, 5, 3, 2, 42, 6};
    int size = sizeof(list) / sizeof(list[0]);

    print(list, size);
    bubbleSort(list, size);
    print(list, size);
}