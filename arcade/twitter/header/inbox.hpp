#pragma once

#include "message.hpp"
#include <map>

class Inbox {
private:
    std::map<int, Message*> allMsg;
    std::map<int, Message*> unread;

public:
    void receiveNew(Message *tweet) {
        auto pairTweet = std::make_pair(tweet->getID(), tweet);
        allMsg.insert(pairTweet);
        unread.insert(pairTweet);
    }

    void store(Message* tweet) {
        if (unread.count(tweet->getID()) == 1) {
            if (tweet->getUsername() != unread.find(tweet->getID())->second->getUsername()) {
                std::cout << "This message was read" << std::endl;
            }
            unread.erase(tweet->getID());
            return;
        }
        std::cout << "This message is already read" << std::endl;
    }

    std::map<int, Message*> getUnread() {
        auto aux = this->unread;
        this->unread.clear();
        return aux;
    }

    std::map<int, Message*> getAllMsg() {
        return this->allMsg;
    }

    Message* getTweet(int id) {
        auto aux = allMsg.find(id);
        if (aux == allMsg.end()) {
            return nullptr;
        }
        return &(*aux->second);
    }

    std::string toString() {
        this->unread.clear();
        std::stringstream ss;
        for (auto i : allMsg) {
            ss << i.first << ":" << i.second->getUsername() << " | Message: " << i.second->to_string() << std::endl;
        }
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream &os, std::map<int, Message*> &map) {
        for (auto i : map) {
            os << i.first << ":" << i.second->getUsername() << " " << i.second->to_string() << std::endl;
        }
        return os;
    }
};
