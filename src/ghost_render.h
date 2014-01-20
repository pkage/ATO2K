#ifndef GHOST_RENDER_H_INCLUDED
#define GHOST_RENDER_H_INCLUDED

namespace gh {
    namespace render {

        void addMapToBuffer(sf::RenderWindow &window, data::Map &map, data::Tileset ts) {
            sf::Sprite spr; spr.setTexture(ts.tileset);
            for (int y = 0; y < cs::MAP_HEIGHT; y++) {
                for (int x = 0; x < cs::MAP_WIDTH; x++) {
                    spr.setTextureRect(ts.getTileData(map.read(x,y)));
                    spr.setPosition(x * cs::TSET_UNIT_SIZE, y * cs::TSET_UNIT_SIZE);
                    window.draw(spr);
                }
            }
        }

    }
}

#endif // GHOST_RENDER_H_INCLUDED
