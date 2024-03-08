#include <X11/Xlib.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
// remaining incomplete
int main()
{
    auto connection = XOpenDisplay(NULL);
    auto num = XDefaultScreen(connection);
    auto screen = XScreenOfDisplay(connection, num);
    std::cout << "version is: " << XProtocolVersion(connection) << '\n'
              << "revision is: " << XProtocolRevision(connection) << '\n';
    std::cout << "display name is: " << XDisplayString(connection) << '\n';
    std::cout << "vendor release is: " << XVendorRelease(connection) << '\n';
    std::cout << "available screen count is: " << XScreenCount(connection) << '\n';
    std::cout << "screen number is: " << num << '\n';
    std::cout << "colormap of default screen is: " << XDefaultColormap(connection, num) << '\n';
    std::cout << "colormap of screen is: " << XDefaultColormapOfScreen(screen) << '\n';
    std::cout << "default depth of screen is: " << XDefaultDepth(connection, num) << '\n';
    std::cout << "default depth of screen is: " << XDefaultDepthOfScreen(screen) << '\n';
    std::cout << "backing store mode is: ";
    switch (XDoesBackingStore(screen))
    {
    case WhenMapped:
        std::cout << "WhenMapped";
        break;
    case Always:
        std::cout << "Always";
        break;
    case NotUseful:
        std::cout << "NotUseful";
        break;
    }
    std::cout << '\n';
    if (XDoesSaveUnders(screen))
        std::cout << "support save unders\n";
    else
        std::cout << "don't support save unders\n";
    std::cout << "display of screen is: " << XDisplayOfScreen(screen) << '\n';
    std::cout << "event mask of screen is: " << XEventMaskOfScreen(screen) << '\n';
    std::cout << "default root window is: " << XDefaultRootWindow(connection) << '\n';
    std::cout << "window of screen is: " << XRootWindowOfScreen(screen) << '\n';
    XNoOp(connection);
    auto gc = XDefaultGC(connection, num);
    // annotation because of system clear automatically
    // XFree(gc);
    sleep(2);
    XCloseDisplay(connection);
    return 0;
}