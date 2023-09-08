//
// Created by Anthony on 9/8/2023.
//

#include "Game.h"

void Game::_pTurn() {

}

void Game::_cTurn() {

}

void Game::_giveCrib() {
    _crib.at(0) = _pHand.at(4);
    _crib.at(1) = _pHand.at(5);
    _crib.at(2) = _cHand.at(4);
    _crib.at(3) = _cHand.at(5);
}

void Game::_turn() {
    //Shuffle
    _deck.shuffle();
    //Deal
    _deck.deal(&_pHand,&_cHand);
    //show player hand
    std::cout << "----- Player's Hand -----" << std::endl;
    for(auto const& card:_pHand){
        std::cout << card.toString() << std::endl;
    }
    //Players choose crib
    std::cout << "----- Choose Crib -----" << std::endl;
    _giveCrib();
    //cut
    std::cout << "----- Cut Card -----" << std::endl;
    _cutCard = _deck.cut();
    std::cout << _cutCard.toString() << std::endl;
    //Score Non dealer first
    std::cout << "----- Crib Cards -----" << std::endl;
    for(auto const& card:_crib){
        std::cout << card.toString() << std::endl;
    }
    std::array<Card,4> cHand = {_cHand.at(0),_cHand.at(1),_cHand.at(2),_cHand.at(3)};
    std::array<Card,4> pHand = {_pHand.at(0),_pHand.at(1),_pHand.at(2),_pHand.at(3)};;
    if(_isPTurn){
        _addPoints(_scoreHand(&cHand), false);
        if(_winner){
            return;
        }
        _addPoints(_scoreHand(&pHand), true);
        if(_winner){
            return;
        }
        _addPoints(_scoreHand(&_crib), true);
        if(_winner){
            return;
        }
    }else{
        _addPoints(_scoreHand(&pHand), true);
        if(_winner){
            return;
        }
        _addPoints(_scoreHand(&cHand), false);
        if(_winner){
            return;
        }
        _addPoints(_scoreHand(&_crib), false);
        if(_winner){
            return;
        }
    }

    _isPTurn = !_isPTurn;
}

int Game::_scoreHand(std::array<Card,4> *hand) {
    return 20;
}

bool Game::playGame() {
    _turn();
    if(_pScore > 120){
        return true;
    }else if(_cScore > 120){
        return false;
    }else{
        return playGame();
    }
}

void Game::_addPoints(int amt, bool isPlayer) {
    if(isPlayer){
        _pScorePrev = _pScore;
        _pScore += amt;
        std::cout << "----- Player Score -----" << std::endl;
        std::cout << "Current: " << _pScore << std::endl;
        std::cout << "Previous: " << _pScorePrev << std::endl;
        if(_pScore > 120){
            _winner = true;
        }
    }else{
        _cScorePrev = _cScore;
        _cScore += amt;
        std::cout << "----- Computer Score -----" << std::endl;
        std::cout << "Current: " << _cScore << std::endl;
        std::cout << "Previous: " << _cScorePrev << std::endl;
        if(_cScore > 120){
            _winner = true;
        }
    }
}
