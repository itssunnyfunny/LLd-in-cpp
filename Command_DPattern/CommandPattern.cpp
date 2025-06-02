#include <iostream>

using namespace std;


// command interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
    // virtual destructor for interface
};


// Receivers

class Light {
public:
    void on() {
        cout << "Light is on" << endl;
    }
    void off() {
        cout << "Light is off" << endl;
    }
};
 
class Fan {
public:
    void on() {
        cout << "Fan is on" << endl;
    }
    void off() {
        cout << "Fan is off" << endl;
    }
};

// concrete command for light
class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* light) {
        this->light = light;
    }
    void execute() override {
        light->on();
    }
    void undo() override {
        light->off();
    }
};

// concrete command for fan
class FanOnCommand : public Command {
    Fan* fan;
public:
    FanOnCommand(Fan* fan) {
        this->fan = fan;
    }
    void execute() override {
        fan->on();
    }
    void undo() override {
        fan->off();
    }
};

// Invoker: Remote Controller with static 

 class RemoteController {
    private:
     static const int numButtons = 4;
     Command* commands[numButtons];
     bool buttonPressed[numButtons];

     public:

      RemoteController() {
        for (int i = 0; i < numButtons; i++) {
            commands[i] = nullptr;
            buttonPressed[i] = false;
        }
      }
     
      void SetCommand(int index, Command* command) {

           if (index >= 0 && index < numButtons) {
              if(commands[index] != nullptr) {   
                 delete commands[index];    
              }

            commands[index] = command;
            buttonPressed[index] = false;
           }
      }
     void pressButton(int index) {
        if(index >= 0 && index < numButtons && commands[index] != nullptr) {
            if (buttonPressed[index] == false) {
                commands[index]->execute();
                     
            } else {
                commands[index]->undo();
            }
            buttonPressed[index] = !buttonPressed[index];
            
            
        } else {
            cout << "Invalid button index" << endl;
        }
       
     }
    ~RemoteController() {
        for (int i = 0; i < numButtons; i++) {
            if (commands[i] != nullptr) {
                delete commands[i];
            }
        }
    } 

 };


 int main () {
     Light * LivingRoomLight = new Light();
     Fan * KitchenFan = new Fan();


     RemoteController * remoteController = new RemoteController();


     remoteController->SetCommand(0, new LightOnCommand(LivingRoomLight));
     remoteController->SetCommand(1, new FanOnCommand(KitchenFan));

     remoteController->pressButton(0);
     remoteController->pressButton(1);

     remoteController->pressButton(0);
     remoteController->pressButton(1);
     
     delete remoteController;
     delete LivingRoomLight;
     delete KitchenFan;
    
    return 0;
}