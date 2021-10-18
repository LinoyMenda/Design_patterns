//
// Created by Linoy Menda on 14/04/2021.
//

#include <iostream>
#include <map>
using namespace std;
class Employee{
public:
    virtual void whoIam() = 0;
};
class Lecturer: public Employee{
    void whoIam() {
        cout << "I am a lecturer" <<endl;
    }
};
class Ta : public Employee{
    void whoIam() {
        cout << "I am a teacher assistant" <<endl;
    }
};
class Factory {
public:
    class Creator;
    map<string,Creator*> map_creator;
    Factory(){
        map_creator["lecturer"]=new LecturerCreator;
        map_creator["ta"]=new TaCreator;
    }
    class Creator {
    public:
        virtual Employee *create() = 0;
    };

    class LecturerCreator : public Creator {
    private:
        Employee *create() {
            return new Lecturer;
        }
    };

    class TaCreator : public Creator {
    private:
        Employee *create() {
            return new Ta;
        }
    };
};
class UserInput{
public:
    Employee* createEmployee(string input) {
        Factory f;
        if (f.map_creator.find(input)!=f.map_creator.end()){
            Employee* e = f.map_creator[input]->create();
            return e;
        }
        else{
            return nullptr;
        }

    }
};
int main(){
    UserInput u;
    if (u.createEmployee("ta")!= nullptr) {
        u.createEmployee("ta")->whoIam();
    }
    else{
        cout << "Please select valid key " <<endl;
    }
    if (u.createEmployee("notValid")!= nullptr) {
        u.createEmployee("notValid")->whoIam();
    }
    else{
        cout << "Please select valid key " <<endl;
    }
}
