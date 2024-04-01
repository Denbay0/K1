#include "chat.h"
#include <iostream>
#include <algorithm>

Chat::~Chat() {
    for (auto user : users) {
        delete user;
    }
}

void Chat::registerUser(std::string login, std::string password, std::string name) {
    users.push_back(new User(login, password, name));
}

User* Chat::login(std::string login, std::string password) {
    std::transform(login.begin(), login.end(), login.begin(), ::tolower);
    auto it = std::find_if(users.begin(), users.end(), [&](const User* user) {
        std::string userLogin = user->getLogin();
        std::transform(userLogin.begin(), userLogin.end(), userLogin.begin(), ::tolower);
        return userLogin == login && user->getPassword() == password;
        });

    if (it != users.end()) {
        return *it;
    }
    else {
        return nullptr;
    }
}

void Chat::sendMessage(User& sender, User& recipient, const std::string& message) {
    recipient.receiveMessage(sender.getName(), message);
}

void Chat::sendMessageToAll(User& sender, const std::string& message) {
    std::cout << "Sending message to all..." << std::endl;
    for (const auto& user : users) {
        if (user != &sender) {
            user->receiveMessage(sender.getName(), message);
        }
    }
}

std::vector<User*>& Chat::getUsers() {
    return users;
}
