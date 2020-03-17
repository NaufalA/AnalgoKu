#include <iostream>
#include <vector>

int main()
{
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int idx;

    int y;
    // y = 4;
    std::cin >> y;
    bool found = false;
    int i = 0;
    int j = input.size();
    int mid;
    while (i <= j && !found)
    {
        mid = (i+j)/2;
        if(input[mid] == y)
        {
            found = true;
        }
        else
        {
            if(input[mid] < y)
            {
                i = mid+1;
            }
            else
            {
                j = mid-1;
            }
        }
    }

    if (found)
        idx = mid;

    else
        idx = -1;

    std::cout << idx;
}