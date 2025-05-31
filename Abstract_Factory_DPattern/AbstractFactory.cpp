#include <iostream>

using namespace std;    

class Burger{
public:
    virtual void prepare()=0;
};

class BasicBurger:public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Burger with bun, patty andj ketchup"<<endl;
    }
};

class StandardBurger:public Burger{
public:
    void prepare() override{
        cout<<"Preparing Stranded Burger with bun, patty, cheese, lettuce and ketchup"<<endl;
    }
};


class PremiumBurger:public Burger{
public:
    void prepare() override{
        cout<<"Preparing Premium Burger with goumette bun , premium patty, cheese, lettuce and ketchup"<<endl;
    }
};


class BasicWheatBurger:public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger with bun, patty andj ketchup"<<endl;
    }
};

class StandardWheatBurger:public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard Wheat Burger with  wheat bun, patty andj ketchup"<<endl;
    }
};


class PremiumWheatBurger:public Burger{
public:
    void prepare() override{
        cout<<"Preparing Premium Wheat Burger with goumette bun , premium patty, cheese, lettuce and ketchup"<<endl;
    }
};

// product-2 --> GarlicBread


class GarlicBread{
public:
    virtual void prepare()=0;
};


class BasicGarlicBread:public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Basic Garlic Bread with butter and garlic"<<endl;
    }
};

class CheeseGarlicBread:public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Cheese Garlic Bread with extra cheese and butter"<<endl;
    }
};


class BasicWheatGarlicBread:public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Garlic Bread with butter and garlic"<<endl;
    }
};

class CheeseWheatGarlicBread:public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Cheese Wheat Garlic Bread with extra cheese and butter"<<endl;
    }
};


// factory and its concretions

class MealFactory {
public:
    virtual Burger* createBurger(string& type)=0;
    virtual GarlicBread* createGarlicBread(string& type)=0;
};


class KFCMealFactory : public MealFactory {
public:
    Burger* createBurger(string& type) override {
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

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        } else if (type == "standard") {
            return new CheeseGarlicBread();
        } else {
            return nullptr;
        }
    }
};


class DominosMealFactory : public MealFactory {
public:
    Burger* createBurger(string& type) override {
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

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicWheatGarlicBread();
        } else if (type == "standard") {
            return new CheeseWheatGarlicBread();
        } else {
            return nullptr;
        }
    }
};


int main() {

    string burgerType = "basic";
    string garlicBreadType = "standard";

    MealFactory *factory = new KFCMealFactory();
    Burger *burger = factory->createBurger(burgerType);
    GarlicBread *garlicBread = factory->createGarlicBread(garlicBreadType);
    burger->prepare();
    garlicBread->prepare();
    delete burger;
    delete garlicBread;
    return 0;
}