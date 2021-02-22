//
// Created by lukas on 17.02.2021.
//

#include "Deck.h"
#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cassert>


Deck::Deck() {
    std::size_t cardCounter{ 0 };
    auto suits = static_cast<std::size_t>(CardSuit::MAX_SUIT);
    auto ranks = static_cast<std::size_t>(CardRank::MAX_RANK);
    for (std::size_t suit{ 0 }; suit < suits; ++suit){
        for (std::size_t rank{ 0 }; rank < ranks; ++rank){
            m_deckOfCards[cardCounter] = {static_cast<CardRank>(rank), static_cast<CardSuit>(suit)};
            cardCounter++;
        }
    }
}

void Deck::printDeck() const {
    for (const auto &cardInDeck : m_deckOfCards){
        cardInDeck.printCard();
        std::cout<<std::endl;
    }
}

void Deck::shuffleDeck() {
    static std::mt19937 mtVar{ static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(m_deckOfCards.begin(), m_deckOfCards.end(), mtVar);
    m_currentCardIndex = 0;
}

const Card &Deck::dealCards() {
    assert(m_currentCardIndex < m_deckOfCards.size());
    return m_deckOfCards[m_currentCardIndex++];
}
