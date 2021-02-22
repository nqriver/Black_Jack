cmake_minimum_required(VERSION 3.17)
project(Black_Jack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Black_Jack main.cpp Card.cpp Card.h Deck.cpp Deck.h Player.cpp Player.h PlayBlackJack.h PlayBlackJack2.h)