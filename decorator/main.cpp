#include <iostream>

using std::cout;
using std::endl;


class Car {
	public:
        virtual int getPrice();
        virtual void go();
        virtual void stop();
		
    protected:
		int mPrice = 20000;
};

int Car::getPrice() {
    return mPrice;
}

void Car::go() {
    cout << "The standard car accelerates normally." << endl;
}

void Car::stop() {
    cout << "The standard brakes stop the car normally." << endl;
}

class SportEngine : public Car {
	public:
        SportEngine(Car* car);

        int getPrice() override;
		void go() override;
        void stop() override;
		
	private:
        Car *mCar;
};

SportEngine::SportEngine(Car* car) {
	mCar = car;
}

int SportEngine::getPrice() {
    return mCar->getPrice() + 5000;
}

void SportEngine::go() {
	cout << "The sport engine accelerates the car quickly." << endl;
}

void SportEngine::stop() {
    mCar->stop();
}

class BudgetBrakes : public Car {
    public:
        BudgetBrakes(Car* car);

        int getPrice() override;
        void go() override;
        void stop() override;
		
    private:
        Car *mCar;
};

BudgetBrakes::BudgetBrakes(Car* car) {
    mCar = car;
}

int BudgetBrakes::getPrice() {
    return mCar->getPrice() - 1000;
}

void BudgetBrakes::go() {
    mCar->go();
}

void BudgetBrakes::stop() {
    cout << "With a shrill squeaking sound, the budget breaks stop the car slowly." << endl;
}

int main() {
    Car* theCar = new Car();
    cout << "The car costs: " << theCar->getPrice() << endl;
    theCar->go();
    theCar->stop();
    cout << endl;

    theCar = new SportEngine(theCar);
    cout << "A sport engine has been added to the car." << endl;
    cout << "The car costs: " << theCar->getPrice() << endl;
    theCar->go();
    theCar->stop();
    cout << endl;

    theCar = new BudgetBrakes(theCar);
    cout << "Budget brakes have been added to the car." << endl;
    cout << "The car costs: " << theCar->getPrice() << endl;
    theCar->go();
    theCar->stop();
    cout << endl;

	return 0;
}
