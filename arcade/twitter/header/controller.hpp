#pragma once

#include <iostream>
#include "user.hpp"

class Controller {
private:
    std::map<std::string, User*> users;
    std::map<int, Tweet*> tweets;
    int nextTwId;

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

    std::string toString() {
        std::stringstream ss;
        ss << "Users [" << users.size() << "]\n";
        for (auto i : users) {
            ss << i.second->toString();
        }
        return ss.str();
    }

    Tweet* createTweet(std::string sender, std::string msg) {
        Tweet *tweet = new Tweet(this->nextTwId, sender, msg);
        this->tweets.insert(std::make_pair(this->nextTwId, tweet));
        this->nextTwId++;
        return tweet;
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

    void sendRt(std::string &username, int twID, std::string &msg) {
        Tweet *rt = this->createTweet(username, msg);
        try {
            User *user = this->getUser(username);
            Tweet *tweet = this->tweets.find(twID)->second;
            tweet->setRt(rt);
            user->sendTweet(rt);
        } catch (std::string &error) {
            if (error == "User not found") {
                std::cout << error;
            } else if (error == "Tweet not found") {
                std::cout << error;
            }
        }
    }

    void rmUser(std::string &username) {
        try {
            User *user = this->getUser(username);
            user->rejectAll();
            user->unfollowAll();
            for (auto i : user->getInbox()->getMyTweets()) {
                i->setDeleted();
            }
            this->users.erase(username);
            std::cout << username << " was deteled";
        } catch (std::string &error) {
            std::cout << error;
        }
    }
}; 