/*
 * al_handler_bitmap.c
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

#include "al_handler_bitmap.h"

ALLEGRO_BITMAP *load_img(char *img_filename)
{
    ALLEGRO_BITMAP *image = NULL;

    assert(img_filename);

    image = al_load_bitmap(img_filename);

    if(image != 0) {
        al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));
    }

    return image;
}
