#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor called. Data: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called. Data: " << data << std::endl;
    }

    void display() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Creating a unique_ptr to a MyClass object
    std::unique_ptr<MyClass> uniqueObj(new MyClass(42));

    // Displaying data using the unique_ptr
    uniqueObj->display();

    // Transfer ownership to another unique_ptr using move semantics
    std::unique_ptr<MyClass> anotherUniqueObj = std::move(uniqueObj);

    // Displaying data using the second unique_ptr
    anotherUniqueObj->display();

    // The original unique_ptr is now null after the move
    // The associated MyClass object will be deleted when anotherUniqueObj goes out of scope
    return 0;
}
