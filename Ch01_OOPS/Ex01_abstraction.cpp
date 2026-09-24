#include <iostream>
#include <ostream>
#include <string>

using namespace std;

// Parent Class
class Car {
public:

    string brand;
    string model;
    float engine_cc;
    int speed;

    Car(){
        brand = "unknown";
        model = "unknown";
        engine_cc = 0.0;
        speed = 0;
    }

    virtual void engine_start();
    virtual void engine_stop();
    virtual void accelerate();
    virtual void decelerate();
    virtual void apply_break();

    virtual ~Car() = default;
};

class Manual_Car: public Car {
public:
    string brand;
    string model;
    float engine_cc;
    int speed;

    Manual_Car(){
        brand = "TATA";
        model = "SUV26";
        engine_cc = 1200.6;
        speed = 0;
    }

    void engine_start() override {
        cout << "Car Engine Started!!" << endl;
    }

    void engine_stop() override {
        cout << "Car Engine Stopped!!" << endl;
    }

    void accelerate() override {
        speed += 10;
        cout << "Car Accelerate at speed " << speed << endl;
    }

    void decelerate() override {
        if (speed == 0) {
            cout << "Car Decelerate to speed " << speed << endl;
        }else {
            speed -= 10;
            cout << "Car Decelerate to speed " << speed << endl;
        }
    }

    void apply_break() override{
        speed = 0;
        cout << "Car Break at speed " << speed << endl;
    }

};

// Main function
int main() {
    // Object creation
    Car* car_m = new Manual_Car();

    car_m->engine_start();
    car_m->accelerate();
    car_m->accelerate();
    car_m->decelerate();
    car_m->apply_break();
    car_m->engine_stop();

    delete car_m;

    return EXIT_SUCCESS;
}
