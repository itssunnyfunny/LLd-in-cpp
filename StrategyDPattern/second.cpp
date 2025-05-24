#include <iostream>


using namespace std;

// creating strategy interface

class WalkableRobot {
      public:
       virtual void walk() = 0;
       virtual ~WalkableRobot(){};
};

// walking 
class NormalWalk : public WalkableRobot {
        public:
         void walk() override {
            cout << "this it the normal walk freature" << endl;
         }   
};

class fastWalk: public WalkableRobot {
    public:
      void walk() override {
        cout << "this is fast walk feature" << endl;
      }
};

class slowWalk : public WalkableRobot {
    public:
      void walk() override {
        cout << "this is slow walk feature" << endl;
      }
};


class WeaponRobot {
    public:
      virtual void shoot() = 0;

};

class NOWeapon : public WeaponRobot {
      public:
        void shoot() override {
            cout << "weapon is removed from this robot" << endl;
        }
};

class MachingunWeapon: public WeaponRobot {
    public:
      void shoot() override {
        cout << "shooting - - - with machine gun " << endl;
      }
};


class TalkableRobot {
    public:
      virtual void talk() = 0;
};


class NoTalkable : public TalkableRobot {
    public: 
      void talk() override {
        cout << "this robot can't talk" << endl;
      }
};

class Talkable : public TalkableRobot {
    public:
      void talk() override {
        cout << "this robot can Talk " << endl;
      }
};


class Robot {
    protected:
       WalkableRobot* walkable;
       WeaponRobot* weaponized;
       TalkableRobot* talkable;

    public : 
      Robot(WalkableRobot* walk, WeaponRobot* weapon, TalkableRobot* talk){
          this->walkable = walk;
          this->weaponized = weapon;
          this->talkable = talk;
      }

      void walk() {
         walkable->walk();
      }

      void shoot(){
        weaponized->shoot();
      }

      void talk(){
        talkable->talk();
      }
};


class CompanianRobot: public Robot {
    public: 
     CompanianRobot(WalkableRobot* walk, WeaponRobot* weapon, TalkableRobot* talk ) : Robot(walk, weapon, talk){}
};

class MelatoryRobot: public Robot {
    public:
      MelatoryRobot(WalkableRobot* walk, WeaponRobot* weapon, TalkableRobot* talk) : Robot(walk, weapon, talk){}
};


int main() {

    Robot *robot1 = new MelatoryRobot(new fastWalk(), new MachingunWeapon(), new Talkable() ) ;

    
}





