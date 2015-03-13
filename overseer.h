#ifndef OVERSEER_H
#define OVERSEER_H

#include <bitset>


/*
 * @class Overseer
 * @brief The overseer class keeps track of variables used by multiple other objects
 *
 *
class Overseer
{
public:
    Overseer();
    //Overseer(int initial_enemies, int initial_hostages);

    //getters
    int badguys_remaining()       { return badg_remaining;    }
    size_t badguys_onscreen()     { return badg_zones.count();}
    int max_badguys_onscreen()    { return max_badg_onscreen; }
    bool badguy_zones(int n)      { return badg_zones[n];     }

    int hostages_remaining()      { return host_remaining;    }
    size_t hostages_onscreen()    { return host_zones.count();}
    int max_hostages_onscreen()   { return max_host_onscreen; }
    bool hostage_zones(int n)     { return host_zones[n];     }

    //setters
    void badguy_killed()                       { badg_remaining--;  }
    void set_badguys_zones (size_t p, bool b)  { badg_zones[p] = b; }

    void hostage_rescued()                     { host_remaining--;  }
    void hostage_kiled()                    {}
    void set_hostages_zones (size_t p, bool b) { host_zones[p] = b; }









    ~Overseer();


private:

    int initial_badg;
    int initial_host;

    int host_remaining;
    int badg_remaining;

    //int badg_onscreen;
    //int host_onscreen;

    int max_badg_onscreen;
    int max_host_onscreen;


    std::bitset<16> badg_zones;
    std::bitset<16> host_zones;



};
*/
#endif // OVERSEER_H
