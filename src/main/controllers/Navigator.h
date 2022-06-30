#include <iostream>
#include <string>
#include "../services/UserService.h"
using namespace std;


class Navigator {
public:

    AccountService accountService;
    UserService userService;
    User currentUser;
    Account currentAccount;

    void signUp(){
        string firstName, lastName, email, password;

        cout << "========================================" << endl;
        cout << "===             SIGN UP              ===" << endl;
        cout << "========================================" << endl;


        cout << "Enter your firstName: ";
        cin.ignore();
        getline(cin, firstName);
        cout << "Enter your lastName: ";
        cin.ignore();
        getline(cin, lastName);
        cout << "Enter your email: ";
        cin.ignore();
        getline(cin, email);
        cout << "Enter your password: ";
        cin.ignore();
        getline(cin, password);        

        User userTosave(firstName, lastName, email, password);
        userTosave = userService.registerUser(userTosave);

        if(userTosave.getId() == -1){
            signUp();
        }else{
            login();
        }

    }

    void login(){
        string email, password;

        cout << "========================================" << endl;
        cout << "===              LOGIN               ===" << endl;
        cout << "========================================" << endl;

        cout << "Enter your email: ";
        cin.ignore();
        getline(cin, email);

        cout << "Enter your password: ";
        cin.ignore();
        getline(cin, password);

        currentUser = userService.login(email, password);
        if(currentUser.getId() == -1){
            cout << "Email or Password Incorrect. " << endl;
            login();
        }else{
            currentAccount = accountService.getAccountByUserId(currentUser.getId());
            dashboard();
        }
    }

    void withdrawOrDeposit(){

    }

    void dashboard(){

    }

    void start(){
        cout << "========================================" << endl;
        cout << "=== IKIRIRE BANK SYSTEM TECHNOLOGIES ===" << endl;
        cout << "========================================" << endl;

        cout << "1. Log In" << endl;
        cout << "2. Create Account " << endl;
        cout << "========================================" << endl;
        cout << "Your Choice: ";

        int option;
        cin >> option;

        switch(option){
            case 1: 
                cout<<endl<<endl;
                login();
                break;
            case 2:
                cout<<endl<<endl;
                signUp();
                break;
            default:
                cout << "You Entered Invalid input please try again" << endl;
                start();
        }

    }

};