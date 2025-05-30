#include <iostream>
using namespace std;


class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger: public Burger {
    public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty andj ketchup" << endl;
    }
};


class StandardBurger: public Burger {
    public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, lettuce and ketchup" << endl;
    }
};


class PremiumBurger: public Burger {
    public:
    void prepare() override {
        cout << "Preparing Premium Burger with goumette bun , premium patty, cheese, lettuce and ketchup" << endl;
    }
};


class BurgerFactory {
    public:
      static Burger* createBurger(string type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            return nullptr;
        }
    }
};


int main() {
    BurgerFactory* factory = new BurgerFactory();
    Burger* basicBurger = factory->createBurger("basic");
    basicBurger->prepare();
    delete basicBurger;
    return 0;
}