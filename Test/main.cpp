#include <iostream>
#include "structures.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <thread>
using namespace std;


bool checkInside(int i , int j)
{
    if(i < 0 || j <0 || j >= TABLE_LENGTH || i >= TABLE_LENGTH)
        return 0;
    return 1;
}

bool endGame()
{
    bool canPlay;
    for(int index =0; index <4 ; index++ )
    {
        for(jndex=0; jndex <4; jndex++)
    if(checkInside(index-1,jndex)  && gameTable[index-1][jndex].top->currentSquare->value < gameTable[index][jndex].base->currentSquare->value )
    return 1;
    if(checkInside(index+1,jndex)  && gameTable[index+1][jndex].top->currentSquare->value < gameTable[index][jndex].base->currentSquare->value )
    return 1;
    if(checkInside(index,jndex+1)  && gameTable[index][jndex+1].top->currentSquare->value < gameTable[index][jndex].base->currentSquare->value )
    return 1;
    if(checkInside(index,jndex-1)  && gameTable[index][jndex-1].top->currentSquare->value < gameTable[index][jndex].base->currentSquare->value )
    return 1;
    }
    return 0;
}

//void generateStartpos()
//{
//    srand(time(NULL));
//    startPlayer1.x=rand()%4;
//    startPlayer1.y=rand()%4;
//
//    startPlayer2.x=rand()%4;
//    startPlayer2.y=rand()%4;
//}
//
//
//void findpositionPlayer1()
//{
//    bool found;
//    char direction;
//    found=0;
//    while(!found)
//    {
//        direction=0;
//        switch((direction=getch()))
//        {
//        case 'w':
//        case 'W':
//            if(checkInside(startPlayer1.x-1 , startPlayer1.y))
//            {
//                startPlayer1.x=startPlayer1.x-1;
//                startPlayer1.y=startPlayer1.y;
//            }
//            cout<<startPlayer1.x<<" "<<startPlayer1.y<<"\n";
//            break;
//
//        case 's':
//        case 'S':
//            if(checkInside(startPlayer1.x+1 , startPlayer1.y))
//            {
//                startPlayer1.x=startPlayer1.x+1;
//                startPlayer1.y=startPlayer1.y;
//            }
//            cout<<startPlayer1.x<<" "<<startPlayer1.y<<"\n";
//            break;
//
//        case 'a':
//        case 'A':
//            if(checkInside(startPlayer1.x , startPlayer1.y-1))
//            {
//                startPlayer1.x=startPlayer1.x;
//                startPlayer1.y=startPlayer1.y-1;
//            }
//            cout<<startPlayer1.x<<" "<<startPlayer1.y<<"\n";
//            break;
//
//        case 'd':
//        case 'D':
//            if(checkInside(startPlayer1.x,startPlayer1.y+1))
//            {
//                startPlayer1.x=startPlayer1.x;
//                startPlayer1.y=startPlayer1.y+1;
//            }
//            cout<<startPlayer1.x<<" "<<startPlayer1.y<<"\n";
//            break;
//
//        /// cazul de stop (A gasit pozitia)
//        case 'e':
//        case 'E': /// primul player se opreste la enter
//            found=1;
//            cout<<"Ai ales pozitia, player 1"<<"\n";
//            break;
//
//        default :
//            break;
//        }
//    }
//}
//
//
//void findpositionPlayer2()
//{
//    bool found;
//    char direction;
//    found=0;
//    while(!found)
//    {
//        direction=0;
//        switch((direction=getch()))
//        {
//        case KEY_UP:
//            if(checkInside(startPlayer2.x-1,startPlayer2.y))
//            {
//                startPlayer2.x=startPlayer2.x-1;
//                startPlayer2.y=startPlayer2.y;
//            }
//            cout<<startPlayer2.x<<" "<<startPlayer2.y<<"\n";
//            break;
//
//        case KEY_DOWN:
//            if(checkInside(startPlayer2.x+1,startPlayer2.y))
//            {
//                startPlayer2.x=startPlayer2.x+1;
//                startPlayer2.y=startPlayer2.y;
//            }
//            cout<<startPlayer2.x<<" "<<startPlayer2.y<<"\n";
//            break;
//
//        case KEY_LEFT:
//            if(checkInside(startPlayer2.x,startPlayer2.y-1))
//            {
//                startPlayer2.x=startPlayer2.x;
//                startPlayer2.y=startPlayer2.y-1;
//            }
//            cout<<startPlayer2.x<<" "<<startPlayer2.y<<"\n";
//            break;
//
//        case KEY_RIGHT:
//            if(checkInside(startPlayer2.x,startPlayer2.y+1))
//            {
//                startPlayer2.x=startPlayer2.x;
//                startPlayer2.y=startPlayer2.y+1;
//            }
//            cout<<startPlayer2.x<<" "<<startPlayer2.y<<"\n";
//            break;
//
//
//        case 'u':
//        case 'U': /// al doilea la space p=space
//            found=1;
//            cout<<"Ai ales pozitia,player2"<<"\n";
//            break;
//
//        default :
//            break;
//        }
//    }
//}
//
//
//
//
//void makeMove()
//{
//    char direction;
//    bool endGame;
//    endGame=1;
//
//    while(endGame)
//    {
//        direction=0;
//        //findpositionPlayer1();
//        //findpositionPlayer2();
//          std::thread a(findpositionPlayer1);
//          std::thread b(findpositionPlayer2);
//        a.join();
//        b.join();
//        switch((direction=getch()))
//        {
//        case 'w':
//        case 'W':
//
//            if(checkInside(startPlayer1.x-1 , startPlayer1.y))
//            {
//                position destination; // unde adaug turnul
//                destination.x=startPlayer1.x-1;
//                destination.y=startPlayer1.y;
//
//                //moveTower(startPlayer1,destination);
//                startPlayer1.x=startPlayer1.x-1;
//                startPlayer1.y=startPlayer1.y;
//            }
//            break;
//
//        case 's':
//        case 'S':
//            if(checkInside(startPlayer1.x+1 , startPlayer1.y))
//            {
//                position destination; // unde adaug turnul
//                destination.x=startPlayer1.x+1;
//                destination.y=startPlayer1.y;
//
//                //moveTower(startPlayer1,destination);
//                startPlayer1.x=startPlayer1.x+1;
//                startPlayer1.y=startPlayer1.y;
//            }
//            break;
//
//        case 'a':
//        case 'A':
//            if(checkInside(startPlayer1.x , startPlayer1.y-1))
//            {
//                position destination; // unde adaug turnul
//                destination.x=startPlayer1.x;
//                destination.y=startPlayer1.y-1;
//
//                //moveTower(startPlayer1,destination);
//                startPlayer1.x=startPlayer1.x;
//                startPlayer1.y=startPlayer1.y-1;
//            }
//            break;
//
//        case 'd':
//        case 'D':
//            if(checkInside(startPlayer1.x , startPlayer1.y+1))
//            {
//                position destination; // unde adaug turnul
//                destination.x=startPlayer1.x;
//                destination.y=startPlayer1.y+1;
//
//                //moveTower(startPlayer1,destination);
//                startPlayer1.x=startPlayer1.x;
//                startPlayer1.y=startPlayer1.y+1;
//            }
//            break;
//
//         case KEY_UP:
//          if(checkInside(startPlayer2.x-1,startPlayer2.y))
//          {
//              position destination; // unde adaug turnul
//              destination.x=startPlayer2.x-1;
//              destination.y=startPlayer2.y;
//              //moveTower(startPlayer2,destination);
//              startPlayer2.x=startPlayer2.x-1;
//              startPlayer2.y=startPlayer2.y;
//          }
//
//        break;
//
//        case KEY_DOWN:
//        if(checkInside(startPlayer2.x+1,startPlayer2.y))
//          {
//              position destination; // unde adaug turnul
//              destination.x=startPlayer2.x+1;
//              destination.y=startPlayer2.y;
//              //moveTower(startPlayer2,destination);
//              startPlayer2.x=startPlayer2.x+1;
//              startPlayer2.y=startPlayer2.y;
//          }
//
//        break;
//
//        case KEY_LEFT:
//        if(checkInside(startPlayer2.x,startPlayer2.y-1))
//          {
//              position destination; // unde adaug turnul
//              destination.x=startPlayer2.x;
//              destination.y=startPlayer2.y-1;
//              //moveTower(startPlayer2,destination);
//              startPlayer2.x=startPlayer2.x;
//              startPlayer2.y=startPlayer2.y-1;
//          }
//
//        break;
//
//        case KEY_RIGHT:
//        if(checkInside(startPlayer2.x,startPlayer2.y+1))
//          {
//              position destination; // unde adaug turnul
//              destination.x=startPlayer2.x;
//              destination.y=startPlayer2.y+1;
//              //moveTower(startPlayer2,destination);
//              startPlayer2.x=startPlayer2.x;
//              startPlayer2.y=startPlayer2.y+1;
//          }
//
//        break;
//
//        case VK_ESCAPE:
//            endGame=0;
//
//            break;
//
//
//        }
//    }
//}
//
//
//


int main()
{
    generateStartpos();
    cout<<"Player 1 start position :"<<startPlayer1.x<<" "<<startPlayer1.y<<"\n";
    cout<<"Player 2 start position :"<<startPlayer2.x<<" "<<startPlayer2.y<<"\n";
    makeMove();

    return 0;
}


