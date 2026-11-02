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

// Create a constructor of the Mothership class
Mothership::Mothership(bn::fixed_point ship_location) : ship_sprite(bn::sprite_items::mothership.create_sprite(ship_location))
{
}
