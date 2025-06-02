#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Abstract Observer interface

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {} // virtual destructor for interface
};

// Abstract Oberserable interface : a YouTube channel interface

class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {} // virtual destructor for interface
};

// Concrete Subject: a YouTube channel that observers can subscribe to

class YouTubeChannel : public IChannel {
private:
    vector<ISubscriber*> subscribers; // vector of subscribers
    string name;
    string lastVideo;                  // last video uploaded
public:

    YouTubeChannel(string name) : name(name) {}
           
    // Add a new subscriber (avoid duplicates)
    void subscribe(ISubscriber* subscriber) override {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    // Remove a subscriber if it exists
    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    // Notify all subscribers about a new video
    void notifySubscribers() override {
        for (ISubscriber* subscriber : subscribers) {
            subscriber->update();
        }
    }

    // Upload a new video and notify subscribers
    void uploadVideo(string title) {
        lastVideo = title;

        cout << "New video uploaded: " << title << endl;
        notifySubscribers();
    }

    // get Video title
    string getVideoData() {
       return "\nCheckout our new video: " + lastVideo + "\n";
    }
};

// Concrete Observer: a user that subscribes to a YouTube channel
class Subscriber : public ISubscriber {
private:
    string name;
    YouTubeChannel* channel;
public:
    Subscriber(string name, YouTubeChannel* channel) : name(name), channel(channel) {}

   // called by Channel : print notification message
    void update() override {
        cout << "hey" << name << " " << this->channel->getVideoData() << endl;
    }
};




int main() {
    // create a YouTube channel
    YouTubeChannel* channel = new YouTubeChannel("MyChannel");

    // create subscribers
    Subscriber* subscriber1 = new Subscriber("Alice", channel);
    Subscriber* subscriber2 = new Subscriber("Bob", channel);
    Subscriber* subscriber3 = new Subscriber("Charlie", channel);


    // subscribe subscribers
    channel->subscribe(subscriber1);
    channel->subscribe(subscriber2);
    channel->subscribe(subscriber3);


       // upload a new video
    channel->uploadVideo("New video!");

       // unsubscribe a subscriber
    channel->unsubscribe(subscriber2);

       // upload another video
    channel->uploadVideo("Updated video!");
    delete channel;
    delete subscriber1;
    delete subscriber2;
    delete subscriber3;
    return 0;
}