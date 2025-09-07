#include <iostream>
#include "random_value.h"
#include "guess.h"
#include "record_highscore.h"

int main() {

    std::string file_name = "high_scores.txt";
    int random_number = generate_random_number(100);
    int score = 0;

    guess(random_number, score);
    std::cout << "Your score is " << score << std::endl;
    record_score(file_name, score);

}