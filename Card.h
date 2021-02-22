//
// Created by lukas on 17.02.2021.
//

#ifndef BLACK_JACK_CARD_H
#define BLACK_JACK_CARD_H

enum class CardSuit{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUIT
};
enum class CardRank{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANK
};

class Card {
private:
    CardRank m_rank;
    CardSuit m_suit;
public:
    Card() = default;
    Card(CardRank rank, CardSuit suit);
    void printCard() const;
    int getValue() const;
};


#endif //BLACK_JACK_CARD_H
