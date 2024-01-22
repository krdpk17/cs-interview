'''
It implements pubsub with many publishers and many subscribers
publish is blocking call and it returns after sending data to all subscribers
'''

class PubSub:
    def __init__(self):
        self.subscribers = []
    
    def publish(self, val):
        for subscriber in self.subscribers:
            subscriber.callback(val)
    
    def subscribe(self, obj):
        self.subscribers.append(obj)

class Subscriber:
    def __init__(self, pubsub):
        self.pubsub = pubsub
    
    def register(self):
        self.pubsub.subscribe(self)
    
    def callback(self, val):
        print(" " + val)

class Publisher:
    def __init__(self, pubsub):
        self.pubsub = pubsub
    
    def publish(self, val):
        self.pubsub.publish(val)

if(__name__ == "__main__"):
    ps = PubSub()

    s1 = Subscriber(ps)
    s1.register()
    s2 = Subscriber(ps)
    s2.register()

    p = Publisher(ps)
    p.publish("hello")
    p.publish("world")

