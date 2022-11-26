#include "colormod.h" // namespace Color
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    // cout << "This ->" << red << "word" << def << "<- is red." << endl;
    std::cout << "\x1b]50;";
    cout << "\033[1;43m\033[4;31mbold red text\n\n\n";
}
