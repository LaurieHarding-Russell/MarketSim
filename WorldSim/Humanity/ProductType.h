#ifndef PRODUCT_TYPE_H
#define PRODUCT_TYPE_H

#include <vector>

enum ProductType {
    FOOD,
    TRAVEL,
    EDUCATION,
    HEALTH,
    HAPPINESS
};

static std::vector<ProductType> ALL_PRODUCTS({
    ProductType::FOOD,
    ProductType::TRAVEL,
    ProductType::EDUCATION,
    ProductType::HEALTH,
    ProductType::HAPPINESS
});
#endif