//
// Created by Linoy Menda on 16/10/2021.
//
# include <iostream>
using namespace std;
class Car{
private:
    Car(){

    }
    static Car * instance_car;
public:
    static Car* get_car(){
        if (instance_car == nullptr){
            instance_car =  new Car;
        }
        return instance_car;
    }
};
Car* Car::instance_car = nullptr;
int main(){
    Car* c = Car::get_car();
    cout << c << endl;
    Car* c2 = Car::get_car();
    cout << c2 << endl;
    cout << "Print the same address" ;
}
