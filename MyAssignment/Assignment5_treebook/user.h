#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User() = default;

    User(std::string name);

    User(User& user) = delete;

    User& operator=(User& user) = delete;

    User(User&& user);

    User& operator=(User&& user);

    void addFriend(User& user);

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    
private:
    std::string name;
    std::set<User> friends;

};