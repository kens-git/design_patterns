#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;


// In production, Subject and Observer would be abstract base classes,
// but, for this small example they'll hold the actual implementations.
class Observer {
    public:
        void update(string msg);
        void showMessage();

    private:
        string mMessage;
};

void Observer::update(string msg) {
    mMessage = msg;
}

void Observer::showMessage() {
    cout << mMessage << endl;
}


class Subject {
    public:
        void registerObserver(shared_ptr<Observer> observer);
        void notifyObservers();
        void setMessage(string msg);

    private:
        vector<shared_ptr<Observer>> mObservers;
        string mMessage;
};

void Subject::registerObserver(shared_ptr<Observer> observer) {
    // For the sake of a simple example, don't check for duplicate entries
    mObservers.push_back(observer);
}

void Subject::notifyObservers() {
    for (shared_ptr<Observer> observer : mObservers) {
        observer->update(mMessage);
    }
}

void Subject::setMessage(string msg) {
    mMessage = msg;
    notifyObservers();
}



int main() {
    Subject kelly;
    shared_ptr<Observer> fred = make_shared<Observer>();
    shared_ptr<Observer> stacy = make_shared<Observer>();
    shared_ptr<Observer> joe = make_shared<Observer>();

    kelly.registerObserver(fred);
    kelly.registerObserver(stacy);
    kelly.registerObserver(joe);

    kelly.setMessage("Jenny is politically neutral.");

    fred->showMessage();
    stacy->showMessage();
    joe->showMessage();

    kelly.setMessage("Jeff is of low moral character.");

    fred->showMessage();
    stacy->showMessage();
    joe->showMessage();

    return 0;
}
