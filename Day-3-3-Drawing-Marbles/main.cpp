#include <iostream>

using namespace std;

int main() {

    // A bag contains 3 red marbles and 4 blue marbles.
    // Then, 2 marbles are drawn from the bag, at random, without replacement.
    // If the first marble drawn is red,
    // what is the probability that the second marble is blue?

    // Since there are 2 red marbles and 4 blue marbles left after the first drawn
    // Then the chance to get a blue marble is 4/(2+4) = 1/3

    cout << "1/3" << endl;

    return 0;
}