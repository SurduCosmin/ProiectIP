#include <iostream>
#include "structures.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;


bool checkInside(int i , int j)
{
    if(i < 0 || j <0 || j >= TABLE_LENGTH || i >= TABLE_LENGTH)
        return 0;
    return 1;
}

void generateStartpos()
{
    srand(time(NULL));
    start.x=rand()%4;
    start.y=rand()%4;
}


void findMovepos()
{
    // Plecand de la valoarea generata caut (W-A-S-D) unde e posibil . La enter ma opresc
    bool found;
    char direction;
    found=0;
    while(!found)
    {
        direction=0;
        switch((direction=getch()))
        {
        case 'W':
            if(checkInside(start.x-1 , start.y))
            {
                start.x=start.x-1;
                start.y=start.y;
            }

            cout<<start.x<<" "<<start.y<<"\n";

            break;

        case 'S':
            if(checkInside(start.x+1 , start.y))
            {
                start.x=start.x+1;
                start.y=start.y;
            }
            cout<<start.x<<" "<<start.y<<"\n";
            break;

        case 'A':
            if(checkInside(start.x , start.y-1))
            {
                start.x=start.x;
                start.y=start.y-1;
            }
            cout<<start.x<<" "<<start.y<<"\n";
            break;

        case 'D':
            if(checkInside(start.x,start.y+1))
            {
                start.x=start.x;
                start.y=start.y+1;
            }
            cout<<start.x<<" "<<start.y<<"\n";
            break;

        case 'E': /// enter
            found=1;
            cout<<"Ai ales pozitia"<<"\n";
            break;
        default :
            break;
        }
    }
}

void makeMove()
{
    char direction;
    bool endGame;
    endGame=1;

    while(endGame)
    {
        direction=0;
        findMovepos();
        switch((direction=getch()))
        {
        case 'W':
            if(checkInside(start.x-1 , start.y))
            {
                position destination; // unde adaug turnul
                destination.x=start.x-1;
                destination.y=start.y;

                //moveTower(start,destination);
                start.x=start.x-1;  // Ca sa raman de unde am plecat
                start.y=start.y;
            }
            break;

        case 'S':
            if(checkInside(start.x+1 , start.y))
            {
                position destination; // unde adaug turnul
                destination.x=start.x+1;
                destination.y=start.y;

                //moveTower(start,destination);
                start.x=start.x+1;  // Ca sa raman de unde am plecat
                start.y=start.y;
            }
            break;

        case 'A':
            if(checkInside(start.x , start.y-1))
            {
                position destination; // unde adaug turnul
                destination.x=start.x;
                destination.y=start.y-1;

                //moveTower(start,destination);
                start.x=start.x;  // Ca sa raman de unde am plecat
                start.y=start.y-1;
            }
            break;

        case 'D':
            if(checkInside(start.x , start.y+1))
            {
                position destination; // unde adaug turnul
                destination.x=start.x;
                destination.y=start.y+1;

                //moveTower(start,destination);
                start.x=start.x;  // Ca sa raman de unde am plecat
                start.y=start.y+1;
            }
            break;

        case VK_ESCAPE:
            endGame=0;

            break;


        }
    }
}



int main()
{
    generateStartpos();
    cout<<"Pozitia initiala : " <<start.x <<" "<< start.y<<"\n";
    makeMove();

    return 0;
}
