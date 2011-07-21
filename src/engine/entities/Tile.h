/***********************************************

Gameka: A game development tool for non-programmers
Copyright (C) 2011 Igor Augusto de Faria Costa

This software is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

************************************************/

#ifndef TILE_H_
#define TILE_H_

#include <SDL/SDL.h>
#include <stdio.h>

#include "Tileset.h"
#include "Vector2.h"
#include "Rectangle.h"

class Tileset;
class Vector2;
class Rectangle;


/**
 * @brief Classe representando um tile,
 * que é um bloco de imagem do mapa.
 *
 */
class Tile  {
public:
        /**
         * @brief Construtor.
         *
         * @param x Posição x do Tile (em píxeis).
         * @param y Posição y do Tile (em píxeis).
         * @param w Largura em píxeis;
         * @param h Altura em píxeis.
         */
        Tile(int x, int y, int w, int h);
        /**
         * @brief
         *
         */
        virtual ~Tile();

        /**
         * @brief Determina o tipo de colisão do Tile.
         *
         * @param type Tipo de colisão: \n
                        - 0: passa;
                        - 1: bloqueia;
         */
        void setCollisionType(int type);

        /**
         * @brief Obtém a SDL_Surface do Tileset deste Tile.
         *
         */
        SDL_Surface* getTilesetSurface();
        /**
         * @brief Obtém o Rectangle desse Tile.
         *
         */
        Rectangle getTileRect();

        SDL_Rect rectangleTileMap; /**< SDL_Rect do Tile. */

        int collisionType; /**< Tipo de colisão:  \n
                        - 0: passa;
                        - 1: bloqueia; */
        Vector2 pos; /**< Posição do Tile */

        Tileset *tileset; /**< Tileset do Tile */

        static const int COLLISION_BLOCK = 1; /**<  */
        static const int COLLISION_PASS = 0; /**<  */

};

#endif /* TILE_H_ */
