#include<iostream>
#include<stdio.h>
#include<cmath>
#include<conio.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <cstring>

using namespace std;

string passwd()
{
            char ch;
            int x=0,Max=10;
            char ar[100];
            while(1)
            {
                ch=getch();
                if(ch==13)
                {
                    ar[x]='\0';
                    break;
                }
                if(ch==8 && x!=0)
                {
                    cout<<"\b \b";
                    if(x<=Max && x>0)
                        x--;
                }
                else if(x<Max && ch!=8)
                {
                    cout<<"*";
                    ar[x]=ch;
                    x++;
                }
            }
            return ar;
}


void score()
{
    char ch;
    fstream newfile;
    cout<<"Want to see your score?Y/N: ";
    cin>>ch;
    if(ch=='Y')
    {

        newfile.open("score.txt", ios::in);
        if (newfile.is_open()){ //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
        cout << tp << "\n"; //print the data of the string
      }
    }
      newfile.close(); //close the file object.
    }

}

void deadline()
{
    fstream newfile;
    newfile.open("deadline.txt", ios::in);
        if (newfile.is_open()){ //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
        cout << tp << "\n"; //print the data of the string
      }
    }
      newfile.close();
}

void stud_entry()
{
    while(1)
    {
        int ch;
        cout<<"\n******************************************************\n";
        cout<<"1.ASSIGNMENT SUBMISSION\n";
        cout<<"2.ASSIGNMENT DEADLINE\n";
        cout<<"3.ASSIGNMENT SCORE\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: //submit();
            break;
            case 2: deadline();
            break;
            case 3: score();
            break;
            case 4: return;
            default:
                cout<<"Invalid Choice!!!\n";

        }
    }
}

void staff_score()
{
    string asmt,sc;
    cout<<"Enter the assignment-name: ";
    cin>>asmt;
    cout<<"Enter the score: ";
    cin>>sc;
    ofstream reg("score.txt",ios::app);
    reg<<asmt<<' '<<sc<<' '<<endl;
    system("cls");
}

void staff_deadline()
{
    string asmt,dl;
    cout<<"Enter the assignment-name: ";
    cin>>asmt;
    cout<<"Enter the deadline: ";
    cin>>dl;
    ofstream reg("deadline.txt",ios::app);
    reg<<asmt<<' '<<dl<<' '<<endl;
    system("cls");

}

void staff_post()
{
    string asmt= "";
    cout<<"Enter the Assignment Question: ";
    cin.ignore();
    getline(cin, asmt, '\n');
    ofstream reg("staff_post.txt",ios::app);
    reg<<asmt<<'\n'<<endl;

}

void staff_entry()
{
    while(1)
    {
        int ch;
        cout<<"\n******************************************************\n";
        cout<<"1.POST ASSIGNMENT\n";
        cout<<"2.ASSIGNMENT DEADLINE\n";
        cout<<"3.ASSIGNMENT SCORE\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: staff_post();
            break;
            case 2: staff_deadline();
            break;
            case 3: staff_score();
            break;
            case 4: return;
            default:
                cout<<"Invalid Choice!!!\n";

        }
    }
}

void staff_login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        pass=passwd();

        ifstream input("staff.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello "<<user<<"\nLOGIN SUCCESS!!!\n";
                cin.get();
                staff_entry();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        }
}

void staff_register()
{
    string un,pass;
    cout<<"Enter userName: ";
    cin>>un;
    cout<<"Enter Password: ";
    pass=passwd();
    ofstream reg("staff.txt",ios::app);
    reg<<un<<' '<<pass<<' '<<endl;
    system("cls");
}

void staff()
{
    int ch;
    cout<<"1.Register\n";
    cout<<"2.Login\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1: staff_register();
            break;
        case 2: staff_login();
            break;
        default:
            cout<<"INVALID CHOICE!!";
    }
}

void Register()
{
        string name,dept,usn,sem,username,pass;
        cout<<"Enter USN: \n";
        cin>>usn;
        cout<<"Enter Name: \n";
        cin>>name;
        cout<<"Enter department: \n";
        cin>>dept;
        cout<<"Enter semester: \n";
        cin>>sem;
        cout<<"Enter User Name: \n";
        cin>>username;
        cout<<"Enter password: \n";
        pass=passwd();

        ofstream reg("database.txt",ios::app);
        reg<<usn<<' '<<name<<' '<<dept<<' '<<sem<<' '<<username<<' '<<pass<<' '<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";

}

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        pass=passwd();

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello "<<user<<"\nLOGIN SUCCESS\n";
                cin.get();
                stud_entry();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        }
}

void student()
{
        int a;
        cout<<"1.Register\n";
        cout<<"2.LogIn\n";

        cout<<"Enter your choice: \n";
        cin>>a;
        switch(a)
        {
            case 1: Register();
            break;
            case 2: login();
            break;
            default:
            cout<<"INVALID CHOICE!!";
        }
}

int main()
{
    cout<<"\t\t\t\tCMR INSTITUTE OF TECHNOLOGY\n";
    cout<<"\t\t\t\tASSINGMENT SUBMISSION PORTAL\n";
    cout<<"\n";
    while(1)
    {
        int ch;
        cout<<"\n--------------------------------------------\n";
        cout<<"1.STUDENT\n";
        cout<<"2.STAFF\n";
        cout<<"3.EXIT\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: student();
            break;
            case 2: staff();
            break;
            case 3: return 0;
            break;
            default:
            cout<<"INVALID INPUT!!!!!!";
        }
    }
    return 0;
}
