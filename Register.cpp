//
// Created by pasha on 16.07.2023.
//
#include <iostream>
#include <fstream>
#include "Register.h"
using namespace std;

void user::registration()
{
    cout<<"Enter user name= ";
    cin >> username;
    cout << "Enter password= ";
    cin >> password;

    fstream filout;
    filout.open( "registration.txt");
    if(!filout)
    {
        cout<<"\nCannot open file\n";
    }
    else
    {
        int f =0;
        while (!filout.eof())
        {
            string log_cheker = "";
            filout >> log_cheker;
            if (log_cheker == username)
            {
                f = 1;
                break;
            }
        }
        filout.close();
        if (f == 0)
        {
            fstream filout;
            filout.open( "registration.txt",ios::app);
            cout << "\n";
            filout << username <<endl<< password<<endl;
            cout<<"\nYou are registered.\n";
        }
        else{
            cout<<"Username already exist"<<endl;
        }

        filout.close();
    }
}
void user::login()
{
    int i =0 ;
    fstream filout;
    filout.open( "registration.txt");
    if (!filout.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        string login_correct;
        string pass_correct;
        cout << "Login: "; cin >> login_correct;
        cout << endl;
        cout << "Password: "; cin >> pass_correct;
        while (!filout.eof())
        {
            string log_cheker = "";
            string psw_cheker = "";

            filout >> log_cheker;
            filout >> psw_cheker;

            if(login_correct == log_cheker & pass_correct == psw_cheker)
            {
                cout << "Correct!" << endl;
                i = 1;
                break;
            }
        }
        if(i == 0)
        {
            cout << "Try again!" << endl;
        }
        filout.close();
    }

}