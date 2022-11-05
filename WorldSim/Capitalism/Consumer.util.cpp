#include "Consumer.util.h"

Consumer ConsumerUtil::generateKid(Consumer dad, Consumer mum) {
    std::default_random_engine generator = std::default_random_engine(std::random_device{}());
    
    std::uniform_int_distribution<int> sexDistribution(0, 1);
    std::uniform_int_distribution<int> educationDistribution(0, std::max(dad.getEducation(), mum.getEducation()));
    std::uniform_int_distribution<int> intelligenceDistribution(0, 100); // How controversail shall we get?

    Consumer::ConsumerFactory personFactory = Consumer::ConsumerFactory();
    personFactory.education = educationDistribution(generator);
    personFactory.sex = sexDistribution(generator);
    personFactory.fed = true;
    personFactory.happy = 100;
    personFactory.health = 100;
    personFactory.age = 0;
    personFactory.intelligence = intelligenceDistribution(generator);
    personFactory.coordinate = Coordinate();
    personFactory.coordinate.setX(dad.getCoordinate().getX());
    personFactory.coordinate.setY(mum.getCoordinate().getY());
    return personFactory.generateConsumer();
}