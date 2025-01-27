#include<FL/Fl.H>
#include<FL/fl_draw.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Input.H>
#include<FL/Fl_Button.H> 
#include<string>
#include<iostream>
#include"particle.hpp"
#include"system.hpp"
#include"windowt.hpp"

int main(int argc, char* argv[])
{
    if(argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <seed> <num_l_particles> <num_h_particles>\n";
        return 1;
    }
    int seed = std::stoi(argv[1]), num_l_particles = std::stoi(argv[2]), num_h_particles = std::stoi(argv[3]);
    particles::Windowt *win = new particles::Windowt();
    particles::System sys(seed, num_l_particles, num_h_particles, win);
    win->set_sys(&sys);
    win->show();
    return Fl::run();
}