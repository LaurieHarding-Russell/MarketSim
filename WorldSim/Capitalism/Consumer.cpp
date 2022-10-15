#include "Consumer.h"

Consumer::Consumer() {}

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