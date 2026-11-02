#pragma once
#include <bn_sprite_items_mothership.h>
#include <bn_sprite_items_mothership_damage.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>

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

    /**
     * Get the mothership's location.
     */
    bn::fixed_point get_location();

    /**
     * Get the hitbox.
     */
    bn::rect get_hitbox();

    /**
     * Set the hitbox.
     */
    void set_hitbox(bn::rect hitbox);


private:
    bn::fixed health_points;    // The ship's hit points
    bn::sprite_ptr ship_sprite; // The ship's graphic
    bn::sprite_ptr ship_sprite_damage; // The ship's graphic
    bn::rect ship_hitbox;
};