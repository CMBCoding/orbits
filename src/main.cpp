#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>
#include <bn_keypad.h>
#include "orbiter.h"
#include "hitbox.h"
#include "mothership.h"
#include <bn_rect.h>
#include <bn_log.h>
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_bg.h"
#include "bn_sprite_items_explosion.h"
#include "bn_regular_bg_items_victorybg.h"
#include "bn_sprite_items_mothership_damage.h"

// A scaling factor by which to reduce the force applied when orbiting
// Important for numerical stability
static constexpr bn::fixed FORCE_SCALE = 10;

// Maximum number of orbiters allowed on the screen
static constexpr int MAX_ORBITERS = 30;

// Default starting posiiton and velocity for Orbiter
static constexpr bn::fixed_point ORBITER_START_POSIITON = {0, 0};
static constexpr bn::fixed_point ORBITER_START_VELOCITY = {0, 5};

// Set the size of the sprites
static constexpr bn::size ORBITER_SIZE = {16, 16};
static constexpr bn::size CENTER_SIZE = {32, 32};
static constexpr bn::size MOTHERSHIP_SIZE = {32, 32};

int main()
{
    bn::core::init();

    // Set time for damage sprite display
    int damage_timer = 0;
    bool damage_timer_active = false;

    // Add background
    bn::regular_bg_ptr background = bn::regular_bg_items::bg.create_bg(0, 0);

    Center center = Center({-40, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};

    Mothership mothership = Mothership({70, -30}); // Create the mothership
    bn::sprite_ptr damaged_mothership = bn::sprite_items::mothership_damage.create_sprite(300, 300);
    // Mothership damaged_mothership = Mothership({300, 300}); //Create a damaged mothership
    // Set up the hitbox for the mothership.
    bn::rect mothership_hitbox = create_mothership_hitbox(mothership, MOTHERSHIP_SIZE);

    // Create the explosion sprite
    bn::sprite_ptr boom = bn::sprite_items::explosion.create_sprite(300, 300);

    while (true)
    {
        // Add an orbiter when A is pressed if there's room
        if (bn::keypad::a_pressed())
        {
            if (orbiters.size() < MAX_ORBITERS)
            {
                orbiters.push_back(Orbiter(ORBITER_START_POSIITON, ORBITER_START_VELOCITY, center));
            }
        }

        // Remove an orbiter when B is pressed if there's at least one
        if (bn::keypad::b_pressed())
        {
            if (orbiters.size() > 0)
            {
                orbiters.pop_back();
            }
        }

        center.update();
        for (Orbiter &orbiter : orbiters)
        {
            // For every orbiter in the orbiters list, add a hitbox
            orbiter.set_hitbox(create_orbiter_hitbox(orbiter, ORBITER_SIZE));
            orbiter.update(FORCE_SCALE);
        }

        // Now that the orbiters have a hitbox...
        for (Orbiter &orbiter : orbiters)
        {
            // If that hitbox touchs the mohership's hitbox...
            if (orbiter.get_hitbox().intersects(mothership_hitbox))
            {
                // And the orbiters vector is not empty...
                if (orbiters.size() > 0)
                {
                    damage_timer_active = true;
                    // Pop the orbiter out.
                    orbiters.pop_back();
                    // Tick down the mothership health
                    mothership.set_health(mothership.get_health() - 1);
                    BN_LOG("Enemy health is", mothership.get_health());
                }
            }
        }

        // If the mothership is hit, show the damage sprite
        if (damage_timer_active)
        {
            // Show the damage sprite
            damaged_mothership.set_position(70, -30);
            damage_timer++;
            if (damage_timer == 10)
            {
                damage_timer = 0;
                damage_timer_active = false;
                damaged_mothership.set_position(300, 300);
            }
        }

        // If the mothership's hitpoints hit zero, blow it up (move it off screen)
        if (mothership.get_health() < 0)
        {
            mothership.get_sprite().set_position(300, 300);
            boom.set_position(70, -30);
            background = bn::regular_bg_items::victorybg.create_bg(0, 0);
        }

        bn::core::update();
    }
}