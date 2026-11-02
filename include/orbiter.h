#pragma once
#include "center.h"
#include <bn_sprite_items_drone.h>
#include <bn_rect.h>

/**
 * An object that orbits around a center. Orbits using Hooke's law, as if attached by a 2D spring.
 * The stiffness of the spring in each dimension is center.mass() / FORCE_SCALE.
 */
class Orbiter
{
public:
    /**
     * Creates an orbiter.
     *
     * @param starting_location the initial location of the Orbiter
     * @param starting_velocity the initial velocity of the Orbiter, {dx, dy}
     * @param center the center to orbit around
     */
    Orbiter(bn::fixed_point starting_location, bn::fixed_point starting_velocity, Center &center);

    /**
     * Take a step orbiting around the center.
     */
    void update(bn::fixed FORCE_SCALE);

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
    bn::fixed_point _velocity;
    bn::rect _hitbox;
    Center &_center;
};
