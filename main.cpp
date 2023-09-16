//
// Created by laichao on 2023/9/16.
//

#include "include/ObserverPattern.h"

int main () {
    std::shared_ptr<Subject> subject = std::make_shared<ConcreteSubject>();

    // create some observers
    auto observer_jack_one = std::make_shared<ObserverJack>(subject, "jack_fans_one");
    auto observer_jack_two = std::make_shared<ObserverJack>(subject, "jack_fans_two");
    auto observer_jack_three = std::make_shared<ObserverJack>(subject, "jack_fans_three");
    auto observer_rose_one = std::make_shared<ObserverJack>(subject, "rose_fans_one");
    auto observer_rose_two = std::make_shared<ObserverJack>(subject, "rose_fans_two");
    auto observer_rose_three = std::make_shared<ObserverJack>(subject, "rose_fans_three");

    // register observers
    subject->attach(observer_jack_one);
    subject->attach(observer_jack_two);
    subject->attach(observer_jack_three);
    subject->attach(observer_rose_one);
    subject->attach(observer_rose_two);
    subject->attach(observer_rose_three);

    subject->set_status(2); // subject change status
    subject->notify();

    std::cout << std::string(100, '-') << std::endl;

    // detach one observer of jack and rose
    subject->detach(observer_jack_one);
    subject->detach(observer_rose_one);

    subject->set_status(3); // subject change status
    subject->notify();

    return 0;
}