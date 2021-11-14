#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <string_view>
#include <iterator>


void readData(nlohmann::json& data) {
    std::string filePath = "film.json";
    std::ifstream fileData(filePath);
    fileData >> data;
}

bool searchActor(const std::string_view actor, nlohmann::json& films) {
    bool result = false;
    for (auto it = films.begin(); it != films.end(); it++) {
        auto film = films[it.key()];

        auto actors = film["starring"];
        for (auto subIt = actors.begin(); subIt != actors.end(); subIt++) { 
            if (subIt.key() == actor || subIt.key().find(actor) < subIt.key().length()) {
                std::cout << subIt.key() << ": " << it.key() << " (" << subIt.value() << ")." << std::endl;
                result = true;
                break;
            }
        }
    }

    return result;
}

int main() {
    nlohmann::json films;
    readData(films);

    //std::cout << films << std::endl;

    std::cout << "Search actor: " << std::endl;

    std::string actor;
    std::getline(std::cin, actor);
    if (!searchActor(actor, films)) {
        std::cout << "Sorry, i don`t know this actor.." << std::endl;
    }

    return 0;
}
