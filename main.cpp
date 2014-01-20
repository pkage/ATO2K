#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
#include "ghost.h"
#include <random>
#include <ctime>
#include <limits>
#include <fstream>


#ifdef _WIN32
void clr() {system("cls");}
void pause() {system("pause");}
std::string datapath = std::string(getenv("APPDATA")) + "\\ATO2K\\"; // hacky workaround to the dilemma of %appdata%
#else
void clr() {system("clear");}


#endif // WIN32

using namespace std;

using namespace gh::tools::log;



void genmap(gh::data::Map &map);
void init_tset(gh::data::Tileset &ts);
void mapeditor();

//int rand() {return 1;};

int main() {



    srand(time(0));
    gh::printGhostVer();
    cout << "\n\nMenu: \n  1) Map Editor\n  2) Load map\n\nSelection: ";
    int sel; cin >> sel;
    if (sel == 1) {mapeditor();}
    if (sel == 2) {;}
}

void genmap(gh::data::Map &map) {
    map.fillMap('a');
    for (int y = 0; y < gh::cs::MAP_WIDTH; y++) {
        for (int x = 0; x < gh::cs::MAP_WIDTH; x++ ) {
            if (0 == rand()%10) {
                  map.write(x,y,'b');
            }
        }
    }
    for (int y = 0; y < gh::cs::MAP_WIDTH; y++) {
        for (int x = 0; x < gh::cs::MAP_WIDTH; x++ ) {
            if (0 == rand()%20) {
                  map.write(x,y,'c');
            }
        }
    }
}

void init_tset(gh::data::Tileset &ts) {
    gh::data::Tile t;
    t.init(0,5,1,1,'a');
    ts.addTile(t);
    t.init(2,5,1,1,'b');
    ts.addTile(t);
    t.init(3,5,1,1,'c');
    ts.addTile(t);
    t.init(3,5,1,1,'d');
    ts.addTile(t);

}

void mapeditor() {
    sf::RenderWindow window(sf::VideoMode(800,600), "test", sf::Style::Default);
    sf::View v; v.setSize(sf::Vector2f(800,600));
    info("Initializing tileset");
    gh::data::Tileset ts("C:\\Users\\PK\\Documents\\CodeBlocks\\A Tale of Two Kingdoms\\bin\\Debug\\tiles.png");
    init_tset(ts);
    gh::data::Map map;
    map.fillMap('a'); bool tmpbool = false,sb = false;
    sf::Vector2i bloc(0,0), b2,b3;
    sf::RectangleShape bhl,bhl2; bhl.setFillColor(sf::Color(255,0,0,20));bhl2.setFillColor(sf::Color(0,0,255,50));
    bhl.setSize(sf::Vector2f(gh::cs::TSET_UNIT_SIZE,gh::cs::TSET_UNIT_SIZE));bhl2.setSize(sf::Vector2f(gh::cs::TSET_UNIT_SIZE,gh::cs::TSET_UNIT_SIZE));
    char cbrush = 'a'; string tmpstr, oname = "newmap.amf";
    //map.write(0,1,'c');
    //map.importMap("C:\\Users\\PK\\Desktop\\export.txt"bhl.setSize(sf::Vector2f(gh::cs::TSET_UNIT_SIZE,gh::cs::TSET_UNIT_SIZE)););
    //for (int c = 0; c < gh::cs::MAP_HEIGHT; c++) {map.importMapRow(map.exportMapRow(c),c);cout << map.exportMapRow(c) << '\n';}
    sf::Event ev;
    while (window.isOpen()) {
        clr();
        cout << "Brush: (" << bloc.x << "," << bloc.y << "), drawing [" << cbrush << "]\nMap path: " << datapath << "maps\\editor\\\nMap save name: " << oname;
        if (sb) {cout << "\nSelecting block (corner1: (" << b2.x << "," << b2.y << ")";}
        cout << "\n\nPress space to access menu.";
        window.pollEvent(ev); if (ev.type == sf::Event::Closed) {cout << "\n\nAre you sure you want to close?\nAll unsaved progress will be lost!\n";tmpstr = gh::kh::getinput("     [y/n]: ");if (tmpstr.at(0) == 'y' || tmpstr.at(0) == 'Y') {break;}}
        window.clear(sf::Color::Black);
        v.setCenter((sf::Vector2f)(bloc * 16));
        window.setView(v);
        gh::render::addMapToBuffer(window, map, ts);


        bhl.setPosition((sf::Vector2f)(bloc * 16));
        window.draw(bhl);
        if (sb) {window.draw(bhl2);}

        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            cout << "\nMenu: \n\t1) Change brush\n\t2) Export map\n\t3) Import map\n\t4) Add/Edit lightsource\n\t5) Return\n\t6) Quit\n\n\t] ";
            while (true) {
                window.pollEvent(ev);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {cout << "\n\nAvailable tiles: [" << ts.getTileList() << "]\n";tmpstr = gh::kh::getinput("New brush: "); cbrush = (tmpstr.length() == 0 || ts.getTileList().find(tmpstr.at(0)) == -1) ? 'a' : tmpstr.at(0);break;}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {cout << "\n\n"; oname = gh::kh::getinput("Export name: "); map.exportMap(datapath + "maps\\editor\\" + oname);pause();break;}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {cout << "\n\n"; tmpstr = gh::kh::getinput("Import name: "); map.importMap(datapath + "maps\\editor\\"  + tmpstr);pause();break;}

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {break;}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {cout << "\n\nAre you sure you want to close?\nAll unsaved progress will be lost!\n";tmpstr = gh::kh::getinput("     [y/n]: ");if (tmpstr.at(0) == 'y' || tmpstr.at(0) == 'Y') {tmpbool = true;break;}}

            }
            if (tmpbool == true) {return;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (map.valid(bloc.x, bloc.y - 1)) {bloc.y--;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (map.valid(bloc.x, bloc.y + 1)) {bloc.y++;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (map.valid(bloc.x - 1, bloc.y)) {bloc.x--;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (map.valid(bloc.x + 1, bloc.y)) {bloc.x++;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            map.write(bloc.x, bloc.y, cbrush);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            gh::kh::wfkr(sf::Keyboard::F);
            if (!sb) {
                b2 = bloc;
                bhl2.setPosition((sf::Vector2f)(b2 * 16));
                sb = true;
            } else {
                if (b2.x < bloc.x) {b3.x = -1;} else {b3.x = 1;}
                if (b2.y < bloc.y) {b3.y = -1;} else {b3.y = 1;}
                bloc.x -= b3.x;
                bloc.y -= b3.y;
                for (int y = bloc.y; y != b2.y; y += b3.y) {
                    for (int x = bloc.x; x != b2.x; x += b3.x) {
                        map.write(x + b3.x, y + b3.y, cbrush);
                    }
                }
                sb = false;
                bloc.x += b3.x;
                bloc.y += b3.y;
            }
        }
    }
    cin.ignore(10000000, '\n');
    return;
}
