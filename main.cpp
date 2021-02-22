#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "PlayBlackJack.h"

int main() {
    Deck deck{};
    Player player{};
    Player dealer{};
    deck.shuffleDeck();
    deck.printDeck();
    if (blackJack(player, dealer, deck)){
        std::cout<<"Player's win with "<<player.getScore()<<" points scored! ";
        std::cout<<"Dealer's score: "<<dealer.getScore();
    }
    else{
        std::cout<<"Player's loss with "<<player.getScore()<<" points scored! ";
        std::cout<<"Dealer's score: "<<dealer.getScore();
    }
    return 0;
}
