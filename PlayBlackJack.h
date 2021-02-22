//
// Created by lukas on 18.02.2021.
//

#ifndef BLACK_JACK_PLAYBLACKJACK_H
#define BLACK_JACK_PLAYBLACKJACK_H
#include <iostream>
#include "Player.h"
#include "Deck.h"

// In this variant of Black Jack cards are dealt alternately for player and dealer. When one player passes the limit of
// 21 points game is terminated. Differently, if one player decides to stop taking cards game is not terminated and second
// player can still take cards from the deck. If each player decides to stop taking cards game result is decided via the
// greater amount of points scored.

enum class StatesOfPlay{
    busted,
    continued,
    stopped
};


bool playersDecision(){
    char choice{};
    std::cout<<"Do you want to draw another card?(y/n) ";
    while (true) {
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') return true;
        else if (choice == 'n' || choice == 'N') return false;
    }
}


StatesOfPlay playersTurn(Player &player, Deck &deck){
    std::cout<<"Player's score: "<<player.getScore()<<std::endl;
    if (player.isBust())
        return StatesOfPlay::busted;
    else {
        if (playersDecision()) {
            player.drawCard(deck);
            return StatesOfPlay::continued;
        } else {                // if player do not want to play any longer return false
            return StatesOfPlay::stopped;
        }
    }
}

StatesOfPlay dealersTurn(Player &dealer, Deck &deck){
    if (dealer.getScore() < Player::minimumDealerScore){
        dealer.drawCard(deck);
        return StatesOfPlay::continued;
    }
    else if (dealer.isBust()) {
        return StatesOfPlay::busted;
    }
   else /*if (dealer.getScore() >= Player::minimumDealerScore and !dealer.isBust())*/{
        return StatesOfPlay::stopped;
    }
}

bool blackJack(Player &player, Player &dealer, Deck &deck){
    player.drawCard(deck);
    dealer.drawCard(deck);
    StatesOfPlay playerState{StatesOfPlay::continued};
    StatesOfPlay dealerState{StatesOfPlay::continued};
    while (playerState != StatesOfPlay::stopped or dealerState != StatesOfPlay::stopped){
        if (playerState == StatesOfPlay::continued) {
            playerState = playersTurn(player, deck);
            if (player.isBust()) { return false; }
        }

        if (dealerState == StatesOfPlay::continued) {
            dealerState = dealersTurn(dealer, deck);
            if (dealer.isBust()) { return true; }
        }
    }
    return (player.getScore() >= dealer.getScore());
}
#endif //BLACK_JACK_PLAYBLACKJACK_H
