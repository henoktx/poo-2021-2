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

    Inbox* getInbox() {return &this->inbox;}
    
    void sendTweet(Tweet *tweet) {
        try {
            for (auto i : followers) {
                i.second->inbox.storeInTimeline(tweet);
            }
            this->inbox.storeInTimeline(tweet);
            this->inbox.storeInMyTweets(tweet);
            std::cout << "Your tweet was posted" << std::endl;
        } catch (std::string &error) {
            std::cout << error << std::endl;
        }       
    }

    void follow(User *other) {
        if (other->username ==  this->username) {
            throw std::string("You can't follow yourself");
            return;
        } else if (this->following.find(other->username)->first != other->username) {
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
            this->inbox.rmMsgsFrom(other->username);
            return;
        }
        std::cout << this->username << " didn't follow " << other->username << std::endl;
    }

    void like(int tweetID) {
        try {
            this->inbox.getTweet(tweetID)->like(this->username);
        } catch (std::string &error) {
            std::cout << error;
        }
    }

    void unfollowAll() {
        std::map<std::string, User*>::iterator it = this->following.begin();
        while (it != this->following.end()) {
            this->unfollow((it++)->second);
        }
    }

    void rejectAll() {
        std::map<std::string, User*>::iterator it = this->followers.begin();
        while (it != this->followers.end()) {
            (it++)->second->unfollow(this);
        }
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