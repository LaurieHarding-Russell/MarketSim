#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <algorithm>

#include "./Consumer.h"
#include "../Humanity/Building.h"
#include "../Humanity/ProductType.h"

// Might want business to have multiple locations. Keeping it simple for now.
class Company: public Building {
    public:
    Company();
    Company(std::string name);
    std::string getName();
    
    Company* setFunds(double funds);
    double getFunds();

    Company* setProductType(ProductType productType);

    Consumer getCeo();
    std::vector<Consumer> getEmployees();

    void evaluateCeo();
    void removePervicedWorstEmployees();
    // FIXME static blaa
    // bool employeeSortOperator (Consumer i, Consumer j);
    static bool employeeSortOperator (Consumer i, Consumer j);
    void hireBestPercivedBestEmployees(std::vector<Consumer> unemployed);

    double calculateEmployeeSalary();
    void paySalaries();
    void buyUpgrades();
    void produce();

    bool canSellProduct(ProductType product, double amount);
    // returns cost;
    double sellProduces(double amount);

    private:
        std::string name;
        Consumer ceo;
        std::vector<Consumer> employees;
        double funds;
        ProductType produces;
        double amountProduced;
        double equipmentModifier;
        double productStored;
        
};

#endif