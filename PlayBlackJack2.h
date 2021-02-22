//
// Created by lukas on 22.02.2021.
//

// In this variant of Black Jack cards are dealt in a different procedure. Firstly player and dealer gets one card for
// each side. Then player takes cards from the deck as long as decides to stop or runs over the limit of 21 points scored.
// Then the same mechanism is repeated for dealer. Finally if anyone loses by exceeding the limit of 21 points winner is
// selected through the greater sum of points scored.


#ifndef BLACK_JACK_PLAYBLACKJACK2_H
#define BLACK_JACK_PLAYBLACKJACK2_H
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "PlayBlackJack.h"

bool playerTurn(Player &player, Deck &deck){
    while (true) {
        std::cout<<"Player's score: "<<player.getScore()<<std::endl;
        if (player.isBust())
            return true;
        else {
            if (playersDecision()) {
                player.drawCard(deck);
                continue;
            } else {                // if player do not want to play any longer return false
                return false;
            }
        }
    }
}

bool dealerTurn(Player &dealer, Deck &deck){
    while (dealer.getScore() < Player::minimumDealerScore){
        dealer.drawCard(deck);
    }
    if (dealer.isBust()) {
        return false;
    }
    else { return true; }
}

bool playRoundBlackJack(Player &player, Player &dealer, Deck &deck){
    player.drawCard(deck);
    dealer.drawCard(deck);
    if (playerTurn(player, deck)) return false;
    if (!dealerTurn(dealer, deck)) return true;
    return player.getScore() > dealer.getScore();
}

#endif //BLACK_JACK_PLAYBLACKJACK2_H
