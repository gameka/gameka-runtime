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

#ifndef CHOICETEXT_H_
#define CHOICETEXT_H_

#include <vector>
#include <iostream>
#include <SDL/SDL_gfxPrimitives.h>


#include "Modal.h"

#include "Text.h"
#include "GameData.h"
#include "Rectangle.h"
#include "InputManager.h"
#include "Sprite.h"

class Text;
class GameData;
class Rectangle;
class InputManager;
class Sprite;

/**
 * @brief Contexto modal para escolha de opções.
 *
 */
class ChoiceText : public Modal {
public:
        /**
         * @brief Construtor.
         *
         * @param posicao Posição:\n
                            - 0: embaixo;
                            - 1: em cima.
         */
        ChoiceText(int posicao);
        /**
         * @brief
         *
         */
        virtual ~ChoiceText();

        /**
         * @brief Adiciona uma escolha.
         *
         * @param choice Texto da escolha.
         */
        void addChoice(std::string choice);
        /**
         * @brief
         *
         * @param dt
         */
        int update(int dt);
        /**
         * @brief Verifica input das escolhas e muda os menus. ENTER faz escolher um.
         *
         * @param screen
         */
        void render(Screen *screen);

        std::vector<std::string> choices; /**< As escolhas. */
        std::vector<Text*> texts; /**< Textos das escolhas. */

        Vector2 pos; /**< Posição real. */
        int barWidth; /**< Largura da barra. */
        int currentChoice; /**< Escolha atual. */
        int mouseCurrentChoice; /**< Escolha atual do mouse. */

        int selectorAlpha; /**<  */
        int selectorAlphaDirection; /**<  */

        InputManager *inputManager; /**< */

        static const int POS_DOWN = 0; /**< */
        static const int POS_UP = 1; /**<  */
};

#endif /* CHOICETEXT_H_ */
