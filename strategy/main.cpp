#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::move;



class HitBehaviour {
    public:
        virtual void hit() = 0;
};

class PowerHitter : public HitBehaviour {
    public:
        void hit() override { cout << "The power hitter swings for the fences." << endl; }
};

class LeadoffHitter : public HitBehaviour {
    public:
        void hit() override { cout << "The leadoff hitter hits for average." << endl; }
};



class BaseballPlayer {
    public:
        BaseballPlayer(unique_ptr<HitBehaviour> hb);
        void hit() { mHitBehaviour->hit(); }
        void doSteroids();

    private:
        unique_ptr<HitBehaviour> mHitBehaviour;
};

BaseballPlayer::BaseballPlayer(unique_ptr<HitBehaviour> hb) {
    mHitBehaviour = move(hb);
}

void BaseballPlayer::doSteroids() {
    mHitBehaviour = make_unique<PowerHitter>();
}



int main() {
    BaseballPlayer thirdBaseman(make_unique<PowerHitter>());
    BaseballPlayer secondBaseman(make_unique<LeadoffHitter>());

    thirdBaseman.hit();
    secondBaseman.hit();
    cout << "The second baseman has elected to use PEDs." << endl;
    secondBaseman.doSteroids();
    secondBaseman.hit();

    return 0;
}
