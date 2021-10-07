#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{   int i=1, n=0;
    while (i>n)
    {
        while (i<4)
            i+=2; n++;
            i-=3;

    }
    cout<<i<<" " <<n;
    getch();
    return 0;
}
