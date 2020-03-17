#include <iostream>
#include <vector>

int main()
{
    std::vector<int> input;
    int n = 0;
    std::cout << "size : ";std::cin >> n;

    for (int i = 0; i != n; i++)
    {
        int user;
        std::cin >> user;
        input.push_back(user);
    }

    int max = input[0];
    int i = 1;
    while (i <= n)
    {
        if (input[i] > max)
            max = input[i];
        i = i + 1;
    }

    std::cout << max;
}