#include <iostream>
#include <string>

using namespace std;

// Component interface: defines a common interface for Mario and all power-up decorators

class Character {
public:
    virtual string getAbilities() = 0;
    virtual ~Character() {}
    // virtual destructor for interface
};

// concrete component: Basic Mario Character with no power-ups
class Mario : public Character {
public:
    string getAbilities() {
        return "Mario";
    }
};

// Abstract Decorator interface: defines common interface for all decorators have both "is a" and "has a" relationship
class CharacterDecorator : public Character {
     protected:
        Character* character; // "has a" relationship, wrapped character

   public:
        CharacterDecorator(Character* character) {
            this->character = character;
        }
    
   
};


// Concrete Decorator: adds fly ability to Mario
class FlyDecorator : public CharacterDecorator {
public:
    FlyDecorator(Character* character) : CharacterDecorator(character) {}
    string getAbilities() {
        return character->getAbilities() + " fly";
    }
};


// concrete  Decorator: Gun shooting power-up
class GunDecorator : public CharacterDecorator {
public:
    GunDecorator(Character* character) : CharacterDecorator(character) {}
    string getAbilities() {
        return character->getAbilities() + " shoot with gun";
    }
};


// Concrete Decorator : Height-Increase power-up
class HeightDecorator : public CharacterDecorator {
public:
    HeightDecorator(Character* character) : CharacterDecorator(character) {}
    string getAbilities() {
        return character->getAbilities() + " increase height";
    }
};

// Concrete Decorator: Star-power power-up
class StarDecorator : public CharacterDecorator {
public:
    StarDecorator(Character* character) : CharacterDecorator(character) {}
    string getAbilities() {
        return character->getAbilities() + " with star power";
    }

    ~StarDecorator() {
        cout << "StarDecorator destroyed" << endl;
    }
};

int main() {

    Mario* mario = new Mario();
    cout << "Abilities of mario: "<< mario->getAbilities() << endl;


    FlyDecorator* flyDecorator = new FlyDecorator(mario);
    cout << "Abilities of flyDecorator: " << flyDecorator->getAbilities() << endl;


    GunDecorator* gunDecorator = new GunDecorator(flyDecorator);
    cout << "Abilities of gunDecorator: " << gunDecorator->getAbilities() << endl;

    HeightDecorator* heightDecorator = new HeightDecorator(gunDecorator);
    StarDecorator* starDecorator = new StarDecorator(heightDecorator);

    cout  << "Abilities of starDecorator: "<< starDecorator->getAbilities() << endl;

    return 0;
}