#include <fstream>
#include <string>
#include "../models/Account.h"
using namespace std;

class AccountService {
    public: 

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

    // Account getAccountById(int id){

    // }

    // Account getAccountByaccountId(int id){

    // }

    // int getLatestAccountId(){

    // }

    // Account deposit(){

    // }

    // Account withdraw(){

    // }

    double getAccountBalance(){
        
    }
};