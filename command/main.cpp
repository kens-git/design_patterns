#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::move;


// In production this would be an abstract base class
class Receiver {
    public:
        void incrementValue();
        void decrementValue();

    private:
        int mValue;
};

void Receiver::incrementValue() {
    mValue++;
    cout << "Value was incremented. It is now " << mValue << endl;
}

void Receiver::decrementValue() {
    mValue--;
    cout << "Value was decremented. It is now " << mValue << endl;
}



// In production this would be an abstract base class
class Command {
    public:
        Command(unique_ptr<Receiver> thing) { mThing = move(thing); }
        void execute() { mThing->incrementValue(); }
        void undo() { mThing->decrementValue(); }

    private:
        unique_ptr<Receiver> mThing;
};



class Invoker {
    public:
        Invoker(unique_ptr<Command> command) { mCommand = move(command); }

        void doTheThing() { mCommand->execute(); }
        void undoTheThing() { mCommand->undo(); }

    private:
		// This would usually be a stack or queue, so we could push and pop commands (i.e., executate and undo commands)
        unique_ptr<Command> mCommand;
};


/* Definitions */
// Invoker: Keeps track of the command stack
// Command: The specified command
// Receiver: The object being acted on


// Any references to a client mean the class that holds the invoker
// In this case, the client is our main() function
int main() {
    Invoker invoker(make_unique<Command>(make_unique<Receiver>()));
    invoker.doTheThing();
    invoker.doTheThing();
    invoker.doTheThing();
    invoker.doTheThing();
    invoker.undoTheThing();
    invoker.undoTheThing();
    invoker.doTheThing();

    return 0;
}
