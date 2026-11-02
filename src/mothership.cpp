#include "mothership.h"
#include <bn_sprite_items_mothership.h>
#include <bn_sprite_items_mothership_damage.h>

/**
 * An object that has a set of hit points and serves as the game
 *  antagonist.
 */

/**
 * Get the sprite.
 */
bn::sprite_ptr Mothership::get_sprite()
{
    return ship_sprite;
};

/**
 * Get the damage sprite.
 */
// bn::sprite_ptr Mothership::get_damage_sprite()
// {
//     return ship_sprite_damage;
// };

/**
 * Get the hitbox.
 */
bn::rect Mothership::get_hitbox()
{
    return ship_hitbox;
};

/**
 * Set the hitbox.
 */
void Mothership::set_hitbox(bn::rect hitbox)
{
    ship_hitbox = hitbox;
};

// Create a constructor of the Mothership class
Mothership::Mothership(bn::fixed_point ship_location) : ship_sprite(bn::sprite_items::mothership.create_sprite(ship_location))
// , ship_sprite_damage(bn::sprite_items::mothership_damage.create_sprite(300, 300)) 
{
    
};

