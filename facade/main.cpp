#include <iostream>

using std::cout;
using std::endl;

class GitTasks {
    public:
        void checkStatus() { cout << "4 changed files, 3 untracked files." << endl; }
        void add() { cout << "Added files x, y, and z." << endl; }
        void commit() { cout << "Commited files x, y, and z with message \'Hello!\'" << endl; }
        void push() { cout << "Everything up to date." << endl; }

        void gitFacade();
};

void GitTasks::gitFacade() {
    checkStatus();
    add();
    commit();
    push();
}

int main() {
    GitTasks oldWay;
    cout << "Doing git stuff the old way..." << endl;
    oldWay.checkStatus();
    oldWay.add();
    oldWay.commit();
    oldWay.push();
    cout << endl << endl;

    GitTasks newWay;
    cout << "Doing git stuff the new way..." << endl;
    newWay.gitFacade();

    return 0;
}
