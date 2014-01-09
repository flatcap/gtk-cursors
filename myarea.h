#ifndef _MYAREA_H_
#define _MYAREA_H_

class MyArea : public Gtk::DrawingArea
{
public:
	MyArea (void) {}
	bool focus = false;
protected:
	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};

#endif // _MYAREA_H_

