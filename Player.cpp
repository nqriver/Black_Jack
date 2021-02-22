//
// Created by lukas on 18.02.2021.
//

#include "Player.h"

void Player::drawCard(Deck &deck) {
    m_score += deck.dealCards().getValue();
}

bool Player::isBust() const{
    return (m_score > maxScore);
}

int Player::getScore() const{
    return m_score;
}
