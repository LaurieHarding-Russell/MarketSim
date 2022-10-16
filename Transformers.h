#ifndef TRANSFORMERS_H
#define TRANSFORMERS_H

#include "WorldSim/World.h"
#include "Api/WorldDto.h"

using json = nlohmann::json;
// FIXME think about namespacing etc.

CoordinateDto toCoordinateDto(Coordinate coordinate) {
    CoordinateDto coordinateDto = CoordinateDto();
    coordinateDto.x = coordinate.getX();
    coordinateDto.y = coordinate.getY();
    return coordinateDto;
}

CompanyDto toCompanyDto(Company company) {
    CompanyDto companyDto = CompanyDto();
    companyDto.name = company.getName();
    return companyDto;
}

std::vector<CompanyDto> toCompanyDtoList(std::vector<Company> companies) {
    std::vector<CompanyDto> companyDtoList = std::vector<CompanyDto>();
    for (const auto &company : companies) {
        companyDtoList.push_back(toCompanyDto(company));
    }
    return companyDtoList;
}

PersonDto toPersonDto(Consumer person) {
    PersonDto personDto = PersonDto();
    personDto.funds = person.getFunds();
    personDto.coordinate = toCoordinateDto(person.getCoordinate());
    return personDto;
}

std::vector<PersonDto> toPersonDtoList(std::vector<Consumer> people) {
    std::vector<PersonDto> peopleDtoList = std::vector<PersonDto>();
    for (const auto &person : people) {
        peopleDtoList.push_back(toPersonDto(person));
    }
    return peopleDtoList;
}

WorldDto toWorldDto(World* world) {
    WorldDto worldDto = WorldDto();
    worldDto.year = world->getYear();
    worldDto.companies = toCompanyDtoList(world->getCompanies());
    worldDto.people = toPersonDtoList(world->getPeople());
    return worldDto;
}

#endif