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
static constexpr bn::size MOTHERSHIP_SIZE = {32, 32};

int main()
{
    bn::core::init();

    Center center = Center({30, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};
    Mothership mothership1 = Mothership({60, 60});
    // Set up the hitbox for the mothership.
    bn::rect mothership_hitbox = create_mothership_hitbox(mothership1, MOTHERSHIP_SIZE);
    // Mothership mothership2 = Mothership({0, 60});
    // Mothership mothership3 = Mothership({10, 40});

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
                    // Pop the orbiter out.
                    orbiters.pop_back();
                    BN_LOG("Orbiter destroyed");
                }
            }
        }

        bn::core::update();
    }
}