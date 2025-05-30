#include <iostream>


using namespace std;


class Singleton {
    private: 
    static Singleton* instance;
    // Singleton() {}
    // public:
    // static Singleton* getInstance() {
    //     if (instance == nullptr) {
    //         instance = new Singleton();
    //     }
    //     return instance;
    // }

    Singleton() {
        cout << "Singleton constructor called" << endl;
    }

     public: 
       static Singleton * getInstance() {
        return instance;
       }
};

// eagor instantiation
Singleton* Singleton::instance = new Singleton();

int main() {

    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
    return 0;
}