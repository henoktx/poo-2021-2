#pragma once

#include "tweet.hpp"
#include <map>
#include <list>

class Inbox {
private:
    std::map<int, Tweet*> timeline;
    std::map<int, Tweet*> myTweets;

public:
    void storeInTimeline(Tweet *tweet) {
        if (this->timeline.find(tweet->getID())->second == tweet) {
            throw std::string("This tweet has already been stored");
        }
        this->timeline.insert(std::make_pair(tweet->getID(), tweet));
    }

    std::list<Tweet*> getTimeline() {
        std::list<Tweet*> timelineList {};
        for (auto i : this->timeline) {
            timelineList.push_back(i.second);
        }
        return timelineList;
    }

    Tweet* getTweet(int id) {
        auto aux = this->timeline.find(id);
        if (aux == this->timeline.end()) {
            throw std::string("Tweet not found");
        }
        return &(*aux->second);
    }

    void rmMsgsFrom(std::string username) {
        std::list<int> idsRm {};
        for (auto i : this->timeline) {
            if (i.second->getSender() == username) {
                idsRm.push_back(i.first);
            }
        }
        for (auto j : idsRm) {
            this->timeline.erase(j);
        }
    }

    void storeInMyTweets(Tweet *tweet) {
        if (this->myTweets.count(tweet->getID()) == 1) {
            std::cout << "This tweet has already been stored" << std::endl;
            return;
        }
        this->myTweets.insert(std::make_pair(tweet->getID(), tweet));
    }

    std::list<Tweet*> getMyTweets() {
        std::list<Tweet*> myTweetsList {};
        for (auto i : this->myTweets) {
            myTweetsList.push_back(i.second);
        }
        return myTweetsList;
    }

    std::string toString() {
        std::stringstream ss;
        for (auto i : timeline) {
            ss << i.first << ":" << i.second->getSender() << " | " << i.second->to_string() << std::endl;
        }
        return ss.str();
    }
};
