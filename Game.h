//
// Created by Anthony on 9/8/2023.
//

#ifndef CRIBBAGE_GAME_H
#define CRIBBAGE_GAME_H
#include "Deck.h"

class Game {
private:
    Deck _deck;
    int _pScore = 0,_pScorePrev = 0,_cScore = 0,_cScorePrev = 0;
    std::array<Card,6> _pHand;
    std::array<Card,6> _cHand;
    std::array<Card,4> _crib;
    Card _cutCard;
    std::string difficulty = "easy";
    bool _winner = false;
    bool _isPTurn = true;
    void _pTurn();
    void _cTurn();
    void _giveCrib();
    void _addPoints(int amt, bool isPlayer);
    void _turn();
    int _scoreHand(std::array<Card,4> *hand);
public:
    bool playGame();
};


#endif //CRIBBAGE_GAME_H
