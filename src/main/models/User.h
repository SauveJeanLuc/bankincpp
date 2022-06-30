#pragma once
#include <string>
#include <iostream>
using namespace std;

class User {
    private:
        int id;
        string firstName;
        string lastName;
        string email;
        string password;
    
    public:

        User(){
            
        }

        User(int inputId, string inputFirstName, string inputLastName, string inputEmail, string inputPassword){
            id = inputId;
            firstName = inputFirstName;
            lastName = inputLastName;
            email = inputEmail;
            password = inputPassword;
        }

        User(string inputFirstName, string inputLastName, string inputEmail, string inputPassword){
            firstName = inputFirstName;
            lastName = inputLastName;
            email = inputEmail;
            password = inputPassword;
        }

        void setId(int inputId){
            id = inputId;
        }
        int getId(){
            return id;
        }

        void setFirstName(string inputFirstName){
            firstName = inputFirstName;
        }
        string getFirstName(){
            return firstName;
        }

        void setLastName(string inputLastName){
            lastName = inputLastName;
        }
        string getLastName(){
            return lastName;
        }

        void setEmail(string inputEmail){
            email = inputEmail;
        }
        string getEmail(){
            return email;
        }

        void setPassword(string inputPassword){
            password = inputPassword;
        }
        string getPassword(){
            return password;
        }

};