#include "stack.h"
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#include "disk.h"
#include "board.h"


Disk::Disk(){

}

void Disk::display1()
{
    cout<<endl;
    node4 *p4;
    p4 = top4;
    cout<<"Tower1-> "<<" ";
    while (p4 != NULL)
    {
        cout<<p4->data4<<" " ;
        p4 = p4->next4;
    }
    cout<<endl;
}
void Disk::display2()
{
    node5 *p5;
    p5 = top5;
    cout<<"Tower2-> "<<" ";
    while (p5 != NULL)
    {
        cout<<p5->data5<<" ";
        p5 = p5->next5;
    }
    cout<<endl;
}
void Disk::display3()
{
    node6 *p6;
    p6 = top6;
    cout<<"Tower3-> "<<" ";
    while (p6 != NULL)
    {
        cout<<p6->data6<<" ";
        p6 = p6->next6;
    }
    cout<<endl;
    cout<<endl;
}

