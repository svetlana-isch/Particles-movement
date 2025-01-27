#ifndef system_h
#define system_h
#include<vector>
#include "particle.hpp"
#include "windowt.hpp"
namespace particles
{
    class Particle;
    class Windowt;
    class System
    {       
            int seed;
            int amount;
            Windowt* win;
            std::vector<Particle*> sys;
        public:
            System(int seed, int start_light, int start_heavy, Windowt* win);
            System(System &S) = delete;
            void add_light();
            void add_heavy();
            void part_delete();
            void step();
            void operator=(System &S) = delete;
            int& get_value();
            void set_value();
            void clear_input();
            Particle* get_part(int a);
            int get_color(int a);
            int get_amount() const;
            ~System();
    };
}
#endif