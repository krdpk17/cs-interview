/*
It is pub-sub model where there are many publishers and many subscribers
In this example, topic is only one
This is basic version of pub-sub where publish is blocking until all sbscribers consumes
TODO: 
    Multi thread support
    non-blocking publish
*/

#include<list>
#include<string>
#include<iostream>
using namespace std;
class PubSub;

/*
Consumer class
*/
class Consumer{
    public:
        Consumer(PubSub *pubsub);
        void callback(string str);//callback function
        void subscribe(); // subscribe to pubsub
    private:
        PubSub *pubsub;//pubsub handler
};

/*
Pub sub class
*/
class PubSub{
    public:
    PubSub(){

    }

    void publish(string str){
        list<Consumer *>::iterator it;
        Consumer *consumer = nullptr;
        for(it = consumers.begin(); it != consumers.end(); ++it){
            consumer = *it;
            consumer->callback(str);
        }
    }

    bool subscribe(Consumer *c){
        consumers.push_back(c);
        return true;
    }

   void unsubscribe(){

    }

    private:
        //list<string> pubsubQueue;
        list<Consumer *> consumers;
};

Consumer::Consumer(PubSub *pubsub){
            this->pubsub = pubsub;
}

void Consumer::subscribe(){
    pubsub->subscribe(this);
}

void Consumer::callback(string str){
    cout<<str<<"\t";
}

/*
    Producer class
*/
class Producer{
    public:
        Producer(PubSub *pubsub){
            this->pubsub = pubsub;
        }

        bool publish(string str){
            pubsub->publish(str);
            return true;
        }

    private:
        PubSub *pubsub;//pubsub handler
};

int main(){
    PubSub *pubsub = new PubSub;
    Consumer *c1 = new Consumer(pubsub);
    c1->subscribe();
    Consumer *c2 = new Consumer(pubsub);
    c2->subscribe();
    Producer *p1 = new Producer(pubsub);
    p1->publish("hello");
    return 0;

}

