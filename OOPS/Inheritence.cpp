#include <iostream>
#include <ostream>
#include <string>

using namespace std;

// Class
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

    void engine_start() {
        cout << "Car Engine Started!!" << endl;
    }

    void engine_stop() {
        cout << "Car Engine Stopped!!" << endl;
    }

    void accelerate() {
        speed += 10;
        cout << "Car Accelerate at speed " << speed << endl;
    }

    void decelerate() {
        if (speed == 0) {
            cout << "Car Decelerate to speed " << speed << endl;
        }else {
            speed -= 10;
            cout << "Car Decelerate to speed " << speed << endl;
        }
    }

    void apply_break(){
        speed = 0;
        cout << "Car Break at speed " << speed << endl;
    }

};

// Main function
int main() {
    // Object creation
    Car* c = new Car();

    c->engine_start();
    c->accelerate();
    c->decelerate();
    c->apply_break();
    c->engine_stop();

    delete c;

    return EXIT_SUCCESS;
}
