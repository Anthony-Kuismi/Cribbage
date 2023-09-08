//
// Created by Anthony on 9/6/2023.
//

#ifndef CRIBBAGE_CARD_H
#define CRIBBAGE_CARD_H
#include <iostream>

class Card {
private:
    int _value;
    std::string _suite;
public:
    Card() = default;
    Card(int value, std::string suite);
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] int getValue() const;
    [[nodiscard]] std::string getSuite() const;
};


#endif //CRIBBAGE_CARD_H
