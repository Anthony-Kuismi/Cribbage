#include <iostream>
#include "Deck.h"
int main() {
    Deck deck;
    std::array<Card,6> player;
    std::array<Card,6> comp;
    deck.shuffle();
    deck.deal(&player,&comp);
    for(const auto& card:player){
        std::cout<< card.getValue() << " " << card.getSuite() << std::endl;
    }
    return 0;
}
