#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::make_unique;



class CoolClass {
    public:
        virtual void beCool() { cout << "CoolClass says:" << endl << "\tI'm a cool class!" << endl;}
};



class UncoolClass {
    public:
        void beUncool() { cout << "I'm not cool." << endl; }
};



class UncoolClassAdapter : public CoolClass, private UncoolClass {
    public:
        void beCool() ;
};

void UncoolClassAdapter::beCool() {
    cout << "Formally UncoolClass says:" << endl;
    cout << "\tEveryone is fooled into believing I'm cool!" << endl;
    cout << "\tBut actually..." << endl << "\t";
    beUncool();
}

int main() {
    vector<unique_ptr<CoolClass>> coolClub;
    unique_ptr<CoolClass> coolPerson1 = make_unique<CoolClass>();
    unique_ptr<CoolClass> coolPerson2 = make_unique<CoolClass>();
    unique_ptr<CoolClass> coolNow = make_unique<UncoolClassAdapter>();
    coolClub.push_back(move(coolPerson1));
    coolClub.push_back(move(coolPerson2));
    coolClub.push_back(move(coolNow));

    for (unique_ptr<CoolClass> &cool : coolClub) {
        cool->beCool();
    }

    return 0;
}
