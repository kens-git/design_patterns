#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Singleton {
    public:
        static Singleton* getInstance();

    private:
        Singleton() { }
};

Singleton* Singleton::getInstance() {
    static Singleton* instance;
    if (instance == nullptr) {
        instance = new Singleton();
        cout << "Constructing Singleton for the first and only time..." << endl;
    }

    cout << "Returning previously constructed Singleton instance..." << endl;
    return instance;
}

int main() {
	Singleton* singleton = Singleton::getInstance();
	singleton->getInstance();
	singleton->getInstance();
	singleton->getInstance();
	
    // Note that because the Singleton instance is static, deleting our instance
    // only frees up the memory related to our instance
    cout << "Attempting to delete Singleton instance..." << endl;
	delete singleton;
    singleton = nullptr;

    Singleton* otherSingleton = Singleton::getInstance();
    singleton = Singleton::getInstance();

    if (singleton == otherSingleton) {
        cout << "(Not so) Magically, they point to the same address." << endl;
    }

    return 0;
}
