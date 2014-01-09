#ifndef _EXAMPLEWINDOW_H_
#define _EXAMPLEWINDOW_H_

#include <gtkmm/drawingarea.h>
#include <gtkmm/eventbox.h>
#include <gtkmm/grid.h>
#include <gtkmm/window.h>

#include "myarea.h"

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow();
	virtual ~ExampleWindow();

protected:
	bool on_keypress(GdkEventKey* ev);

	Gtk::EventBox event;
	Gtk::Grid grid;

	MyArea a0;
	MyArea a1;
	MyArea a2;
	MyArea a3;
	MyArea a4;
	MyArea a5;
	MyArea a6;
	MyArea a7;
	MyArea a8;
};

#endif // _EXAMPLEWINDOW_H_

