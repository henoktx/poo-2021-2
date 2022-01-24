#pragma once

#include <iostream>
#include <sstream>
#include <set>

class Tweet {
private:
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    Tweet *rt;
    bool deleted;
    
public:
    Tweet(int id, const std::string &username, const std::string &msg) :
    id{id}, username{username}, msg{msg}, rt{nullptr}, deleted{false} {}

    int getID() {return this->id;}

    std::string getSender() {return this->username;}

    std::string getMsg() {return this->msg;}
    
    std::string to_string() {
        std::stringstream ss;
        ss << this->msg << "[";
        for (auto i : likes) {
            ss << i << (*--likes.end() != i ? ", " : "");
        }
        ss << "]\n";
        if (rt != nullptr) {
            ss << "     " << rt->getID() << ":" << rt->getSender() << " | " << rt->to_string();
        }
        return ss.str();
    }

    void like(const std::string &username) {
        this->likes.insert(username);
        std::cout << "tweet liked by " << username << std::endl;
    }

    std::set<std::string> getLikes() {return this->likes;}

    void setRt(Tweet *tweet) {this->rt = tweet;}

    void setDeleted() {
        this->deleted = true;
        this->msg = "This tweet was deleted";
        this->username.clear();
        this->likes.clear();
    }

    bool isDeleted() {return this->deleted;}
};