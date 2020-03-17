#include <iostream>
#include <vector>

int main()
{
    std::vector<int> input{7, 4, 13, 6, 23, 10, 73, 9, 24, 124, 7, 45, 6, 1, 64, 24, 25};

    for (auto i : input)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    int i, j, imax, temp;
    for (i = input.size() - 1; i >= 1; i--)
    {
        imax = 0;
        for (j = 1; j <= i; j++)
        {
            if (input[j] > input[imax])
            {
                imax = j;
            }
        }
        temp = input[i];
        input[i] = input[imax];
        input[imax] = temp;
    }

    for (auto i : input)
    {
        std::cout << i << " ";
    }
}