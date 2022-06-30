#pragma once
#include <string>
#include <iostream>
#include "User.h"
using namespace std;

class Account {

    private:
        int id;
        User user;
        double balance;

    public:
        Account(){
            balance = 0.0;
        }       

        Account(int inputId, User inputUser){
            id = inputId;
            user = inputUser;
            balance = 0.0;
        }

        void setId(int inputId){
            id = inputId;
        }
        int getId(){
            return id;
        }

        void setUser(User inputUser){
            user = inputUser;
        }
        User getUser(){
            return user;
        }

        void setBalance(double userBalance){
            balance = userBalance;
        }
        double getBalance(){
            return balance;
        }        

};