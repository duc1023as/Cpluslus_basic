#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "Class.h"
#include "SmartPointer.h"

int g_count = 0;
std::mutex Mutex;
std::condition_variable cv;
bool ready = false;

void doSomething() {
    std::unique_lock<std::mutex> lock(Mutex);
    while(!ready){
        cv.wait(lock);
    }
    std::cout << "Conditional Variable\n";
}

void notify() {
    std::unique_lock<std::mutex> lock(Mutex);
    ready = true;
    cv.notify_one();
}

void count() {
    Mutex.lock();
    for (int i = 0; i < 100000; i++) {
        g_count++;
    }
    Mutex.unlock();
}

void display(int times) {
    for (int i = 0; i < times; i++) {
        std::cout << std::this_thread::get_id() << "---" << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main(int argc,char* argv[])
{
#if 0
    std::cout << "Hello World!\n";
    Person person(23, "Do Minh Duc");
    Student* ptrStudent = new Student(23, "Do Minh Duc", 13);
    Person* ptrPerson = ptrStudent;
    Student student(23, "Do Minh Duc", 12);
    AbstractClass* abstractClass = new DerviedClass();
    std::cout << person.getAge() << "---" << person.getName() << "\n";
    student.display();
    delete ptrPerson;
    abstractClass->typeClass();
#endif

#if 0
    //std::unique_ptr<Test> ptr = std::make_unique<Test>();
    //std::shared_ptr<Test> ptr1 = std::make_shared<Test>();
    //std::shared_ptr<Test> ptr2 = ptr1;
    //std::cout << ptr1.use_count() << "\n";
    //ptr1.reset();
    //std::cout << ptr1 << "\n";
    std::shared_ptr<Test> ptr3 = std::make_shared<Test>();
    std::shared_ptr<Test2> ptr4 = std::make_shared<Test2>();
    ptr3->pointer = ptr4;
    ptr4->pointer = ptr3;
#endif

#if 0
    std::thread thread1(display, 10);
    std::thread thread2(display, 16);
    std::thread thread3(display, 20);
    std::thread thread4(count);
    std::thread thread5(count);

    thread3.detach();

    thread1.join();
    thread2.join();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    thread4.join();
    thread5.join();
    std::cout << g_count << "\n";
#endif

#if 1
    std::cout << "Example with Condition Variable\n";
    std::thread thread(doSomething);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "After sleeping\n";
    notify();
    thread.join();
    std::this_thread::sleep_for(std::chrono::seconds(2));
#endif
    return 0;
}
