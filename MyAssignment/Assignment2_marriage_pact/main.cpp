/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>

std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::set<std::string> my_set;
    std::ifstream ifs(filename);
    std::string name;
    while(std::getline(ifs,name)){
        my_set.insert(name);
        //std::cout<<name<<'\n';
    }
    return my_set;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
    std::queue<std::string*> matches;
    std::string first_name;
    std::string last_name;
    for(auto iter = students.begin();iter != students.end();iter++){
        std::stringstream ss((*iter));
        ss >> first_name >> last_name;
        //std::cout<<"name: "<<first<<" "<<last<<'\n';
        if(first_name[0] == 'D' && last_name[0] == 'C')
            matches.push(const_cast<std::string*> (&*iter));
    }
    return  matches;
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    std::string filename = "C:\\Users\\admin\\CLionProjects\\CS106L\\MyAssignment\\Assignment2_marriage_pact\\students.txt";
    std::set<std::string> my_set = get_applicants(filename);
    std::queue<std::string*> names = find_matches(my_set);
    while (!names.empty()){
        std::cout<<*names.front()<<'\n';
        names.pop();
    }
    return 0;
}
