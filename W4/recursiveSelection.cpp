#include <iostream>

using namespace std;

int minIndex(int a[], int i, int j) 
{ 
    if (i == j) 
        return i; 
  
    int k = minIndex(a, i + 1, j); 
  
    return (a[i] < a[k])? i : k; 
} 
  
void selection(int a[], int n, int index = 0) 
{ 
    if (index == n) 
       return; 
  
    int k = minIndex(a, index, n-1); 
  
    if (k != index) 
       swap(a[k], a[index]); 
  
    selection(a, n, index + 1); 
} 

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
  
int main() 
{ 
    int list[10] = {12,121,51,52,6,51,4,5,37,34}; 
    int size = sizeof(list)/sizeof(list[0]); 

    print(list, size);
    selection(list, size); 
    print(list, size);
  
}