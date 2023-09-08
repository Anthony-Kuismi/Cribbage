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

std::string Card::toString() const {
    std::string temp;
    switch (_value) {
        case 11:
            temp = "J";
            break;
        case 12:
            temp = "Q";
            break;
        case 13:
            temp = "K";
            break;
        case 1:
            temp = "A";
            break;
        default:
            temp = std::to_string(_value);
            break;
    }
    return temp + " " + _suite;
}
