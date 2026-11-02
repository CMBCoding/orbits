#pragma once
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
/**
 * A center of mass to be orbited around. Position is controlled by the player.
 */
class Center
{
public:
    /**
     * Creates a new center.
     *
     * @param starting_position the initial location of the center
     * @param mass the mass of the center. The larger the value, the greater the attraction
     * @param speed the speed at which the center moves when the d-pad is held
     */
    Center(bn::fixed_point starting_position, bn::fixed mass, bn::fixed speed);

    /**
     * Updates the location of the Center based on player direction with the d-pad.
     */
    void update();

    bn::fixed_point position();

    bn::fixed mass();

    /**
     * Get the sprite.
     */
    bn::sprite_ptr get_sprite();

     /**
     * Get the hitbox.
     */
    bn::rect get_hitbox();

    /**
     * Set the hitbox.
     */
    void set_hitbox(bn::rect hitbox);

private:
    bn::sprite_ptr _sprite;
    bn::fixed _mass;  // the mass of the center. The larger the value, the greater the attraction
    bn::fixed _speed; // the speed at which the center moves when the d-pad is held
    bn::rect center_hitbox; //Hitbox of the center
};