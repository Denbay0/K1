#pragma once

#include <vector>
#include "user.h"

class Chat {
private:
    std::vector<User*> users;
public:
    ~Chat();

    void registerUser(std::string login, std::string password, std::string name);
    User* login(std::string login, std::string password);
    void sendMessage(User& sender, User& recipient, const std::string& message);
    void sendMessageToAll(User& sender, const std::string& message);
    std::vector<User*>& getUsers();
};




