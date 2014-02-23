#include <iostream>

#include "examplewindow.h"

ExampleWindow::ExampleWindow()
{
	add(event);
	event.add(grid);

	a0.set_size_request (100,100); a0.set_can_focus(true); grid.attach(a0, 0, 0, 1, 1);
	a1.set_size_request (100,100); a1.set_can_focus(true); grid.attach(a1, 1, 0, 1, 1);
	a2.set_size_request (100,100); a2.set_can_focus(true); grid.attach(a2, 2, 0, 1, 1);
	a3.set_size_request (100,100); a3.set_can_focus(true); grid.attach(a3, 0, 1, 1, 1);
	a4.set_size_request (100,100); a4.set_can_focus(true); grid.attach(a4, 1, 1, 1, 1);
	a5.set_size_request (100,100); a5.set_can_focus(true); grid.attach(a5, 2, 1, 1, 1);
	a6.set_size_request (100,100); a6.set_can_focus(true); grid.attach(a6, 0, 2, 1, 1);
	a7.set_size_request (100,100); a7.set_can_focus(true); grid.attach(a7, 1, 2, 1, 1);
	a8.set_size_request (100,100); a8.set_can_focus(true); grid.attach(a8, 2, 2, 1, 1);
	a4.focus = true;

	event.set_events(Gdk::KEY_PRESS_MASK);
	event.signal_key_press_event().connect (sigc::mem_fun(*this, &ExampleWindow::on_keypress), false);

	show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

bool ExampleWindow::on_keypress(GdkEventKey* ev)
{
	std::cout << "Key: " << ev->keyval << std::endl;

	// a0 a1 a2
	// a3 a4 a5
	// a6 a7 a8
	switch (ev->keyval) {
		case GDK_KEY_Left:
			if (a1.focus) { a1.focus = false; a0.focus = true; break; }
			if (a2.focus) { a2.focus = false; a1.focus = true; break; }
			if (a4.focus) { a4.focus = false; a3.focus = true; break; }
			if (a5.focus) { a5.focus = false; a4.focus = true; break; }
			if (a7.focus) { a7.focus = false; a6.focus = true; break; }
			if (a8.focus) { a8.focus = false; a7.focus = true; break; }
			break;
		case GDK_KEY_Up:
			if (a3.focus) { a3.focus = false; a0.focus = true; break; }
			if (a4.focus) { a4.focus = false; a1.focus = true; break; }
			if (a5.focus) { a5.focus = false; a2.focus = true; break; }
			if (a6.focus) { a6.focus = false; a3.focus = true; break; }
			if (a7.focus) { a7.focus = false; a4.focus = true; break; }
			if (a8.focus) { a8.focus = false; a5.focus = true; break; }
			break;
		case GDK_KEY_Right:
			if (a0.focus) { a0.focus = false; a1.focus = true; break; }
			if (a1.focus) { a1.focus = false; a2.focus = true; break; }
			if (a3.focus) { a3.focus = false; a4.focus = true; break; }
			if (a4.focus) { a4.focus = false; a5.focus = true; break; }
			if (a6.focus) { a6.focus = false; a7.focus = true; break; }
			if (a7.focus) { a7.focus = false; a8.focus = true; break; }
			break;
		case GDK_KEY_Down:
			if (a0.focus) { a0.focus = false; a3.focus = true; break; }
			if (a1.focus) { a1.focus = false; a4.focus = true; break; }
			if (a2.focus) { a2.focus = false; a5.focus = true; break; }
			if (a3.focus) { a3.focus = false; a6.focus = true; break; }
			if (a4.focus) { a4.focus = false; a7.focus = true; break; }
			if (a5.focus) { a5.focus = false; a8.focus = true; break; }
			break;
	}

	get_window()->invalidate (false);

	return true;
}

