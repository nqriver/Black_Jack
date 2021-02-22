//
// Created by lukas on 18.02.2021.
//

#ifndef BLACK_JACK_PLAYER_H
#define BLACK_JACK_PLAYER_H


#include "Deck.h"

class Player {
public:
    static constexpr int minimumDealerScore{ 17 };
    static constexpr int maxScore{ 21 };
private:
    int m_score{};
public:
    Player() = default;
    int getScore() const;
    void drawCard(Deck &deck);
    bool isBust() const;
};


#endif //BLACK_JACK_PLAYER_H
