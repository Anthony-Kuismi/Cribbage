//
// Created by Anthony on 9/6/2023.
//

#ifndef CRIBBAGE_CARD_H
#define CRIBBAGE_CARD_H
#include <string>

class Card {
private:
    std::string _suite;
    int _value;
public:
    Card() = default;
    Card(int value, std::string suite);
    [[nodiscard]] int getValue() const;
    [[nodiscard]] std::string getSuite() const;
};


#endif //CRIBBAGE_CARD_H
