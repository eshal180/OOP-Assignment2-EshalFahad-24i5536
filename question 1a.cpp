#include <iostream>
using namespace std;


void ChangeLocation(char *Array, int b1, int b2)
{
    
    if (b1 >= b2)
        return;

    
    char temp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = temp;

    
    ChangeLocation(Array, b1 + 1, b2 - 1);
}

int main()
{
    
    char Array[8] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};

    int b1 = 2; 
    int b2 = 6; 

    cout << "Before changing"<<endl;
    for (int i = 0; i < 8; i++)
        cout << Array[i] << " ";

    ChangeLocation(Array, b1, b2);

    cout << "After changing"<<endl;
    for (int i = 0; i < 8; i++)
        cout << Array[i] << " ";

    return 0;
}
