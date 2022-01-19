#include "../header/controller.hpp"

int main() {
    Controller controle;
    while (true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << std::endl;
        std::cout << std::endl;

        if (cmd == "end") {
            break;
        } else if (cmd == "add") {
            std::string name;
            ss >> name;
            controle.addUser(name);
            std::cout << std::endl;
        } else if (cmd == "show") {
            std::cout << controle.toString();
            std::cout << std::endl;
        } else if (cmd == "follow") {
            std::string following, follower;
            ss >> following;
            ss >> follower;
            try {
                controle.getUser(follower)->follow(controle.getUser(following));
            } catch (std::string &error) {
                std::cout << error << std::endl;
            }
            std::cout << std::endl;
        } else if (cmd == "twittar") {
            std::string tweet, user, aux;
            ss >> user;
            while (ss >> aux) {tweet += aux + " ";}
            try {
                controle.sendTweet(user, tweet);
            } catch (std::string &error) {
                std::cout << error << std::endl;
            }
            std::cout << std::endl;
        } else if (cmd == "unread") {
            std::string username;
            ss >> username;
            auto aux = controle.getUser(username)->getInbox()->getUnread();
            for (auto i : aux) {
                std::cout << i.first << ":" << i.second->getUsername() << " | Message: " << i.second->to_string() << std::endl;
            }
        } else if (cmd == "timeline") {
            std::string username;
            ss >> username;
            std::cout << controle.getUser(username)->getInbox()->toString();
        } else if (cmd == "like") {
            std::string username;
            int twId;
            ss >> twId;
            ss >> username;
            try {
                controle.getUser(username)->like(twId);
            } catch (std::string &error) {
                if (error == "User not found") {
                    std::cout << error << std::endl;
                } else if (error == "Message not found") {
                    std::cout << error << std::endl;
                }
            }
            std::cout << std::endl;
        } else if (cmd == "unfollow") {
            std::string unfollow, unfollower;
            ss >> unfollow;
            ss >> unfollower;
            try {
                controle.getUser(unfollower)->unfollow(controle.getUser(unfollow));
            } catch (std::string &error) {
                std::cout << error << std::endl;
            }
            std::cout << std::endl;
        } else {
            std::cout << "Invalid command" << std::endl;
            std::cout << std::endl;
        }
    }

    
    return 0;
}