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
        std::cout << "New message received" << std::endl;
    }

    void store(Message* tweet) {
        if (unread.count(tweet->getID()) == 1) {
            unread.erase(tweet->getID());
            std::cout << "This message was read" << std::endl;
            return;
        }
        std::cout << "This message is already read" << std::endl;
    }

    std::map<int, Message*> getUnread() {
        return this->unread;
    }

    std::map<int, Message*> getAllMsg() {
        return this->allMsg;
    }

    Message* getTweet(int id) {
        auto aux = unread.find(id);
        if (aux == unread.end()) {
            return nullptr;
        }
        return &(*aux->second);
    }

    std::string toString() {
        std::stringstream ss;
        for (auto i : allMsg) {
            ss << "ID - " << i.first << " | Message : " << i.second->to_string() << std::endl;
        }
        return ss.str();
    }
};
