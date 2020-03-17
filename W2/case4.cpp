#include <iostream>
#include <vector>
int main()
{
    std::vector<int> input = {9, 1, 2, 5, 7, 4, 6, 8, 4, 3, 12, 41, 41, 22, 71, 5, 47, 3, 4, 11};

    for (auto i : input)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    int i, j, insert;

    for (i = 1; i < input.size(); i++)
    {
        insert = input[i];
        j = i;
        while (j > 0 && input[j - 1] > insert)
        {
            input[j] = input[j - 1];
            j = j - 1;
        }
        input[j] = insert;
    }

    for (auto i : input)
    {
        std::cout << i << " ";
    }
}