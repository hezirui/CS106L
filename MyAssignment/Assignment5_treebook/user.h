#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User() = default;

    User(std::string name);

//    User(User& user) = delete;
//
//    User& operator=(User& user) = delete;

    User(User&& user) noexcept;

    User& operator=(User&& user) noexcept;

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);


    // TODO: add the < operator overload here!
    bool operator < (const User &user) ;
    void setFriend(User user);
private:
    std::string name;
    std::set<User> friends;

};