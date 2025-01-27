#include<vector>
#include<random>
#include "particle.hpp"
#include "system.hpp"
#include "windowt.hpp"
#include<iostream>
using namespace particles;

System::System(int seed, int start_light, int start_heavy, Windowt* win):seed(seed), amount(start_light+start_heavy), win(win)
{
    for (int i = 0; i < start_light; ++i)
    {
        sys.push_back(new Light_particle(seed+i));
        int f = 10;
        for(int j = 0; j < i; ++j)
        {
            while(sys[i]->isOverlap(sys[j]))
            {
                sys[i]->change_x(seed+f+i);
                sys[i]->change_y(seed+f+i);
                f++;
            }
        }
    }
    for (int i = 0; i < start_heavy; ++i)
    {
        sys.push_back(new Heavy_particle(seed+i+start_light));
        int f = 10;
        for(int j = 0; j < i+start_light; ++j)
        {
            while(sys[i+start_light]->isOverlap(sys[j]))
            {   
                sys[i + start_light]->change_x(seed+f+i);
                sys[i + start_light]->change_y(seed+f+i);
                f++;
            }
        }
    }
}
void System::step()
{
    for(int i = 0; i < amount; ++i)
    {
        sys[i]->make_a_step();
    }  
    for(int i = 0; i < amount; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            while(sys[i]->isOverlap(sys[j]))
            {
                sys[i]->impact(sys[j]);
            }
        }
    }
    win->redraw();
}
void System::add_light()
{
    sys.push_back(new Light_particle(seed+amount));
    ++amount;
    int c = sys.size() - 1;
    for(int j = 0; j < c; ++j)
    {
        while(sys[sys.size() - 1]->isOverlap(sys[j]))
        {
            sys[sys.size() - 1]->change_x(seed+j);
            sys[sys.size() - 1]->change_y(seed+j);
        }
    }
}
void System::add_heavy()
{
    sys.push_back(new Heavy_particle(seed+amount));
    ++amount;
    int c = sys.size() - 1;
    for(int j = 0; j < c; ++j)
    {
        while(sys[sys.size() - 1]->isOverlap(sys[j]))
        {
            sys[sys.size() - 1]->change_x(seed+j);
            sys[sys.size() - 1]->change_y(seed+j);
        }
    }
}
void System::part_delete()
{
    delete(sys[sys.size()-1]);
    sys.pop_back();
    --amount;
}
int System::get_amount() const
{
    return amount;
}
Particle* System::get_part(int a)
{
    return sys[a];
}
int System::get_color(int a)
{
    return sys[a]->get_color();
}
int& System::get_value()
{
    return win->get_value();
}
void System::set_value()
{
    return win->set_value();
}
void System::clear_input()
{
    win->clear_input();
}
System::~System()
{
    int a = sys.size();
    for(int i = 0; i < a;++i)
    {
        delete(sys[sys.size()-1]);
        sys.pop_back();
    }
}