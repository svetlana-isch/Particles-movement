.PHONY: all clean
all:
	g++ -Wall -Wextra -Werror -o app mainwindow.cpp particle.cpp system.cpp windowt.cpp `fltk-config --ldflags` -g 
clean:
	clear
	rm -f app mainwindow.o particle.o system.o windowt.o
