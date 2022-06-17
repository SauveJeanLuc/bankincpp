#include <fstream>
#include <string>
#include "../models/Account.h"
using namespace std;


class UserService {

    public: 

    User registerUser(User user){

        if(isUserEmailUnique(user.getId(), user.getEmail()) != 1){
            cout << "Entered Email already exists" << endl;
        }else{
            user.setId(getLatestUserId() +1);
            ofstream usersFile("../output/database/users.txt", std::fstream::in | std::fstream::out | std::fstream::app);

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
        ifstream inFile("../output/database/users.txt");
        string words;
        bool found = false;
        User user;
        user.setId(-1); // Indicating that user is not found
        int indexCounter = 0;
        while(inFile >> words) {
            if(words.find("user_id:"+to_string(id)) != string::npos){
                found = true;
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

        if(!found){
            cout << "User with Id " << id << "Not found" << endl;
        }

        inFile.close();
        return user;
    }

    bool isUserIdUnique(int id){
        ifstream inFile("../output/database/users.txt");
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
        ifstream inFile("../output/database/users.txt");
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
        ifstream inFile("../output/database/users.txt");
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

    User login(string email, string password) {

        ifstream inFile("../output/database/users.txt");
        string words;
        int userId = 0;

        while(inFile >> words) {
            if( (words.find("email:"+email) != string::npos) ){
                words.erase(words.find("email")-1, words.length());
                userId = stoi( words.substr(words.find(":")+1,words.length()) );
            }
        }
        User notFoundUser;
        notFoundUser.setId(-1);

        if(userId != 0){
            User user = getUserById(userId);
            if(user.getPassword() == password)
                return user;
            else
                return notFoundUser;
        }else{
            return notFoundUser;
        }

    }

};