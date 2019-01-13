#ifndef DISK_H
#define DISK_H


#include<iostream>


using namespace std;

class Disk
{
    struct node4
    {
        int data4;
        node4 *next4;
    }*top4 = NULL, *p4 = NULL, *np4 = NULL;
    struct node5
    {
        int data5;
        node5 *next5;
    }*top5 = NULL, *p5 = NULL, *np5 = NULL;
    struct node6
    {
        int data6;
        node6 *next6;
    }*top6 = NULL, *p6 = NULL, *np6 = NULL;
public:
    Disk();
    void display1();
    void display2();
    void display3();

};

//Disk::Disk(){

//}

//void Disk::display1()
//{
//    cout<<endl;
//    node1 *p1;
//    p1 = top1;
//    cout<<"Tower1-> "<<" ";
//    while (p1 != NULL)
//    {
//        cout<<p1->data1<<" " ;
//        p1 = p1->next1;
//    }
//    cout<<endl;
//}
//void Disk::display2()
//{
//    node2 *p2;
//    p2 = top2;
//    cout<<"Tower2-> "<<" ";
//    while (p2 != NULL)
//    {
//        cout<<p2->data2<<" ";
//        p2 = p2->next2;
//    }
//    cout<<endl;
//}
//void Disk::display3()
//{
//    node3 *p3;
//    p3 = top3;
//    cout<<"Tower3-> "<<" ";
//    while (p3 != NULL)
//    {
//        cout<<p3->data3<<" ";
//        p3 = p3->next3;
//    }
//    cout<<endl;
//    cout<<endl;
//}


#endif // DISK_H
