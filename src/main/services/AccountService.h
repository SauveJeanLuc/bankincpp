#include <fstream>
#include <string>
#include "../models/Account.h"
// #include "UserService.h"
#include <vector>
#include "../utils/UserUtil.h"
using namespace std;

class AccountService {
    public: 

    UserUtil userService;

    Account createAccount(User user){
        Account account;

        account.setId(getLatestAccountId() +1);

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
                        account.setBalance(stod(value));
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

    Account getAccountByUserId(int id){
        ifstream inFile("../output/database/accounts.txt");
        string words;
        string previousValue; // containing id
        string value;
        bool found;
        int indexCounter = 0;
        Account account;

        while( inFile >> words){

            if(indexCounter > 0){
                switch(indexCounter) {
                    case 0: 
                        account.setUser(userService.getUserById(stoi(value)));
                        break;
                    case 1:
                        account.setBalance(stod(value));
                }

                indexCounter ++;
            }else if(words.find("userId:"+to_string(id)) != string::npos){
                    found = true;
                    value = words.substr(words.find_last_of(":")+1, words.length());
                    previousValue = previousValue.substr(previousValue.find_last_of(":")+1, previousValue.length());
                    account.setId(stoi(previousValue));
                    indexCounter = 1;
            }else{
                previousValue = words;
            }

        }

        inFile.close();
        return account;
    }

    int getLatestAccountId(){

        ifstream inFile("../output/database/accounts.txt");
        string words;
        string lastOccurence = "not_found";
        int occurenceCounter = 0;

        while(inFile >> words) {
            if(words.find(":id:") != string::npos){
                lastOccurence = words;
            }
        }
        if(lastOccurence == "not_found")
            return 0;
        else
            return stoi(lastOccurence.substr(lastOccurence.find_last_of(':')+1, lastOccurence.length()));
    } 

    void depositOrWithdraw(int id, double newAmount, bool isDeposit){

        ifstream inFile("../output/database/accounts.txt");

        bool found = false;
        string words;
        vector<string> fileContents;

        int indexCounter = 0;
        while(inFile >> words) {
            string value;
            if(words.find("account_id:"+to_string(id)) != string::npos){

                found = true;

                if(indexCounter == 2){
                    double oldBalance = stod( words.substr(words.find_last_of(":")+1, words.length()) );
                    double newBalance;
                    if(isDeposit){
                        newBalance = oldBalance+newAmount;
                    }
                    else{
                        if(newBalance > oldBalance){
                            cout << "Amount to withdraw is greater than amount available" << endl;
                        }
                        else{
                            newBalance = oldBalance - newAmount;
                        }           
                    }
                    value = "account_id:"+to_string(id)+":balance:"+to_string(newBalance);
                    fileContents.push_back(value);
                }else{
                    fileContents.push_back(words);
                }

                indexCounter ++;
            }else{
                fileContents.push_back(words);
            }
        }

        if(!found) {
            cout << "Account with Id " << id << " Not found " << endl;
        }

        inFile.close();
        
        ofstream outFile("../output/database/accounts.txt");

        for (const string& line : fileContents) {
            outFile << line << endl;
        }        

        outFile.close();
        return;

    }

};