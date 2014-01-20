#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#ifndef GHOST_VER
#define GHOST_VER "v0.4 alpha"
#endif // Manage versions

// INCLUDE PREREQUISITES
#include <iostream>

// BASIC NAMESPACE
namespace gh {
    void printGhostVer() {
        std::cout << "Ghost Engine " << GHOST_VER << "\n(c) 2014 Patrick Kage";
    }
}

// INCLUDE BLOK
#include "ghost_consts.h"
#include "ghost_tools.h"
#include "ghost_data.h"
#include "ghost_render.h"
#include "keyHandler.h"

#endif // GHOST_H_INCLUDED
