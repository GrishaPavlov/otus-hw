#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

bool is_in_map(std::string name, const std::map<std::string, int> &map) {
    try {
        map.at(name);
    } catch (const std::out_of_range &ex) {
        return false;
    }
    return true;
}

int value_from_map(std::string name, const std::map<std::string, int> &map) {
    std::cout << std::endl;
    try {
        return map.at(name);
    } catch (const std::out_of_range &ex) {
        return -1;
    }
}

void record_score(std::string file_name, int score) {
    const std::string high_scores_filename = file_name;

    // Ask about name
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;
    std::map<std::string, int> records;

    // Read current entry and highscore table. Replace if highscore is better
    {
        int attempts_count = score;
        std::ifstream in_file{high_scores_filename};
        if (!in_file.is_open()) {
            std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
            return;
        }

        std::string username;
        int high_score = 0;

        while (true) {
            // Read the username first
            in_file >> username;
            in_file >> high_score;
            // Ignore the end of line symbol
            in_file.ignore();

            if (username == "")
                break;

            // Record entry if not in map
            if (!is_in_map(username, records))
                records[username] = high_score;

            if (in_file.fail()) {
                break;
            }
        }

        // Write current entry if not existent or better
        if (!is_in_map(user_name, records)) {
            records[user_name] = attempts_count;
        } else if (value_from_map(user_name, records) >= attempts_count) {
            records[user_name] = attempts_count;
        }
    }

    // Write current records map to file
    {
        std::ofstream out_file{high_scores_filename};
        if (!out_file.is_open()) {
            std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
            return;
        }

        for (const auto &pair: records) {
            out_file << pair.first << ' ';
            out_file << pair.second << std::endl;
        }
    } // end of scope here just to mark end of the logic block of code

    // Read the high score file and print all results
    {
        std::ifstream in_file{high_scores_filename};
        if (!in_file.is_open()) {
            std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
            return;
        }

        std::cout << "High scores table:" << std::endl;

        std::string username;
        int high_score = 0;
        while (true) {
            // Read the username first
            in_file >> username;
            // Read the high score next
            in_file >> high_score;
            // Ignore the end of line symbol
            in_file.ignore();

            if (in_file.fail()) {
                break;
            }

            // Print the information to the screen
            std::cout << username << '\t' << high_score << std::endl;
        }
    }
}
