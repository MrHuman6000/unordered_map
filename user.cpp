#include <iostream>
#include <random>
#include <unordered_map>
#include <string>

struct User {
    unsigned long long id;
    int age;
};

unsigned long long generateRandomID() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis;

    return dis(gen);
}

int main() {

    // Creating unordered_map:
    // key   = user's name (string)
    // value = User object
    std::unordered_map<std::string, User> users;

    // Add users
    users["Alice"] = {generateRandomID(), 25};
    users["Bob"] = {generateRandomID(), 30};
    users["Charlie"] = {generateRandomID(), 35};
    users["Dave"] = {generateRandomID(), 40};

    users["Alice"].age = 26;

    if (users.count("Bob") > 0) {
        std::cout << "Bob's ID: " << users["Bob"].id << std::endl;
        std::cout << "Bob's age: " << users["Bob"].age << std::endl;
    }

    if (users.count("Alice") > 0) {
        std::cout << "Alice's ID: " << users["Alice"].id << std::endl;
        std::cout << "Alice's age: " << users["Alice"].age << std::endl;
    }

    if (users.count("John") > 0) {
        std::cout << "John exists." << std::endl;
    } else {
        std::cout << "John does not exist." << std::endl;
    }

    return 0;
}
