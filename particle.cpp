#include<FL/Fl.H>
#include<FL/fl_draw.H>
#include<random>
#include "particle.hpp"
#include "windowt.hpp"
#include <math.h>
#include<iostream>
using namespace particles;
Particle::Particle(){}
Light_particle::Light_particle(int seed)
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> gx(get_radius(), 980);
    std::uniform_real_distribution<double> gy(get_radius(), 480);
    std::uniform_real_distribution<double> gspeed(1, 3);
    std::uniform_real_distribution<double> gvelocity(-180,180);
    x = gx(gen);
    y = gy(gen);
    int speed = gspeed(gen);
    int velocity = gvelocity(gen);
    speed_x = speed*cos(M_PI*velocity/180);
    speed_y = speed*sin(M_PI*(int)velocity/180);
    color = FL_CYAN;
}
Heavy_particle::Heavy_particle(int seed)
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> grad(20, 40);
    radius = grad(gen);
    std::uniform_real_distribution<double> gx(get_radius(), 1000 - get_radius());
    std::uniform_real_distribution<double> gy(get_radius(), 500 - get_radius());
    std::uniform_real_distribution<double> gspeed(3, 5);
    std::uniform_real_distribution<double> gvelocity(-180,180);
    std::uniform_real_distribution<double> gmass(120, 150);
    x = gx(gen);
    y = gy(gen);
    int speed = gspeed(gen);
    int velocity = gvelocity(gen);
    mass = gmass(gen);
    speed_x = speed*cos(M_PI*velocity/180);
    speed_y = speed*sin(M_PI*velocity/180);
    color = FL_DARK_MAGENTA;
}

void Particle::change_speed_x(double a)
{
    speed_x = a;
}
void Particle::change_speed_y(double a)
{
    speed_y = a;
}
double Particle::get_x()
{
    return x;
}
double Particle::get_y()
{
    return y;
}
double Particle::distanceTo(Particle* a)
{
    return sqrt((x-a->get_x())*(x - a->get_x()) +(y - a->get_y())*(y - a->get_y()));
}
bool Particle::isOverlap(Particle *a)
{
    if (distanceTo(a) < get_radius()+a->get_radius()) {
            return true;
        }
    return false;
}
void Particle::make_a_step()
{
    set_x(x+speed_x);
    set_y(y + speed_y);
}
void Particle::change_x(int seed)
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> gx(get_radius(), 1000 - get_radius());
    x = gx(gen);
}
void Particle::change_y(int seed)
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> gy(get_radius(), 500 - get_radius());
    y = gy(gen);
}
double Particle::get_speed_x()
{
    return speed_x;
}
double Particle::get_speed_y()
{
    return speed_y;
}
void Particle::set_x(double a)
{
    x = a;
    if((x>= 1000 - get_radius())||(x<=get_radius()))
    {
        if (x>=1000-get_radius()) x = 1000 - get_radius();
        else x = get_radius();
        speed_x = -speed_x;
    }
}
void Particle::set_y(double a)
{
    y = a;
    if((y>=500 - get_radius())||(y<=get_radius()))
    {
        if (y>=500 - get_radius()) y = 500 - get_radius();
        else y = get_radius();
        speed_y = - speed_y;
    }
}
void Particle::move_little(Particle* a)
{
    set_x(x+speed_x*(0.0001));
    set_y(y+speed_y*(0.0001));
    a->set_x(a->get_x() + a->get_speed_x()*(0.0001));
    a->set_y(a->get_y() + a->get_speed_y()*(0.0001));
}
void Particle::impact(Particle* a)
{
    double speed_x2 = a->get_speed_x();
    double speed_y2 = a->get_speed_y();
    double dy, dx;
    while(distanceTo(a) > get_radius() + a->get_radius())
    {
        move_little(a);
    }
    if(distanceTo(a)!=0){
        dy = (a->get_y() - y)/distanceTo(a);
        dx = (a->get_x() - x)/distanceTo(a);
    }
    else{
        dy = (a->get_y() - y)/0.01;
        dx = (a->get_x() - x)/0.01;
    }
    double da1 = speed_x*dx + speed_y * dy;   
    double da2 = speed_x2*dx + speed_y2 * dy;
    double new_da1 = ((get_mass() - a->get_mass())*da1 + 2*(a->get_mass())*da2)/(get_mass() + a->get_mass());
    double new_da2 = ((a->get_mass() - get_mass())*da2 + 2*get_mass()*da1)/(get_mass() + a->get_mass());
    speed_x = speed_x + (new_da1 - da1)*dx;
    speed_y = speed_y + (new_da1 - da1) * dy; 
    a->change_speed_x(speed_x2 + (new_da2 - da2)*dx);
    a->change_speed_y(speed_y2 + (new_da2 - da2)*dy);
    while(distanceTo(a) < get_radius() + a->get_radius())
    {
        move_little(a);
    }
}
int Particle::get_color()
{
    return color;
}
int Light_particle::get_radius()
{
    return l_radius;
}
int Light_particle::get_mass()
{
    return l_mass;
}
int Heavy_particle::get_radius()
{
    return radius;
}
int Heavy_particle::get_mass()
{
    return mass;
}


