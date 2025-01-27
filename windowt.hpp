#ifndef window_h
#define window_h
#include<FL/Fl.H>
#include<FL/fl_draw.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<Fl/Fl_Int_Input.H>
#include<FL/Fl_Input.H>
#include "particle.hpp"
#include<FL/Fl_Button.H> 
#include "system.hpp"
#include "particle.hpp"
namespace particles{
    class System;
    class Particle;
    class Windowt: public Fl_Window{
            Fl_Box* box;
            System* sys;
            Fl_Int_Input* inp;
            int value;
        public:
            Windowt();
            Windowt(const Windowt& w) = delete;
            void operator=(Windowt& w) = delete;
            void set_sys(System* s);
            void draw();
            void set_value();
            void clear_input();
            int& get_value();
    };

}
#endif