#include <iostream>

using namespace std;

int vertArr[20][20];
void add_edge(int origin, int destination)
{
    vertArr[origin-1][destination-1] = 1;
    vertArr[destination-1][origin-1] = 1;
}

void displayList(int node_count)
{
    for (int i = 0; i < node_count; i++)
    {
        cout << i+1 << " [ ";
        for (int j = 0; j < node_count; j++)
        {
            if(vertArr[i][j] == 1)
            {
                cout << j+1 << " ";
            }
        }
        cout << "]\n";
    }
}

int main(){

    int n = 8;
    add_edge(1, 2);
    add_edge(1, 3);
	add_edge(2, 4);
    add_edge(2, 5);
    add_edge(2, 3);
	add_edge(3, 5);
    add_edge(3, 7);
    add_edge(3, 8);
    add_edge(4, 5);
    add_edge(5, 6);
    add_edge(7, 8);
    displayList(n);

    return 0;
}