#include "Consumer.h"


int Consumer::getFunds() {
    return funds;
}

int Consumer::adjustFunds(int amount) {
    funds = amount;
}

bool Consumer::canRemoveFunds(int amount) {
    return funds - amount >= 0;
}