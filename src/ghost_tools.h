#ifndef GHOST_TOOLS_H_INCLUDED
#define GHOST_TOOLS_H_INCLUDED

#include <cmath>
#include <sstream>
#include <SFML/System.hpp>
#include <iostream>

namespace gh {
    namespace tools {
        float betweenTwoPoints(int x1, int y1, int x2, int y2) {
            return std::sqrt(std::pow(y2 - y1, 2) + std::pow(x2 - x1, 2));
        }
        float betweenTwoPoints(sf::Vector2i v1, sf::Vector2i v2) {
            return betweenTwoPoints(v1.x, v1.y, v2.x, v2.y);
        }
        int strToInt(std::string str) {
            return atoi(str.c_str());
        }
        std::string intToStr(int i) {
            std::stringstream ss; ss.clear();
            ss << i;
            return ss.str();
        }
        namespace log {
            void write(std::string item) {
                std::cout << '\n' << item;
            }
            void error(std::string item) {
                std::cout << "\n[ERROR] " << item;
            }
            void info(std::string item) {
                std::cout << "\n[INFO] " << item;
            }
        }
    }

}

#endif // GHOST_TOOLS_H_INCLUDED
