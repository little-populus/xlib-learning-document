#include <X11/Xlib.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main()
{
    auto con = XOpenDisplay(NULL);
    auto num = XDefaultScreen(con);
    auto screen = XScreenOfDisplay(con, num);
    auto root = XDefaultRootWindow(con);
    auto win =
        XCreateSimpleWindow(con, root, 100, 100, 300, 300, 100, BlackPixelOfScreen(screen), WhitePixelOfScreen(screen));
    // XFlush(con);
    XMapWindow(con, win);
    XMoveWindow(con, win, (1920 - 300) / 2, (1080 - 300) / 2);
    XFlush(con);
    sleep(2);
    XResizeWindow(con, win, 600, 600);
    XFlush(con);
    sleep(2);
    return 0;
}