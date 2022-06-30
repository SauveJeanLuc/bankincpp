#include <fstream>
#include <string>
#include "../models/Account.h"
#include "UserService.h"
using namespace std;

class AccountService {
    public: 

    UserService userService;

    Account createAccount(User user){
        Account account;

        // account.setId(getLatestAccountId() +1);
        account.setId(1);

        ofstream accountsFile("../output/database/accounts.txt", std::fstream::in | std::fstream::out | std::fstream::app);

        if(!accountsFile){
            cout << "Error creating file" << endl;
        }

        accountsFile << "account_id:"<<account.getId()<<":id:"<< account.getId() << endl;
        accountsFile << "account_id:"<<account.getId()<<":userId:"<<user.getId() << endl;
        accountsFile << "account_id:"<<account.getId()<<":balance:"<<to_string(0.0) << endl;

        accountsFile.close();
        cout << "Account Registered Successfully" << endl;
        
        return account;
    }

    Account getAccountById(int id){
        ifstream inFile("../output/database/accounts.txt");

        bool found = false;
        Account account;
        account.setId(-1); // Indicating that account is not found
        string words;
        int indexCounter = 0;
        while(inFile >> words) {
            if(words.find("account_id:"+to_string(id)) != string::npos){
                found = true;
                string value = words.substr(words.find_last_of(":")+1, words.length());

                switch(indexCounter) {
                    case 0:
                        account.setId(stoi(value));
                        break;
                    case 1:
                        account.setUser(userService.getUserById(stoi(value)));
                        break;
                    case 2: 
                        account.setBalance(stoi(value)); // convert to double not int
                        break;
                }

                indexCounter ++;
            }
        }

        if(!found) {
            cout << "Account with Id " << id << " Not found " << endl;
        }

        inFile.close();
        return account;
    }

    // Account getAccountByaccountId(int id){

    // }

    // int getLatestAccountId(){

    // }

    // Account deposit(){

    // }

    // Account withdraw(){

    // }

    // double getAccountBalance(){
        
    // }
};