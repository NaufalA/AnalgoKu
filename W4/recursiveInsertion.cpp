#include <iostream>

using namespace std;

void insertion(int list[], int n)
{
    if (n <= 1)
        return;

    insertion(list, n - 1);

    int last = list[n - 1];
    int j = n - 2;

    while (j >= 0 && list[j] > last)
    {
        list[j + 1] = list[j];
        j--;
    }
    list[j + 1] = last;
}

void print(int list[], int n)
{
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
    cout << "\n";
}

int main()
{
    int list[10] = {12, 123, 11, 12, 3, 1, 411, 41, 3, 5};
    int size = sizeof(list) / sizeof(list[0]);

    print(list, size);
    insertion(list, size);
    print(list, size);
}