#include "mothership.h"
#include <bn_sprite_items_mothership.h>

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

/**
 * Get the mothership's health.
 */
bn::fixed Mothership::get_health() {
    return health_points;
};

/**
 * Set the mothership's health.
 */
void Mothership::set_health(bn::fixed health) {
    health_points = health;
};


// Create a constructor of the Mothership class
Mothership::Mothership(bn::fixed_point ship_location) : ship_sprite(bn::sprite_items::mothership.create_sprite(ship_location)),
health_points(30)
{
};

