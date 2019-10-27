#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
using namespace System;

void enqueue(int v);
int dequeue();
void print();
ConsoleKey menu();
void handleEnqueue();
void handleDequeue();
void handlePrint();
bool isValidKey(ConsoleKey k);
 
int q[10];
int last=-1;
 
void main()
{
    ConsoleKey k;
    while((k = menu()) != ConsoleKey::D4)
    {
        switch(k)
        {
        case ConsoleKey::D1 : handleEnqueue();break;
        case ConsoleKey::D2 : handleDequeue();break;
        case ConsoleKey::D3 : handlePrint();break;
        default : cout << "Error Aborting Program"<<endl;
                 exit(-1);
                 break;
        }
    }
}
 
void handleEnqueue()
{
    int v;
    Console::Clear();
    cout << "Enter the value to Enqueue"<< endl;
    cin >> v;
    enqueue(v);
    cout << "Please Enter to Continue..." <<endl;
    Console::ReadLine();
}
 
void handleDequeue()
{
    int v;
    Console::Clear();
    v = dequeue();
    if(v==-1)
    {
      cout << "Sorry nothing in queue to dequeue"<<endl;
    }
    else
    {
        cout <<"The value dequeued is "<<v<<endl;
    }
    cout << "Please Enter to Continue..." <<endl;
    Console::ReadLine();
}
 
void handlePrint()
{
    Console::Clear();
    cout << "Printing Queue"<<endl;
    print();
    cout << "Please Enter to Continue..." <<endl;
    Console::ReadLine();
}
ConsoleKey menu()
{
    Console::Clear();
    cout << " Welcome to Queue"<< endl;
    cout << " Press 1 to Enqueue value"<<endl;
    cout << " Press 2 to Dequeue-value"<<endl;
cout << " Press 3 to Print Queue"<<endl;
    cout << " Press 4 to Quit"<<endl;
ConsoleKey k = Console::ReadKey(true).Key;
    while(!isValidKey(k))
    {
        cout << "Please Enter Valid Key"<<endl;
        k = Console::ReadKey(true).Key;
    }
    return k;
}
 
bool isValidKey(ConsoleKey k)
{
    switch(k)
    {
    case ConsoleKey::D1 : return true;
    case ConsoleKey::D2 : return true;
    case ConsoleKey::D3 : return true;
    case ConsoleKey::D4 : return true;
    default :return false;
    }
}
void enqueue(int v)
{
    if(last == 9)
    {
        cout << "Queue Full" << endl;
    }
    else
    {
        last  = last + 1;
        q[last] = v;
    }
}
 
int dequeue()
{
    if(last == -1){
         cout << "Queue Empty" << endl;
         return - 1;
   }
    int temp = q[0];
    for( int i = 0 ; i < last ; i++)
    {
       q[i] = q[i+1];
    }
    last = last - 1;
    return temp;
}
 
void print()
{
    cout << "Printing Queue"<<endl;
    for(int i=0 ; i<=last ; i++)
    {
        cout << q[i] << endl;
    }
}
