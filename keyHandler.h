#include <SFML/Window.hpp>
#include <string.h>

//using namespace std;

#ifndef WFKR_TIMEOUT
#define WFKR_TIMEOUT 200
#endif

#ifndef keyHandler_h
#define keyHandler_h
namespace gh {
    namespace kh {
        void wfkr(sf::Keyboard::Key key) {
            sf::Clock clock;
            sf::Time time;
            time = clock.restart();
            while (sf::Keyboard::isKeyPressed(key) && time.asMilliseconds() < WFKR_TIMEOUT ) {
                time = clock.getElapsedTime();
            }
        }

        std::string returnPressedKey() {
            //while (window.isOpen()) {
                // Control Characters
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    wfkr(sf::Keyboard::BackSpace);
                    return "BKSP";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    wfkr(sf::Keyboard::Return);
                    return "ACC";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    wfkr(sf::Keyboard::Space);
                    return " ";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                    wfkr(sf::Keyboard::Tab);
                    return "TAB";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) {return "-";}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
                    // Uppercase Letters
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        wfkr(sf::Keyboard::A);
                        return "A";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        wfkr(sf::Keyboard::B);
                        return "B";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                        wfkr(sf::Keyboard::C);
                        return "C";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        wfkr(sf::Keyboard::D);
                        return "D";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        wfkr(sf::Keyboard::E);
                        return "E";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                        wfkr(sf::Keyboard::F);
                        return "F";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                        wfkr(sf::Keyboard::G);
                        return "G";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                        wfkr(sf::Keyboard::H);
                        return "H";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                        wfkr(sf::Keyboard::I);
                        return "I";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                        wfkr(sf::Keyboard::J);
                        return "J";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                        wfkr(sf::Keyboard::K);
                        return "K";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                        wfkr(sf::Keyboard::L);
                        return "L";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                        wfkr(sf::Keyboard::M);
                        return "M";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                        wfkr(sf::Keyboard::N);
                        return "N";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                        wfkr(sf::Keyboard::O);
                        return "O";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                        wfkr(sf::Keyboard::P);
                        return "P";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                        wfkr(sf::Keyboard::Q);
                        return "Q";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                        wfkr(sf::Keyboard::R);
                        return "R";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        wfkr(sf::Keyboard::S);
                        return "S";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                        wfkr(sf::Keyboard::T);
                        return "T";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                        wfkr(sf::Keyboard::U);
                        return "U";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                        wfkr(sf::Keyboard::V);
                        return "V";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        wfkr(sf::Keyboard::W);
                        return "W";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                        wfkr(sf::Keyboard::X);
                        return "X";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                        wfkr(sf::Keyboard::Y);
                        return "Y";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                        wfkr(sf::Keyboard::Z);
                        return "Z";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                        wfkr(sf::Keyboard::Num0);
                        return ")";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                        wfkr(sf::Keyboard::Num1);
                        return "!";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                        wfkr(sf::Keyboard::Num2);
                        return "@";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                        wfkr(sf::Keyboard::Num3);
                        return "#";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                        wfkr(sf::Keyboard::Num4);
                        return "$";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                        wfkr(sf::Keyboard::Num5);
                        return "%";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                        wfkr(sf::Keyboard::Num6);
                        return "^";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                        wfkr(sf::Keyboard::Num7);
                        return "&";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
                        wfkr(sf::Keyboard::Num8);
                        return "*";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
                        wfkr(sf::Keyboard::Num9);
                        return "(";
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) {
                        wfkr(sf::Keyboard::SemiColon);
                        return ":";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
                        wfkr(sf::Keyboard::Quote);
                        return "\"";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
                        wfkr(sf::Keyboard::LBracket);
                        return "{";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
                        wfkr(sf::Keyboard::RBracket);
                        return "}";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash)) {
                        wfkr(sf::Keyboard::BackSlash);
                        return "|";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {
                        wfkr(sf::Keyboard::Comma);
                        return "<";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
                        wfkr(sf::Keyboard::Period);
                        return ">";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
                        wfkr(sf::Keyboard::Equal);
                        return "+";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {
                        wfkr(sf::Keyboard::Dash);
                        return "_";
                    }
                } else {
                    // Lowercase Letters
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        wfkr(sf::Keyboard::A);
                        return "a";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        wfkr(sf::Keyboard::B);
                        return "b";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                        wfkr(sf::Keyboard::C);
                        return "c";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        wfkr(sf::Keyboard::D);
                        return "d";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        wfkr(sf::Keyboard::E);
                        return "e";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                        wfkr(sf::Keyboard::F);
                        return "f";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                        wfkr(sf::Keyboard::G);
                        return "g";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                        wfkr(sf::Keyboard::H);
                        return "h";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                        wfkr(sf::Keyboard::I);
                        return "i";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                        wfkr(sf::Keyboard::J);
                        return "j";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                        wfkr(sf::Keyboard::K);
                        return "k";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                        wfkr(sf::Keyboard::L);
                        return "l";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                        wfkr(sf::Keyboard::M);
                        return "m";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                        wfkr(sf::Keyboard::N);
                        return "n";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                        wfkr(sf::Keyboard::O);
                        return "o";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                        wfkr(sf::Keyboard::P);
                        return "p";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                        wfkr(sf::Keyboard::Q);
                        return "q";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                        wfkr(sf::Keyboard::R);
                        return "r";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        wfkr(sf::Keyboard::S);
                        return "s";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                        wfkr(sf::Keyboard::T);
                        return "t";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                        wfkr(sf::Keyboard::U);
                        return "u";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                        wfkr(sf::Keyboard::V);
                        return "v";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        wfkr(sf::Keyboard::W);
                        return "w";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                        wfkr(sf::Keyboard::X);
                        return "x";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                        wfkr(sf::Keyboard::Y);
                        return "y";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                        wfkr(sf::Keyboard::Z);
                        return "z";
                    }
                    // Symbols / Numbers
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
                        wfkr(sf::Keyboard::Subtract);
                        return "-";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
                        wfkr(sf::Keyboard::Equal);
                        return "=";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                        wfkr(sf::Keyboard::Num0);
                        return "0";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                        wfkr(sf::Keyboard::Num1);
                        return "1";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                        wfkr(sf::Keyboard::Num2);
                        return "2";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                        wfkr(sf::Keyboard::Num3);
                        return "3";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                        wfkr(sf::Keyboard::Num4);
                        return "4";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                        wfkr(sf::Keyboard::Num5);
                        return "5";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                        wfkr(sf::Keyboard::Num6);
                        return "6";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                        wfkr(sf::Keyboard::Num7);
                        return "7";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
                        wfkr(sf::Keyboard::Num8);
                        return "8";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
                        wfkr(sf::Keyboard::Num9);
                        return "9";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) {
                        wfkr(sf::Keyboard::SemiColon);
                        return ":";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
                        wfkr(sf::Keyboard::Quote);
                        return "\'";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
                        wfkr(sf::Keyboard::LBracket);
                        return "[";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
                        wfkr(sf::Keyboard::RBracket);
                        return "]";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash)) {
                        wfkr(sf::Keyboard::BackSlash);
                        return "\\";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {
                        wfkr(sf::Keyboard::Comma);
                        return ",";
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
                        wfkr(sf::Keyboard::Period);
                        return ".";
                    }
                }
            return "NULL";
        }
        void removeLastChar(std::string &s) {
            if (s.length() != 0) {
                s.erase(s.length() - 1);
            }
        }
        void wfakr() {
            while (returnPressedKey() != "NULL") {}
        }
        std::string getinput(std::string prompt) {
            std::string tmp = "", t2;
            bool changed = true;
            wfakr();
            while (true) {
                if (changed) {
                std::cout << "\r";
                    for (unsigned int c = 0; c <= tmp.length() + prompt.length(); c++) {
                        std::cout << " ";
                    }
                    std::cout << "\r" << prompt << tmp;
                    changed = false;
                }
                t2 = returnPressedKey();
                if (t2 == "NULL" || t2 == "TAB") {} else if (t2 ==  "ACC") {
                    std::cout << "\n";
                    return tmp;
                } else if (t2 == "BKSP") {
                    removeLastChar(tmp); changed = true;
                } else {
                    tmp += t2; changed = true;
                }
            }
        }
    }
}

#endif
