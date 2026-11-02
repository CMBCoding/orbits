#pragma once
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include "orbiter.h"
#include "mothership.h"
#include "center.h"
#include <bn_log.h>

/**
 * Function that take a sprite and a size for the sprite and
 * creates a hit box for the Orbiter object.
 */
bn::rect create_orbiter_hitbox(Orbiter orbiter, bn::size size)
{
    return bn::rect(orbiter.get_sprite().x().round_integer(),
                    orbiter.get_sprite().y().round_integer(),
                    size.width(),
                    size.height());
    BN_LOG("Orbiter Hitbox created");
};

/**
 * Function that take a sprite and a size for the sprite and
 * creates a hit box for the Center (the player ship) object.
 */
bn::rect create_center_hitbox(Center center, bn::size size)
{
    return bn::rect(center.get_sprite().x().round_integer(),
                    center.get_sprite().y().round_integer(),
                    size.width(),
                    size.height());
};

/**
 * Function that take a sprite and a size for the sprite and
 * creates a hit box for the Mothership (the enemy ship) object.
 */
// bn::rect create_center_hitbox(bn::sprite_ptr sprite, bn::size size) {
//     return bn::rect(sprite.x().round_integer(),
//                     sprite.y().round_integer(),
//                     size.width(),
//                     size.height());
// };