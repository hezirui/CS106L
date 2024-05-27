#include <string>
class Student {
public:
    Student();
    Student(std::string name,int age,std::string id);

    std::string get_name();

    void set_name(const std::string &name);

private:
    std::string name;
    int age;
    std::string id;
};