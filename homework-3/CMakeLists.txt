cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)

project(03.homework)

add_executable(
		Guessing_Game
		guess_the_number/guessing_game.cpp
		guess_the_number/guess.cpp
		guess_the_number/random_value.cpp
		guess_the_number/record_highscore.cpp

)