#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "board.h"
#include "disk.h"

using namespace std;

int main()
{
    Stack S;
    Disk D;
    Board b;

    int n, i;
    cout<<"enter the number of disksn";
    cin>>n;
    for (i = n; i >= 1; i--)
    {
        S.push1(i);
    }
    b.toh(n);
    return 0;
}
