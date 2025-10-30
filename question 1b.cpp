#include <iostream>
using namespace std;


void PrintPattern(int n, int row = 1)
{
    
    if (row > n)
        return;

    if (row == 1)
        cout << "4";
    else if (row == 2)
        cout << "2 2";
    else if (row == 3)
        cout << "1 3";
    else if (row == 4)
        cout << "1 1 2";
    else
    {
        
        for (int i = 1; i <= row; i++)
            cout << "1 ";
    }

    cout << endl;

    
    PrintPattern(n, row + 1);
}

int main()
{
    int n;
    cout << "Enter any number ";
    cin >> n;

    PrintPattern(n);

    return 0;
}
