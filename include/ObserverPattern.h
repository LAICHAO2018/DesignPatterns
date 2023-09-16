//
// Created by laichao on 2023/9/16.
//

#ifndef DESIGNPATTERNS_OBSERVERPATTERN_H
#define DESIGNPATTERNS_OBSERVERPATTERN_H

#include <memory>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>

class Observer;

////////// Abstract Subject class
class Subject {
public:
    explicit Subject() = default;

    virtual ~Subject() = default;

    virtual void attach(const std::shared_ptr<Observer> &observer) = 0;

    virtual void detach(const std::shared_ptr<Observer> &observer) = 0;

    virtual void notify() = 0;

    virtual int get_status() const { return _status; }

    void set_status(const int &status) {
        _status = status;
        std::cout << "Status update: " << status << std::endl;
    }

protected:
    int _status = 0;
    std::list<std::shared_ptr<Observer>> _observer_objects;
};

////////// Abstract Subject class
class Observer {
public:
    explicit Observer(std::shared_ptr<Subject> subject, std::string name = "")
            : _subject(std::move(subject)), _name(std::move(name)) {}

    virtual ~Observer() = default;

    virtual void update() = 0;

    virtual const std::string &name() { return _name; }

protected:
    std::shared_ptr<Subject> _subject;
    std::string _name;
};

// =======================================================================================================

// concrete subject class
class ConcreteSubject : public Subject {
public:
    void attach(const std::shared_ptr<Observer> &observer) override {
        const auto iter = std::find(_observer_objects.begin(), _observer_objects.end(), observer);
        if (iter == _observer_objects.end()) {
            _observer_objects.emplace_back(observer);
            std::cout << "Attach observer object: " << observer->name() << std::endl;
        }
    }

    void detach(const std::shared_ptr<Observer> &observer) override {
        _observer_objects.remove(observer);
        std::cout << "Detach observer object: " << observer->name() << std::endl;
    }

    void notify() override {
        auto iter = _observer_objects.begin();
        while (iter != _observer_objects.end()) {
            (*iter)->update();
            ++iter;
        }
    }
};

// concrete observer class
class ObserverJack : public Observer {
public:
    explicit ObserverJack(const std::shared_ptr<Subject> &subject, const std::string &name = "unknown")
            : Observer(subject, name) {}

    void update() override {
        std::cout << "Observer: " << _name << "get update info msg, status is: " << _subject->get_status() << std::endl;
    }
};

// concrete observer class
class ObserverRose : public Observer {
public:
    explicit ObserverRose(const std::shared_ptr<Subject> &subject, const std::string &name = "unknown")
            : Observer(subject, name) {}

    void update() override {
        std::cout << "Observer: " << _name << "get update info msg, status is: " << _subject->get_status() << std::endl;
    }
};

#endif //DESIGNPATTERNS_OBSERVERPATTERN_H
