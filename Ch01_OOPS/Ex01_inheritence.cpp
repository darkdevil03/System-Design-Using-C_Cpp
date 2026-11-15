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

    virtual void engine_start() {
        cout << "[CAR] Engine Started" << endl;
    }

    virtual void engine_stop() {
        cout << "[CAR] Engine Stopped" << endl;
    }

    virtual void accelerate() {
        speed += 5;
        cout << "[CAR] Accelerate to speed " << speed << endl;
    }

    virtual void decelerate() {
        if (speed == 0) {
            cout << "[CAR] Already at speed " << speed << endl;
        } else {
            speed -= 5;
            cout << "[CAR] Decelerate to speed " << speed << endl;
        }
    }

    virtual void apply_break() {
        speed = 0;
        cout << "[CAR] Break at speed " << speed << endl;
    }
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
        cout << "[MANUAL] Car Engine Started!!" << endl;
    }

    void engine_stop() override {
        cout << "[MANUAL] Car Engine Stopped!!" << endl;
    }

    void accelerate() override {
        speed += 10;
        cout << "[MANUAL] Car Accelerate at speed " << speed << endl;
    }

    void decelerate() override {
        if (speed == 0) {
            cout << "[MANUAL] Car Decelerate to speed " << speed << endl;
        }else {
            speed -= 10;
            cout << "[MANUAL] Car Decelerate to speed " << speed << endl;
        }
    }

    void apply_break() override{
        speed = 0;
        cout << "[MANUAL] Car Break at speed " << speed << endl;
    }
};

class Electric_Car: public Car {
public:
    string brand;
    string model;
    float engine_cc;
    int speed;

    Electric_Car(){
        brand = "BMW";
        model = "Electric25";
        engine_cc = 1560.8;
        speed = 0;
    }

    void engine_start() override {
        cout << "[ELECTRIC] Car Engine Started!!" << endl;
    }

    void engine_stop() override {
        cout << "[ELECTRIC] Car Engine Stopped!!" << endl;
    }

    void accelerate() override {
        speed += 15;
        cout << "[ELECTRIC] Car Accelerate at speed " << speed << endl;
    }

    void decelerate() override {
        if (speed == 0) {
            cout << "[ELECTRIC] Car Decelerate to speed " << speed << endl;
        }else {
            speed -= 15;
            cout << "[ELECTRIC] Car Decelerate to speed " << speed << endl;
        }
    }

    void apply_break() override{
        speed = 0;
        cout << "[ELECTRIC] Car Break at speed " << speed << endl;
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


    Car* car_e = new Electric_Car();

    car_e->engine_start();
    car_e->accelerate();
    car_e->accelerate();
    car_e->decelerate();
    car_e->apply_break();
    car_e->engine_stop();

    delete car_e;
    delete car_m;

    return EXIT_SUCCESS;
}
