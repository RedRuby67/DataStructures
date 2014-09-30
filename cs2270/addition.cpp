#include <iostream>
#include <cstdlib> 
#include <cstring>
#include "bigInt.h"   

using namespace std;

int main()
{

    char a = '5';
    char b = '6';
    char c;
    a = a - '0';
    b = b - '0';
    c = a + b;
    if (c >= 10)
        {
            c = c % 10;
        }
    c = c + '0';
    cout << "c = " << c << endl;

    
    
    return EXIT_SUCCESS;
}
