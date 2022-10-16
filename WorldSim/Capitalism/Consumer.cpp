#include "Consumer.h"

Consumer::Consumer() {}

Consumer::Consumer(Person person) {
    //TODO
}

int Consumer::getFunds() {
    return funds;
}

int Consumer::adjustFunds(int amount) {
    funds = amount;
    return funds;
}

bool Consumer::canRemoveFunds(int amount) {
    return funds - amount >= 0;
}

void Consumer::setWork(std::string work) {
    worksFor = work;
}

std::string Consumer::getWork() {
    return worksFor;
}
