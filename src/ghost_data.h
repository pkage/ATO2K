#ifndef GHOST_DATA_H_INCLUDED
#define GHOST_DATA_H_INCLUDED

#include <vector>
#include <fstream>

namespace gh {
    namespace data {
        class Tile {                            // DESIGNED TO BE LIGHTWEIGHT
        private:
            int x, y, width, height;
            char tag;
            bool valid;
        public:
            bool getValid() {return valid;}
            Tile() {
                valid = false;
            }
            char getTag() {return tag;}
            void init(int x, int y, int width, int height, char tag) {
                this->x = x;
                this->y = y;
                this->width = width;
                this->height = height;
                this->tag = tag;
                valid = true;
            }
            Tile(int x, int y, int width, int height, char tag) {
                init(x,y,width,height,tag);
            }
            sf::IntRect get_irect() {
                sf::IntRect tmp;
                if (!valid) {
                    return tmp;
                }
                tmp.left = x * gh::cs::TSET_UNIT_SIZE;
                tmp.top = y * gh::cs::TSET_UNIT_SIZE;       // SET THE BOUNDING EDGES OF THE BOX TO THE BIT OF THE TILESET WE WANT
                tmp.width = width * gh::cs::TSET_UNIT_SIZE; // SHOULD MAKE LOADING SHITE EASIER
                tmp.height = height * gh::cs::TSET_UNIT_SIZE;
                return tmp;
            }
            void devalidate() {valid = false;}
        };
        class Tileset {           // CONTAINS TILES (MAY CONTAIN NUTS)
        private:
            std::vector<Tile> tiles;
            int findFreeTileSlot() {
                for (unsigned int c = 0; c < tiles.size(); c++) {
                    if (!tiles.at(c).getValid()) {
                        return c;
                    }
                }
                return -1;
            }
        public:
            sf::Texture tileset;
            void addTile(Tile tile) {           // ADD A TILE TO THE INDEX
                if (tile.getValid()) {
                    int tmp = findFreeTileSlot();
                    if (tmp == -1) {
                        tiles.push_back(tile);
                    } else {
                        tiles.at(tmp) = tile;
                    }
                }
            }
            sf::IntRect getTileData(char tag) {
                for (unsigned int c = 0; c < tiles.size(); c++) {
                    if (tiles.at(c).getTag() == tag) {
                        return tiles.at(c).get_irect();
                    }
                }
                gh::tools::log::error("attempt to get invalid sf::intrect");
                sf::IntRect ir;
                return ir;
            }
            Tileset() {}
            Tileset(std::string file) {
                if (!tileset.loadFromFile(file)) {
                    tools::log::error("attempted to load invalid image file");
                }
            }
            std::string getTileList() {
                std::string tmp = "";
                for (unsigned int c = 0; c < tiles.size(); c++) {
                    if (tiles.at(c).getValid()) {
                        tmp += tiles.at(c).getTag();
                    }
                }
                return tmp;
            }
        };
        class Map {
          private:
            char cmap[cs::MAP_WIDTH][cs::MAP_HEIGHT];
          public:
            // READ & WRITE FUNCTIONS
            bool valid(int x, int y) {
                if (x < 0 || x >= cs::MAP_WIDTH) {return false;}
                if (y < 0 || y >= cs::MAP_HEIGHT) {return false;}
                return true;
            }
            char read(int x, int y) {
                if (!valid(x,y)) {return '\0';}
                return cmap[y][x];
            }
            bool write(int x, int y, char c) {
                if (!valid(x,y)) {return false;}
                cmap[y][x] = c;
                return true;
            }
            // IMPORT EXPORT FUNCTIONALITY
            std::string exportMapRow(int yindex) {
                if (!valid(0, yindex)) {return "";}
                std::string tmp = "";
                for (int c = 0; c < cs::MAP_WIDTH; c++) {
                    tmp += read(c, yindex);
                }
                return tmp;
            }
            bool exportMap(std::string file) {
                std::ofstream of;
                of.open(file.c_str());
                if (!of) {tools::log::error("unable to export map to " + file);return false;}
                for (int c = 0; c < cs::MAP_HEIGHT; c++) {
                    of << exportMapRow(c) << "\n";
                }
                of.close();
                return true;
            }
            bool importMapRow(std::string line, int yindex) {
                if (!valid(line.size() - 1, yindex)) {tools::log::error("invalid line or length"); return false;}
                for (int c = 0; c < cs::MAP_WIDTH; c++) {
                    write(c,yindex,line.at(c));
                }
                return true;
            }
            bool importMap(std::string file) {
                std::ifstream ifile;
                ifile.open(file.c_str());
                if (!ifile) {tools::log::error("unable to open input file " + file);return false;}
                std::string tmpline;
                for (int c = 0; c < cs::MAP_HEIGHT; c++) {
                    std::getline(ifile, tmpline);
                    if (!importMapRow(tmpline,c)) {
                        tools::log::error("file " + file + " invalid");
                        return false;
                    }
                    if (ifile.eof()) {tools::log::error("reached end of file but not map");return false;}
                }
                tools::log::info("processed " + file + " successfully");
                return true;
            }
            // EXTENDED FUNCTIONALITY
            void fillMap(char c) {
                for (int y = 0; y < cs::MAP_HEIGHT; y++) {
                    for (int x = 0; x < cs::MAP_WIDTH; x++) {
                        write(x,y,c);
                    }
                }
            }

        };
    }
}

#endif // GHOST_DATA_H_INCLUDED
