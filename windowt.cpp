#include"windowt.hpp"
#include<FL/Fl_Window.H>
#include<FL/fl_draw.H>
#include <FL/Fl_Int_Input.H>
#include<FL/Fl_Box.H>
#include<iostream>
#include<FL/Fl.H>
#include<FL/fl_draw.H>
using namespace particles;


void callback_timeout(void* sys)
{
    ((System*)sys)->step();
    --(((System*)sys)->get_value());
    if((((System*)sys)->get_value())>0)
    {    
        Fl::repeat_timeout(0.1, callback_timeout, sys);
    }
    else{
        ((System*)sys)->clear_input();
    }
}
void add_light(Fl_Widget*, void* s)
{
    ((System*)s)->add_light();
}
void add_heavy(Fl_Widget*, void* s)
{
    ((System*)s)->add_heavy();
}
void add_callback(Fl_Widget*, void* s)
{
    Fl_Window *adder = new Fl_Window(300, 300, "choose the type of the particle");
    Fl_Button *light = new Fl_Button(50, 50, 200, 75, "light particle");
    light->labelsize(20);
    light->callback(add_light, s);
    Fl_Button *heavy = new Fl_Button(50, 150, 200, 75, "heavy particle");
    heavy->labelsize(20);
    heavy->callback(add_heavy, s);
    adder->show();
    Fl::run();
}
void delete_callback(Fl_Widget*, void* s)
{
    ((System*)s) -> part_delete();
}
Windowt::Windowt():Fl_Window(1000, 600, "particles") 
{
    color(FL_WHITE);
}
void step_callback(Fl_Widget*, void* s)
{
    ((System*)s)->set_value();
    Fl::add_timeout(0.05, ::callback_timeout, s); 
}
void Windowt::set_sys(System* s)
{
    sys = s;
    Fl_Button *button_add = new Fl_Button(50,510,200,75, "add particle");
    button_add->callback(add_callback, sys);
    button_add->labelsize(20);
    Fl_Button *button_delete = new Fl_Button(275,510,200,75, "delete particle");
    button_delete->callback(delete_callback, (void*)sys);
    button_delete->labelsize(20);
    Fl_Int_Input *input = new Fl_Int_Input(725, 510, 200, 75, "");
    inp = input;
    Fl_Button *button_step = new Fl_Button(500,510,200,75, "make a step");
    button_step->callback(step_callback, (void*)sys);
    button_step->labelsize(20);
}
void Windowt::draw() 
{
    int amount = sys->get_amount();
    Fl_Window::draw();
    for(int i = 0; i < amount;++i)
    {   fl_color(sys->get_color(i));
        fl_begin_polygon();
        fl_circle(sys->get_part(i)->get_x(), sys->get_part(i)->get_y(), sys->get_part(i)->get_radius());
        fl_end_polygon();
    }
}
void Windowt::set_value() 
{
    const char* input_text = inp->value();
    if (input_text == nullptr || input_text[0] == '\0' ) {
        value = 1;
    }
    else
        value = std::stoi(input_text);
}
int& Windowt::get_value() 
{
    return value;
}
void Windowt::clear_input()
{
    inp->value("");
}