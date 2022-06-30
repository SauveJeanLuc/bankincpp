#include <iostream>
#include <string>
// #include "./models/Account.h"
#include "./services/AccountService.h"
using namespace std;


int main( ){

    // cout << "Development of Bank begins Here." << endl;
    // User newUser;
    // newUser.setFirstName("SAUVE");
    // newUser.setLastName("Jean-Luc");
    // newUser.setEmail("me@gmail.com");
    // newUser.setPassword("12345");

    // Account account;
    // account.setId(1);
    // account.setUser(newUser);


    // // cout << newUser.getLastName() << endl;
    // // cout << account.getUser().getLastName() << endl;

    // cout << string::npos << endl;

    // UserService userService;

    // userService.registerUser(newUser);
    // string email = "me@gmail.com";
    // string password = "12345";

    // User testUser;
    // testUser = userService.login(email,password);

    // cout << "Test user username: " <<  testUser.getFirstName();
    
    AccountService accountService;
    Account fetchedAccount = accountService.getAccountById(1);

    cout << " Fetched account's user firstName: " << fetchedAccount.getUser().getFirstName() << endl;

}