#include<iostream>
#include<ctype.h>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/timeb.h>
#include<sys/utime.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#include<limits>
#include<iomanip>
#include<conio.h>
#include<string>
#include<windows.h>
#include<iostream>
using namespace std;
fstream ofs;
 ifstream File;
int main(){
int space[5][10] = {0};
int space1[5][10];
//cout<<"Press 0 for exit , 1 for car , 2 for scooter";
int l=9;
int id;
int timer;
int ch;
int counter=0;
int queuee[10]={0};
int abc=0;
int s=0,flag=0;
int queueflag=0;
string x;
cout<<"----------------------------------------------------------------------"<<endl;
cout<<"\t\tWELCOME TO PARKING MANAGEMENT OS"<<endl;
cout<<"----------------------------------------------------------------------"<<endl;
cout<<"OS Module Loading"<<endl;
Sleep(5000);
cout<<"\nEnter your command:"<<endl;
hello:
    int u=0;
            int p=0;
            int big=0;
cout<<"#";
cin>>x;
if(x=="arrival")
{
    ch=1;
}
else if (x=="depart")
{
    ch=2;
}
else if(x=="view")
{
    ch=3;
}
else if(x=="sleep")
{
    ch=4;
}
else if(x=="exit")
{
    ch=5;
}
else if(x=="write")
{
    ch=6;
}
else if(x=="read")
{
    ch=7;
}
else
    {
      ch=10;
    }
switch(ch)
{
    case 1:
while(l != 0 ){

    counter++;
    starting:
    cout<<"Press\n'1' for Scooter\n'2' for Car"<<endl;
    cin>>l;
if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"You have entered wrong input"<<endl;
goto starting;
}
if(l>2 || l<1)
{
    cout<<"Wrong Input! Enter Again!\n";
    goto starting;
}
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(l == 1){
                if(space[i][j] == 0){
                    space[i][j] = counter ;
                    cout<<"Booking id:"<<counter<<endl;
                    cout<<"Location: ("<<i+1<<","<<j+1<<")"<<endl;
                    goto hello;
                }
            }
            if(l == 2){
                if( j!= 9){
                    if(space[i][j] == 0 && space[i][j+1] == 0){
                        space[i][j] = counter ;
                        space[i][j+1] = counter;
                         cout<<"Booking id:"<<counter<<endl;
                        cout<<"Location: ("<<i+1<<","<<j+1<<") ("<<i+1<<","<<j+2<<")"<<endl;
                        goto hello;
                    }
                }
            }


            }
        }

        for(int f=0;f<10;f++)
        {
            if(queuee[f]==0)
            {
                queueflag=1;
                break;

            }
            else
                {
                queueflag=0;
            }

        }
        if (queueflag==1)
        {
             if(l==1)
                {
                         cout<<"No space available"<<endl;
                        cout<<"Checking queue"<<endl;
                        cout<<"Vehicle Queued"<<endl;
                        queuee[abc]=1;
                        abc++;
                        goto hello;
                }
                    if(l==2)
                {
                         cout<<"No space available"<<endl;
                        cout<<"Checking queue"<<endl;
                        cout<<"Vehicle Queued"<<endl;
                        queuee[abc]=2;
                        abc++;
                        goto hello;
                }
                    if(l==3)
                {

                        goto hello;
                }
            }
           else
            {

                        cout<<"No space available"<<endl;
                        cout<<"Checking queue"<<endl;
                cout<<"Queue list is full.Try again later"<<endl;
                goto hello;

            }

    }break;

    case 2:
        star:
        cout<<"Enter your Vehicle Id:";
        cin>>id;
        if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"You have entered wrong input"<<endl;
goto star;
}
      for(int i = 0 ; i < 5 ; i++)
        {
        for(int j = 0 ; j < 10 ; j++)
        {
            if(space[i][j]==id)
            {
                space[i][j]=0;
                s++;
            }

    }
        }
        if(s==0)
        {
           cout<<"Invalid booking id!"<<endl;
           goto hello;
        }
        if(s==1)
        {
            cout<<"A Scooter has Departed.One block space has been emptied\n";
        }
        if(s==2)
        {
            cout<<"A car has Departed.Two block space has been emptied\n";
        }
        int f;
        for(f=0;f<10;f++)
        {

             if(queuee[f]==1)
            {
                 for(int i = 0 ; i < 5 ; i++){
                       for(int j = 0 ; j < 10 ; j++){
                            if(space[i][j]==0)
                            {
                               space[i] [j]=counter;
                               counter ++;
                               queuee[f]=0;
                               cout<<"A scooter has been Added to the parking lot which was waiting in the queue!\n";
                               cout<<"Vehicle id is:"<<counter-1<<"\n";
                               break;
                            }
                       }}


            }
            else if(queuee[f]==2)
            {
               for(int i = 0 ; i < 5 ; i++){
                       for(int j = 0 ; j < 10 ; j++){
                            if(space[i][j]==0&&space[i][j+1]==0)
                            {
                               space[i][j]=counter;
                               space[i][j+1]=counter;
                               counter ++;
                               queuee[f]=0;
                               cout<<"A car has been Added to the parking lot which was waiting in the queue!\n";
                               cout<<"Vehicle Id is:"<<counter-1<<"\n";

                            }
                       }}




            }
            else
                 flag=1;
        }
        /*if(flag==1)
        {
            cout<<"----------------------------------------------";
            cout<<"\nQueue is Currently Empty\n";
        }*/
        goto hello;
        break;
    case 3:
            for(int i = 0 ; i < 5 ; i++)
        {
        for(int j = 0 ; j < 10 ; j++)
        {
            cout<<space[i][j]<<"\t";
        }
        cout<<endl;

        }
        goto hello;
        break;
    case 4:
        slee:
        cout<<"Enter the sleep time in secs:"<<endl;
            cin>>timer;

if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"You have entered wrong input"<<endl;
goto slee;
}
            SendMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,(LPARAM)2);
            Sleep(timer*1000);
            SendMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,(LPARAM)-1);
            goto hello;
            break;

            case 5: break;
            case 6:
                ofs.open("aa.txt", ios::out | ios::trunc);
                    for(int k = 0 ; k < 5 ; k++){
                        for(int l = 0 ; l < 10 ; l++){
                            ofs<<space[k][l]<<endl;
                        }
                    }
                    ofs.close();
                    cout<<"File Created!"<<endl;
                    cout<<"Instance Saved!"<<endl;
                    goto hello;
                    break;
            case 7:
            cout<<"Retreiving previous instance"<<endl;
            File.open("aa.txt");
    while(!File.eof())
    {
        File >> space[p][u];
        u++;
        if(u>9)
        {
            p++;
            u=0;
        }

    }

    File.close();
     for(int y=0;y<5;y++)
        for(int z=0;z<10;z++)
        {
            if(space[y][z]>big)
                big=space[y][z];
        }
        counter=big;

            goto hello;
            break;


default: cout<<"Enter a proper command!"<<endl;
            goto hello;

}
}
