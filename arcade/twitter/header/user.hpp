#pragma once

#include <iostream>
#include "inbox.hpp"

class User{
private:
    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;

public:
    User(const std::string &username) : 
    username{username}, inbox{}, followers{}, following{} {}

    void follow(User *other) {
        if (this->following.find(other->username)->first != other->username) {
            this->following.insert(std::make_pair(other->username, other));
            other->followers.insert(std::make_pair(this->username, this));
            std::cout << this->username << " now is following " << other->username << std::endl;
            return;
        }
        std::cout << this->username << " is alredy follow " << other->username << std::endl;
    }

    void unfollow(User *other) {
        if (this->following.find(other->username)->first == other->username) {
            this->following.erase(other->username);
            other->followers.erase(this->username);
            std::cout << this->username << " unfollowed " << other->username << std::endl;
            return;
        }
        std::cout << this->username << " didn't follow " << other->username << std::endl;
    }

    void like(int tweetID) {
        if (this->inbox.getTweet(tweetID) == nullptr) {
            throw std::string("Message not found");
        } else {
            this->inbox.getTweet(tweetID)->like(this->username);
        }
    }

    Inbox* getInbox() {return &this->inbox;}

    void sendTweet(Message *tweet) {
        for (auto i : followers) {
            i.second->inbox.receiveNew(tweet);
        }
        this->inbox.receiveNew(tweet);
        this->inbox.store(tweet);
        std::cout << "Your tweet posted" << std::endl;
    }

    std::string toString() {
        std::stringstream ss;
        ss << this->username << ":\n  followers [" << followers.size() << "] ⟶ ";
        for (auto i : followers) {
            ss << i.second->username << (*followers.rbegin() != i ? ", " : "");
        }
        ss << "\n  following [" << following.size() << "] ⟶ ";
        for (auto i : following) {
            ss << i.second->username << (*following.rbegin() != i ? ", " : "");
        }
        ss << std::endl;
        return ss.str();
    }
};