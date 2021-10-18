//
// Created by Linoy Menda on 16/10/2021.
//
#include <iostream>
using namespace std;
#include <vector>
class Listener{
public:
    virtual void update()=0;
};
class Monitor{
    vector<Listener*> vec_listeners;
public:
    void add_listener(Listener* l){
        vec_listeners.push_back(l);
    }
    void notify(){
        for (int i=0;i<vec_listeners.size();i++){
            vec_listeners[i]->update();
        }
    }
};
class Student:public Listener{
    void update() override{
        cout << "I'm student and now I updated" <<endl;
    }
};
class Singer:public Listener{
    void update() override{
        cout << "I'm singer and now I updated" <<endl;
    }
};
int main(){
    Monitor m;
    Listener* ron= new Student;
    Listener* may = new Singer;
    m.add_listener(ron);
    m.add_listener(may);
    m.notify();
}