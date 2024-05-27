#include "user.h"
#include <set>
#include <iostream>
#include <string>


User::User(std::string name) {
// TODO: Implement the additional constructor here!
    this->name = name;
}

User::User(User &&user) noexcept{
    this->name = std::move(user.name);
    this->friends = std::move(user.friends);
    user.name = "";
    user.friends.clear();
}

User& User::operator=(User &&user) noexcept{
    if(this != &user) {
        this->name = std::move(user.name);
        this->friends = std::move(user.friends);
        user.name = "";
        user.friends.clear();
    }
    return *this;
}


std::string User::getName() const {
    return name;
}

std::set<User> User::getFriends() const {
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

bool User::operator < (const User &user) {
    return this->name < user.name;
}

void User::setFriend(User user) {
    this->friends.insert(user);
}

// TODO: Implement the < operator overload here!
