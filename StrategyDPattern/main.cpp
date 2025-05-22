 #include <iostream>

 using namespace std;
// strategy Design Pattern
// it is a pattern that defines a family of algorithms, encapsulate each one, and make them interchangeable.
// strategy design pattern is used when we have to choose between multiple algorithms at runtime.

// -- strategy interface for walk --
 
class WalkableRobot {
    public: 
       virtual void walk() = 0;
       virtual ~WalkableRobot() {}
};

// -- concrete strategy  for walk --
class NormalWalk : public WalkableRobot {
    public:
        void walk() override {
            cout << "Normal walk" << endl;
        }
};

class Nowalk : public WalkableRobot {
    public:
        void walk() override {
            cout << "No walk" << endl;
        }
};


// -- strategy interface for fly --
class FlyableRobot {
    public:
        virtual void fly() = 0;
        virtual ~FlyableRobot() {}
};


// --  concrete strategy for fly --
class NormalFly : public FlyableRobot {
    public:
        void fly() override {
            cout << "Normal fly" << endl;
        }
};


class NoFly : public FlyableRobot {
    public:
        void fly() override {
            cout << "No fly" << endl;
        }
};


// -- stragegy interface for talk --
class TalkableRobot {
    public:
        virtual void talk() = 0;
        virtual ~TalkableRobot() {}
};

// -- concrete strategy for talk --
class NormalTalk : public TalkableRobot {
    public:
        void talk() override {
            cout << "Normal talk" << endl;
        }
};

 
class NoTalk : public TalkableRobot {
    public:
        void talk() override {
            cout << "No talk" << endl;
        }
};



class Robot {
    private:
        WalkableRobot* walk;
        FlyableRobot* fly;
        TalkableRobot* talk;
    public:
        Robot(WalkableRobot* walk, FlyableRobot* fly, TalkableRobot* talk) {
            this->walk = walk;
            this->fly = fly;
            this->talk = talk;
        }
        void walk() {
            walk->walk();
        }
        void fly() {
            fly->fly();
        }
        void talk() {
            talk->talk();
        }

        virtual void projection() = 0; // Abstract method for subclasses
};

// -- concrete  Robot Type --

class CompaniantRobot : public Robot {
    public:
        CompaniantRobot(WalkableRobot* walk, FlyableRobot* fly, TalkableRobot* talk) : Robot(walk, fly, talk) {}
        void projection() override {
            cout << "Companion Robot" << endl;
        }
};


class SoldierRobot : public Robot {
    public:
        SoldierRobot(WalkableRobot* walk, FlyableRobot* fly, TalkableRobot* talk) : Robot(walk, fly, talk) {}
        void projection() override {
            cout << "Soldier Robot" << endl;
        }
};


class workerRobot : public Robot {
    public:
        workerRobot(WalkableRobot* walk, FlyableRobot* fly, TalkableRobot* talk) : Robot(walk, fly, talk) {}
        void projection() override {
            cout << "Worker Robot" << endl;
        }
};



