#ifndef particle_h
#define particle_h

#include "windowt.hpp"
#include "system.hpp"
namespace particles{
    class Windowt;
    class System;
    class Particle{
        protected:
            double speed_x;
            double speed_y;
            double x;
            double y;
            int color;
        public:
            Particle();
            virtual void change_speed_y(double a);
            virtual void change_speed_x(double a);
            virtual double get_speed_x();
            virtual double get_speed_y();
            virtual void set_x(double a);
            virtual void set_y(double a);
            virtual void move_little(Particle *a);
            virtual bool isOverlap(Particle *a);
            virtual void make_a_step();
            virtual void impact(Particle* a);
            virtual void change_x(int a);
            virtual void change_y(int a);
            virtual double distanceTo(Particle* a);   
            virtual double get_x();
            virtual double get_y();
            virtual int get_mass() = 0;
            virtual int get_color();
            virtual int get_radius() = 0;
            virtual ~Particle() = default;
    };
    class Light_particle: public Particle
    {
            const int l_mass = 80;
            const int l_radius = 20;
        public:
            Light_particle(int seed);
            virtual int get_mass();
            virtual int get_radius();
    };
    class Heavy_particle: public Particle
    {
            int mass;
            int radius;
        public:
            Heavy_particle(int seed);
            virtual int get_mass();
            virtual int get_radius();
    };
}
#endif