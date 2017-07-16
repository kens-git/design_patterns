#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;



class GameState {
    public:
        virtual ~GameState() { }
        virtual void update() = 0;
        virtual void draw() = 0;
};

class MenuState : public GameState {
    public:
        MenuState() { cout << "Loading Menustate assets..." << endl; }
        virtual ~MenuState() { cout << "Freeing Menustate assets..." << endl; }
        void update() override { cout << "Menustate: Updating logic..." << endl; }
        void draw() override { cout << "MenuState: Updating graphics..." << endl; }
};

class PlayState : public GameState {
    public:
        PlayState() { cout << "Loading Playstate assets..." << endl; }
        virtual ~PlayState() { cout << "Freeing Playstate assets..." << endl; }
        void update() override { cout << "Playstate: Updating logic..." << endl; }
        void draw() override { cout << "Playstate: Updating graphics..." << endl; }
};



class AwesomeGame {
    public:
        AwesomeGame() : mCurrentState(make_unique<MenuState>()) { mainLoop(); }

    private:
        void mainLoop();
        unique_ptr<GameState> mCurrentState;
};

void AwesomeGame::mainLoop() {
    // There's no actual loop here, just a demonstration of the state changing

    mCurrentState->update();
    mCurrentState->draw();

    // The user decided to play the game, change to PlayState
    mCurrentState = make_unique<PlayState>();

    mCurrentState->update();
    mCurrentState->draw();

    cout << endl << "The user quits..." << endl;
}

int main() {
    AwesomeGame theGame;
    cout << endl << "Thanks for playing!" << endl;
    cout << "Your score was: 0" << endl;

    return 0;
}
