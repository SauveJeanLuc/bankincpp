#include "../models/User.h"

class UserUtil {

    public: 

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
            cout << "User with Id " << id << " Not found" << endl;
        }

        inFile.close();
        return user;
    }

};