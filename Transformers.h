#ifndef TRANSFORMERS_H
#define TRANSFORMERS_H

#include "WorldSim/World.h"
#include "Api/WorldDto.h"
#include <functional>

using json = nlohmann::json;
// FIXME think about namespacing etc.

CoordinateDto toCoordinateDto(Coordinate coordinate) {
    CoordinateDto coordinateDto = CoordinateDto();
    coordinateDto.x = coordinate.getX();
    coordinateDto.y = coordinate.getY();
    return coordinateDto;
}

InvestorDto toInvestorDto(Investor investor) {
    InvestorDto investorDto = InvestorDto();
    investorDto.name = investor.getName();
    investorDto.funds = investor.getFunds();
    return investorDto;
}

CompanyDto toCompanyDto(Company company) {
    CompanyDto companyDto = CompanyDto();
    companyDto.name = company.getName();
    companyDto.funds = company.getFunds();
    return companyDto;
}

/* Is this a little silly... yup... is it kind of fun? YUP!
// D = dto 
// T = other thing
*/
template <class T, class D>
std::vector<D> toDtoList(std::vector<T> objects, std::function<D(T)> toDto) {
    std::vector<D> dtoList = std::vector<D>();
    for (const auto &object : objects) {
        dtoList.push_back(toDto(object));
    }
    return dtoList;
}

PersonDto toPersonDto(Consumer person) {
    PersonDto personDto = PersonDto();
    personDto.funds = person.getFunds();
    personDto.coordinate = toCoordinateDto(person.getCoordinate());
    return personDto;
}

WorldDto toWorldDto(World* world) {
    WorldDto worldDto = WorldDto();
    worldDto.year = world->getYear();
    std::function<CompanyDto(Company)> companyTransformer = toCompanyDto;
    worldDto.companies = toDtoList(world->getCompanies(), companyTransformer);

    std::function<InvestorDto(Investor)> investorTransformer = toInvestorDto;
    worldDto.investors = toDtoList(world->getInvestors(), investorTransformer);

    std::function<PersonDto(Consumer)> toPersonTransformer = toPersonDto;
    worldDto.people = toDtoList(world->getPeople(), toPersonTransformer);
    return worldDto;
}

#endif