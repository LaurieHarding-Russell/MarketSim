#ifndef CONSUMER_H
#define CONSUMER_H

#include "../Humanity/Person.h"

class Consumer: public Person {
    private:
    int funds;
    std::string worksFor;

    public:
    Consumer();
    Consumer(Person person);
    int getFunds();
    int adjustFunds(int amount);
    bool canRemoveFunds(int amount);

    void setWork(std::string work);
    std::string getWork();


    class ConsumerFactory {
        public:
        bool fed;
        bool sex;
        int happy;
        int health;
        int education;
        int intelligence;
        int age;
        int funds;

        Coordinate coordinate;

        Consumer generateConsumer() {
            Consumer person = Consumer();
            person.fed = fed;
            person.sex = sex;
            person.happy = happy;
            person.health = health;
            person.education = education;
            person.intelligence = intelligence;
            person.age = age;
            person.coordinate = coordinate;
            person.funds = funds;

            return person;
        }
    };
    
};

#endif