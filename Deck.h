//
// Created by lukas on 17.02.2021.
//

#ifndef BLACK_JACK_DECK_H
#define BLACK_JACK_DECK_H


#include <array>
#include "Card.h"

class Deck {
public:
    using array_type = std::array<Card, 52>;
    std::size_t m_currentCardIndex{ 0 };
private:
    array_type m_deckOfCards{};
public:
    Deck();
    void printDeck() const;
    void shuffleDeck();
    const Card &dealCards();

};


#endif //BLACK_JACK_DECK_H
