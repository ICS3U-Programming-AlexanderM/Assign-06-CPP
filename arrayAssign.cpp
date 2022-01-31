// Copyright (c) 2022 Alexander Matheson All rights reserved.

// Created by: Alexander Matheson
// Created on: Jan 31 2022
// This program finds the product of
// all numbers in an array, it then
// splits this array in half.
#include <iostream>
#include <list>
#include <cmath>

// declare constant
const int MAX_NUM = 6;


// function to split the array in half
float splitArray(float originalArr[MAX_NUM], std::list<float> &firstList,
                 std::list<float> &secondList) {
    // declare variables
    float range;
    int rangeInt;
    int counter;
    int counter2;
    // find range of each half
    range = MAX_NUM;
    range = range / 2;
    rangeInt = round(range);
    // for the first half
    for (counter = 0; counter < range; counter++) {
        firstList.push_back(originalArr[counter]);
    }
    // for the second half
    for (counter2 = counter; counter2 < range * 2; counter2++) {
        secondList.push_back(originalArr[counter2]);
    }
}


// function to find the product
float findProduct(float array[MAX_NUM]) {
    // declare variables
    float product = 1;
    int counter;
    // loop to find product
    for (counter = 0; counter < MAX_NUM; counter++) {
        product = product * array[counter];
    }
    return product;
}


int main() {
    // declare variables and arrays
    float numArray[MAX_NUM];
    std::string inputString;
    float inputFloat;
    float productMain;
    int counter = 0;
    std::list<float> list1;
    std::list<float> list2;
    // loop to get input
    do {
        std::cout << "Enter a number: ";
        std::getline(std::cin, inputString);
        // error checking
        try {
            inputFloat = stof(inputString);
            numArray[counter] = inputFloat;
            counter = counter + 1;
        } catch (std::invalid_argument) {
            std::cout << "Invaid input, try again\n";
            continue;
        }
    } while (counter < MAX_NUM);
    // call functions
    productMain = findProduct(numArray);
    splitArray(numArray, list1, list2);
    // display results
    std::cout << "The first half of this list is: ";
    for (float tempWord3 : list1) {
        std::cout << tempWord3 << " ";
    }
    std::cout << "\nThe second half is: ";
    for (float tempWord3 : list2) {
        std::cout << tempWord3 << " ";
    }
    std::cout << "\nThe product is: " << productMain;
}
