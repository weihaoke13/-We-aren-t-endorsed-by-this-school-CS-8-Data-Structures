#ifndef BOARD_H
#define BOARD_H


#include<iostream>

using namespace std;



class Board
{
public:
    Board();
    void toh(int n);
};


//Board::Board(){
//    for(int i=0;i<10;i++){

//    }
//}
//void Board::toh(int n){

//    Stack s;
//    Disk d;
//    int i, x, a, b;
//    for (i = 0; i < (pow(2,n)); i++)
//    {
//        d.display1();
//        d.display2();
//        d.display3();
//        x = s.top_of_stack();
//        if (i % 2 == 0)
//        {
//            if (x == 1)
//            {
//                s.push3(s.pop1());
//            }
//            else if (x == 2)
//            {
//                s.push1(s.pop2());
//            }
//            else if (x == 3)
//            {
//                s.push2(s.pop3());
//            }
//        }
//        else
//        {
//            if (x == 1)
//            {
//                a = s.pop2();
//                b = s.pop3();
//                if (a < b && b != 999)
//                {
//                    s.push3(b);
//                    s.push3(a);
//                }
//                else if (a > b && a != 999)
//                {
//                    s.push2(a);
//                    s.push2(b);
//                }
//                else if (b == 999)
//                {
//                    s.push3(a);
//                }
//                else if (a == 999)
//                {
//                    s.push2(b);
//                }
//            }
//            else if (x == 2)
//            {
//                a = s.pop1();
//                b = s.pop3();
//                if (a < b && b != 999)
//                {
//                    s.push3(b);
//                    s.push3(a);
//                }
//                else if (a > b && a != 999)
//                {
//                    s.push1(a);
//                    s.push1(b);
//                }
//                else if (b == 999)
//                {
//                    s.push3(a);
//                }
//                else if (a == 999)
//                {
//                    s.push1(b);
//                }
//            }
//            else if (x == 3)
//            {
//                a = s.pop1();
//                b = s.pop2();
//                if (a < b && b != 999)
//                {
//                    s.push2(b);
//                    s.push2(a);
//                }
//                else if (a > b && a != 999)
//                {
//                    s.push1(a);
//                    s.push1(b);
//                }
//                else if (b == 999)
//                {
//                    s.push2(a);
//                }
//                else if (a == 999)
//                {
//                    s.push1(b);
//                }
//            }
//        }
//    }
//}

#endif // BOARD_H
