#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

int
main (void)
{
    struct winsize w;
    ioctl (STDOUT_FILENO,TIOCGWINSZ,&w);
    int x = 0, y = 0;
    int mx, my;

    WINDOW *ablak;
    ablak = initscr ();
    noecho ();
    cbreak ();
    nodelay (ablak, true);
    
    for (;;)
    {
        ioctl (STDOUT_FILENO,TIOCGWINSZ,&w);
        mx = (w.ws_col-1) * 2;
        my = (w.ws_row-1) * 2;
        
        x = (x+1) % mx;
        y = (y+1) % my;

        clear ();

        for(int i=0;i<w.ws_col;i++) mvprintw(0,i,"-");
        for(int i=0;i<w.ws_col;i++) mvprintw(w.ws_row-1,i,"-");
        mvprintw( abs(w.ws_row - 1 - y), abs(w.ws_col - 1 - x), "X");

        refresh ();
        usleep (100000);
    }

    return 0;
}
