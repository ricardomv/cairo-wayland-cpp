#include "wlplus"
#include "Rectangle.hpp"
#include <FTGL/ftgl.h>

using namespace wayland;

class Egl;
class EglWindow;
class Global;
class Input;

class Window : public Rectangle
{
public:
	bool running;
	bool fullscreen;
	Window(int width, int height);
	~Window();
	void Fullscreen(bool value);
	void Resize(int w, int h);
	void run();
private:
	Display *display;
	Global *global;
	Input *input;
	Surface *surface;
	ShellSurface *shellsurface;
	Egl *egl;
	EglWindow *eglwindow;
	FTGLTextureFont *font;
	static void HandlePing(void *data, struct wl_shell_surface *shell_surface, uint32_t serial);
	static void HandleConfigure(void *data, struct wl_shell_surface *shell_surface, uint32_t edges, int32_t width, int32_t height);
	static void HandlePopupDone(void *data, struct wl_shell_surface *shell_surface);
};
