#include <iostream>
#include <chrono>

using namespace std;

void merge(int list[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = list[l + i];
    for (j = 0; j < n2; j++)
        R[j] = list[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            list[k] = L[i];
            i++;
        }
        else
        {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        list[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int list[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(list, l, m);
        mergeSort(list, m + 1, r);

        merge(list, l, m, r);
    }
}

void print(int list[], int n)
{
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
    cout << "\n";
}

int main()
{
    int list[20]{3, 1, 4, 21, 43, 25, 4, 124, 5, 42, 8, 97, 5, 10, 11, 90, 24, 76, 21, 58};
    int size = sizeof(list) / sizeof(list[0]);

    print(list, size);

    auto start = chrono::high_resolution_clock::now();
    mergeSort(list, 0, size - 1);
    auto stop = chrono::high_resolution_clock::now();
    
    print(list, size);

    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cout << "runtime in nanoseconds : " << duration.count() << " ns\n";
}