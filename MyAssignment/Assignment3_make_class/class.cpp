#include "class.h"
#include <string>
Student::Student() {
    name = "Hzr";
    age = 23;
    id = "M202373993";
}
Student::Student(std::string name, int age, std::string id) : name(name),age(age),id(id) {

}

void Student::set_name(const std::string &name) : name(name) {

}

std::string Student::get_name() {
    return this->name;
}

