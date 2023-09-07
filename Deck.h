//
// Created by Anthony on 9/6/2023.
//

#ifndef CRIBBAGE_DECK_H
#define CRIBBAGE_DECK_H
#include "Card.h"
#include <array>
#include <algorithm>
class Deck {
private:
    std::array<Card,52> _cards;
public:
    Deck();
    ~Deck() = default;
    void shuffle();
    void deal(std::array<Card,6> *playerHand, std::array<Card,6> *compHand);
    Card cut();
};


#endif //CRIBBAGE_DECK_H
