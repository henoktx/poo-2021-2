#pragma once

#include <iostream>
#include <sstream>
#include <set>

class Message {
private:
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    
public:
    Message(int id, const std::string &username, const std::string &msg) :
    id(id), username(username), msg(msg) {}

    void like(const std::string &username) {
        this->likes.insert(username);
        std::cout << "Message liked by " << username << std::endl;
    }

    std::string to_string() {
        std::stringstream ss;
        ss << this->msg << std::endl;
        ss << "Likes: " << likes.size() << " | Users: ";
        for (auto i : likes) {
            ss << i << (*--likes.end() != i ? ", " : "");
        }
        ss << "\n";
        return ss.str();
    }

    int getID() {return this->id;}

    std::string getUsername() {return this->username;}
};