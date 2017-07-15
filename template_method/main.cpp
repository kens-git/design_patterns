#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;



class Automobile {
    public:
        // driveToDestination() is the template method
        void driveToDestination();

    protected:
        virtual void backOutOfDriveway() = 0;
        virtual void go() = 0;
        virtual void stop() = 0;
        virtual void park() = 0;

        // These methods are 'hooks', that the subclasses can override if they need to
        virtual void start() { cout << "The key is put into the ignition and is turned." << endl; }
        virtual void drive() { cout << "Turn left and right until at destination." << endl; }
};

void Automobile::driveToDestination() {
    start();
    backOutOfDriveway();
    go();
    drive();
    stop();
    park();
}

class Car : public Automobile {
    protected:
        void backOutOfDriveway() override { cout << "Put it in reverse, back out." << endl; }
        void go() override { cout << "Step on the gas." << endl; }
        void stop() override { cout << "Step on the brake." << endl; }
        void park() override { cout << "Put it in park, lock the doors." << endl; }
};

class Scooter : public Automobile {
    protected:
        void backOutOfDriveway() override { cout << "Walk backwards out of driveway." << endl; }
        void go() override { cout << "Throttle." << endl; }
        void stop() override { cout << "Squeeze the brake handle." << endl; }
        void park() override { cout << "Hit the kickstand." << endl; }
};

int main() {
    unique_ptr<Automobile> car = make_unique<Car>();
    unique_ptr<Automobile> scooter = make_unique<Scooter>();

    car->driveToDestination();
    cout << endl << endl;
    scooter->driveToDestination();
    cout << endl;

    return 0;
}
