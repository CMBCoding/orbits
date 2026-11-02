#pragma once
#include <bn_sprite_items_mothership.h>
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
     * Get the damage sprite.
     */
    // bn::sprite_ptr Mothership::get_damage_sprite();

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

    /**
     * Get the mothership's health.
     */
    bn::fixed get_health();
    
    /**
     * Set the mothership's health.
     */
    void set_health(bn::fixed health);

private:
    bn::fixed health_points;    // The ship's hit points
    bn::sprite_ptr ship_sprite; // The ship's graphic
    bn::rect ship_hitbox;
};