//
// Created by Linoy Menda on 16/10/2021.
//
#include <iostream>
using namespace std;
class Pizza{
protected:
    int price;
public:
    virtual int get_price()=0;
};
class ItalianPizaa: public Pizza{
    int get_price() override{
        return price;
    }

public:
    ItalianPizaa(){
        price=1;
    }
};
class IsraliPiza: public Pizza{
public:
    IsraliPiza(){
        price=2;
    }
    int get_price() override{
        return price;
    }
};
class Cheese: public Pizza{
protected:
    Pizza* m_p;
public:
    Cheese(Pizza* p){
        m_p=p;
    }
    int get_price() override{
        return m_p->get_price() + 3;
    }

};
class Tomato: public Pizza{
    Pizza* m_p;
public:
    Tomato(Pizza* p){
        m_p=p;
    }
    int get_price() override{
        return m_p->get_price() + 2;
    }
};
int main(){
    Pizza* p = new ItalianPizaa;
    Pizza* p_c = new Cheese(p);
    Pizza* p_c_t = new Tomato(p_c);
    cout << "The price is : " << p_c_t->get_price();

}