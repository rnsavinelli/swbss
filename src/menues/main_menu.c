/*
 * main_menu.c
 * 
 * Copyright 2019 Roberto Nicolás Savinelli <rnsavinelli@est.frba.utn.edu.ar>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <allegro5/allegro.h> 
#include <stdio.h>
#include "struct.h"
#include "application.h"

bool logic_main_menu(int window_width, int window_height, app_t *app_struct)
{
    unsigned char *menu;
    
    assert(app_struct);

    menu = &(app_struct->menu);
    
    assert(menu);
 
    if(handler_key(ALLEGRO_KEY_ENTER)) {
        app_start(window_width, window_height, app_struct);
        (*menu) = MENU_GAME_START;
    }
    
    if(handler_key(ALLEGRO_KEY_ESCAPE)) {
        (*menu) = MENU_EXIT;
        return false;
    }
    
    return true;
}

bool draw_main_menu(int window_width, int window_height, app_t *app_struct)
{
    ALLEGRO_FONT *font;

    assert(app_struct);

    font = app_struct->fonts[FONT_START];

    assert(font);
    
    al_clear_to_color(al_map_rgb(12,12,12));
    
    al_draw_text(font, al_map_rgb(255, 215, 0), 
                window_width/2, window_height/4 - al_get_font_line_height(font),  
                ALLEGRO_ALIGN_CENTER, "Simple Wave Based Space Shooter (SWBSS)");
                 
    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*2 - al_get_font_line_height(font)*5, 
                ALLEGRO_ALIGN_CENTER, "Use the arrow keys to move your character and the spacebar to shoot,");
                 
    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*2 - al_get_font_line_height(font)*4, 
                ALLEGRO_ALIGN_CENTER, "if you collide with an enemy, an asteroid or your tolerance reaches zero");
                     
    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*2 - al_get_font_line_height(font)*3, 
                ALLEGRO_ALIGN_CENTER, "you'll loose a life point. If you run out of lives it's game over.");
                 
    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*2 - al_get_font_line_height(font), 
                ALLEGRO_ALIGN_CENTER, "Good luck!");
                 
    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*2 + al_get_font_line_height(font)*2, 
                ALLEGRO_ALIGN_CENTER, "Press ENTER to start");

    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*2 + al_get_font_line_height(font)*4, 
                ALLEGRO_ALIGN_CENTER, "Press ESCAPE to exit");

    al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*3 + al_get_font_line_height(font)*4,
                ALLEGRO_ALIGN_CENTER, "Fork of GNASS by Savinelli Roberto Nicolás");

       al_draw_text(font, al_map_rgb(255, 255, 255), 
                window_width/2, (window_height/4)*3 + al_get_font_line_height(font)*6,
                ALLEGRO_ALIGN_CENTER, "GNASS was originally developed by Piccardi Juan Ignacio, Savinelli Roberto Nicolás, Taverso José Daniel");
                 
    return true;
}
