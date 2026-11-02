#pragma once
#include <bn_sprite_items_mothership.h>
#include <bn_sprite_ptr.h>

/**
 * An object that has a set of hit points and serves as the game
 *  antagonist.
 */

class Mothership
{
    public:
        /**
         * @param ship_location the starting location of the mothership.
         */
        
        Mothership(bn::fixed_point ship_location);

        /**
         * Get the sprite.
         */
        bn::sprite_ptr get_sprite();

    private:
        bn::fixed health_points; //The ship's hit points
        bn::sprite_ptr ship_sprite; //The ship's graphic

};