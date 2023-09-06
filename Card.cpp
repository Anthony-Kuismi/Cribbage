//
// Created by Anthony on 9/6/2023.
//

#include "Card.h"

#include <utility>

Card::Card(int value,std::string suite) : _value(value), _suite(std::move(suite)) {
}

int Card::getValue() const{
    return _value;
}

std::string Card::getSuite() const{
    return _suite;
}
