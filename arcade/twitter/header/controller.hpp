#pragma once

#include <iostream>
#include "user.hpp"

class Controller {
private:
    std::map<std::string, User*> users;
    std::map<int, Message*> tweets;
    int nextTwId;

    Message* createTweet(std::string sender, std::string msg) {
        Message *tweet = new Message(nextTwId, sender, msg);
        this->tweets.insert(std::make_pair(nextTwId, tweet));
        nextTwId++;
        return tweet;
    }

public:
    Controller() : users{}, tweets{}, nextTwId{0} {}

    ~Controller() {
        for (auto i : tweets) {
            delete i.second;
        }
        for (auto j : users) {
            delete j.second;
        }
    }

    void addUser(std::string &username) {
        if (this->users.find(username)->first != username) {
            User *user = new User(username);
            this->users.insert(std::make_pair(username, user));
            std::cout << username << " has been successfully add" << std::endl;
            return;
        }
        std::cout << username << " has already been add" << std::endl;
    }

    User* getUser(const std::string &username) {
        if (this->users.find(username)->first == username) {
           return this->users.find(username)->second;
        } 
        throw std::string("User not found");
    }

    void sendTweet(const std::string &username, const std::string &msg) {
        if (this->users.find(username)->first == username) {
            this->getUser(username)->sendTweet(this->createTweet(username, msg));
            return;
        }
        throw std::string("User not found");
    }

    std::string toString() {
        std::stringstream ss;
        ss << "Users [" << users.size() << "]\n";
        for (auto i : users) {
            ss << i.second->toString();
        }
        return ss.str();
    }
}; 