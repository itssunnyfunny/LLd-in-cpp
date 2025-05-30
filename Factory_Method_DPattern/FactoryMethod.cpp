#include <iostream>

using namespace std;


// product class and subclasses

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};


class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty andj ketchup" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Stranded Burger with bun, patty, cheese, lettuce and ketchup" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with goumette bun , premium patty, cheese, lettuce and ketchup" << endl;
    }
};

 class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger with bun, patty andj ketchup" << endl;
    }
};


class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger with  wheat bun, patty andj ketchup" << endl;
    }
};


class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger with goumette bun , premium patty, cheese, lettuce and ketchup" << endl;
    }
};


// factory and its concretions

class BurgerFactory {
    public:
        virtual Burger* createBurger(string type) = 0;
};


class DominosBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger(string type) {
            if (type == "basic") {
                return new BasicWheatBurger();
            } else if (type == "standard") {
                return new StandardWheatBurger();
            } else if (type == "premium") {
                return new PremiumWheatBurger();
            } else {
                return nullptr;
            }
        }
};


class KFCBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger(string type) {
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

int main(){

    BurgerFactory* factory = new KFCBurgerFactory();
    Burger* basicBurger = factory->createBurger("basic");
    basicBurger->prepare();
    delete basicBurger;

    BurgerFactory* factory2 = new DominosBurgerFactory();
    Burger* basicBurger2 = factory2->createBurger("premium");
    basicBurger2->prepare();
    delete basicBurger2;
    return 0;
}