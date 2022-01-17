#include "controller.hpp"

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
        } else if (cmd == "addUser") {
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
            } catch (char const *error) {
                std::cout << "User not found" << std::endl;
            }
            std::cout << std::endl;
        } else if (cmd == "twittar") {
            std::string tweet, user;
            ss >> user;
            tweet = ss.str();
            controle.sendTweet(user, tweet);
            std::cout << std::endl;
        } else if (cmd == "unread") {
            std::string username;
            ss >> username;
            controle.getUser(username)->inboxing().getUnread();
            std::cout << std::endl;
        } else if (cmd == "timeline") {
            std::string username;
            ss >> username;
            controle.getUser(username)->inboxing().toString();
            std::cout << std::endl;
        } else if (cmd == "like") {
            std::string username;
            int twId;
            ss >> username;
            ss >> twId;
            controle.getUser(username)->like(twId);
            std::cout << std::endl;
        } else if (cmd == "unfollow") {
            std::string unfollow, unfollower;
            ss >> unfollow;
            ss >> unfollower;
            controle.getUser(unfollower)->unfollow(controle.getUser(unfollow));
            std::cout << std::endl;
        } else {
            std::cout << "Invalid command" << std::endl;
            std::cout << std::endl;
        }
    }

    
    return 0;
}