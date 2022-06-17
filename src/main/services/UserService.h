#include <fstream>
#include <string>
#include "../models/Account.h"
using namespace std;


class UserService {

    public: 

    User registerUser(User user){

        if(isUserIdUnique(user.getId()) != 1){
            cout << "User with id: " << user.getId() << " Already exists. Can't Be Registered" << endl;
        }else if(isUserEmailUnique(user.getId(), user.getEmail()) != 1){
            cout << "Entered Email already exists" << endl;
        }else{

            ofstream usersFile("../output/database/database.txt", std::fstream::in | std::fstream::out | std::fstream::app);

            if(!usersFile){
                cout << "Error creating file" << endl;
            }

            usersFile << "user_id:"<<user.getId()<<":id:"<<user.getId() << endl;
            usersFile << "user_id:"<<user.getId()<<":firstName:"<<user.getFirstName() << endl;
            usersFile << "user_id:"<<user.getId()<<":lastName:"<<user.getLastName() << endl;
            usersFile << "user_id:"<<user.getId()<<":email:"<<user.getEmail() << endl;
            usersFile << "user_id:"<<user.getId()<<":password:"<<user.getPassword() << endl;

            usersFile.close();
            cout << "User Registered Successfully" << endl;
        }

        return user;
    }

    User getUserById(int id){
        ifstream inFile("../output/database/database.txt");
        string words;
        User user;
        int indexCounter = 0;
        while(inFile >> words) {
            if(words.find("user_id:"+to_string(id)) != -1){
                string value = words.substr(words.find_last_of(":")+1, words.length());

                switch(indexCounter){
                    case 0:
                        user.setId(stoi(value));
                        break;
                    case 1: 
                        user.setFirstName(value);
                        break;
                    case 2: 
                        user.setLastName(value);
                        break;
                    case 3: 
                        user.setEmail(value);
                        break;
                    case 4: 
                        user.setPassword(value);
                        break;              
                }

                indexCounter ++;
            }
        }

        inFile.close();
        return user;
    }

    bool isUserIdUnique(int id){
        ifstream inFile("../output/database/database.txt");
        string words;
        int occurenceCounter = 0;

        while(inFile >> words) {
            if(words.find("user_id:"+to_string(id)+":id:"+to_string(id)) != string::npos){
                occurenceCounter ++;
            }
        }

        if (occurenceCounter > 0) 
            return false;
        else
            return true;
    }

    bool isUserEmailUnique(int id, string email){
        ifstream inFile("../output/database/database.txt");
        string words;
        int occurenceCounter = 0;

        while(inFile >> words) {
            if(words.find(":email:"+email) != string::npos){
                occurenceCounter ++;
            }
        }

        if (occurenceCounter > 0) 
            return false;
        else
            return true;
    }

    int getLatestUserId(){
        ifstream inFile("../output/database/database.txt");
        string words;
        string lastOccurence;
        int occurenceCounter = 0;

        while(inFile >> words) {
            if(words.find(":id:") != string::npos){
                lastOccurence = words;
            }
        }
        
        cout << "Last occurence: " << lastOccurence << endl;

        if (occurenceCounter > 0) 
            return false;
        else
            return true;
    }

};