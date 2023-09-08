//
// Created by Anthony on 9/6/2023.
//

#include "Deck.h"
#include <random>

void Deck::shuffle() {
    std::shuffle(std::begin(_cards),std::end(_cards), std::mt19937(std::random_device()()));
}

void Deck::deal(std::array<Card,6> *playerHand, std::array<Card,6> *compHand) {
    for(int i = 0; i < 6; i++){
        playerHand->at(i) = _cards.at(i*2);
        compHand->at(i) = _cards.at(i*2+1);
    }
}

Card Deck::cut() {
    return _cards.at(12);
}

Deck::Deck(){
    for(int i = 0; i <= 12; i ++){
        Card* newCard = new Card(i+1,"diamond");
        _cards.at(i) = * newCard;
        delete(newCard);
    }
    for(int i = 0; i <= 12; i ++){
        Card* newCard = new Card(i+1,"club");
        _cards.at(i+13) = * newCard;
        delete(newCard);
    }
    for(int i = 0; i <= 12; i ++){
        Card* newCard = new Card(i+1,"heart");
        _cards.at(i+26) = * newCard;
        delete(newCard);
    }
    for(int i = 0; i <= 12; i ++){
        Card* newCard = new Card(i+1,"spade");
        _cards.at(i+39) = * newCard;
        delete(newCard);
    }
}

