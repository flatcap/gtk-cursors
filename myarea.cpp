#include <cairomm/context.h>
#include <gtkmm/application.h>

#include "examplewindow.h"
#include "myarea.h"

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	Gtk::Allocation allocation = get_allocation();

	int x = allocation.get_width() / 2;
	int y = allocation.get_height() / 2;

	cr->set_line_width(10.0);

	switch (focus) {
		case true: cr->set_source_rgb(0, 1, 0); break;
		default:   cr->set_source_rgb(1, 0, 0); break;
	}

	cr->arc(x, y, 40, 0, 2*M_PI);
	cr->stroke();

	return true;
}

int main(int argc, char** argv)
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	ExampleWindow win;

	return app->run(win);
}
