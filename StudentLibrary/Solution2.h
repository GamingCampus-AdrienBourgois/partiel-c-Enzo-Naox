#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

class Solution2 {
public:
    static float GetBalance(const std::string& accountName) {
        std::string filePath = "BankAccount/" + accountName + ".txt";

        // Open the file
        std::ifstream inputFile(filePath);
        if (!inputFile.is_open()) {
            throw std::runtime_error("File not found: " + filePath);
        }

        float balance = 0.0f;
        std::string line;

        // Read and process each line in the file
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string operation;
            float amount;

            // Read operation and amount from each line
            if (!(iss >> operation >> amount)) {
                throw std::runtime_error("Error reading file: " + filePath);
            }

            // Update balance based on the operation
            if (operation == "DEPOSIT") {
                balance += amount;
            }
            else if (operation == "WITHDRAW") {
                balance -= amount;
            }
            else {
                throw std::runtime_error("Invalid operation in file: " + filePath);
            }
        }

        // Close the file
        inputFile.close();

        return balance;
    }
};

#endif
