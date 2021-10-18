//
// Created by Linoy Menda on 16/10/2021.
//
#include <iostream>
using namespace std;

class Strategy{
public:
    virtual void pay()=0;
};
class DirectCreditCard: public Strategy{
    void pay() override{
        cout << "client pay with direct credit card" <<endl;
    }
};
class Cash: public Strategy{
    void pay() override{
        cout << "client pay with cash" <<endl;
    }
};
class Shop{
    Strategy* m_s;
public:
    void set_Strategy(Strategy* s){
        m_s=s;
    }
    void clientIsPay(){
        m_s->pay();
    }
};
int main(){
    Shop zara;
    zara.set_Strategy(new DirectCreditCard);
    zara.clientIsPay();
}