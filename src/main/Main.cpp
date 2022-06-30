#include <iostream>
#include <string>
#include "./services/UserService.h"
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
    // Account fetchedAccount = accountService.getAccountById(1);

    // UserService userService;
    // User user = userService.getUserById(1);
    
    // cout << " Fetched account's user firstName: " << fetchedAccount.getUser().getFirstName() << endl;
    // cout << " Fetched user's user firstName: " << user.getFirstName() << endl;
    // accountService.depositOrWithdraw(1, 100.00, true);
    accountService.depositOrWithdraw(1, 100.00, false);
    // accountService.tryUpdatingFile();

    return 1;
}