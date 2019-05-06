
#include <stdio.h>
#if defined(__linux__)
#define MYOS 1
#elif defined(_WIN32)
#define MYOS 2
#elif defined(_WIN64)
#define MYOS 3
#elif defined(__unix__)
#define MYOS 4
#define PATH_MAX 2500
#else
#define MYOS 0
#endif

#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>



#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

int main()
{
    long t;
    struct tm *ltime;
    int ch ; int rows, cols;  int gameover = 0;

    initscr();	
    curs_set( 0 );
    noecho();            
    keypad( stdscr, TRUE );  
    start_color();
    init_pair(0,  COLOR_WHITE,     COLOR_BLACK);
    init_pair(1,  COLOR_RED,     COLOR_BLACK);
    init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
    color_set( 0, NULL );

    while ( gameover == 0 ) 
    {
      time(&t);
      ltime=localtime(&t);
      /////////////////////
      getmaxyx( stdscr, rows, cols );
      erase();
      /////////////////////
      mvprintw( rows/2-1, cols/2 -4 , "[NCLOCK]" );
      mvprintw( rows/2 , cols/2 -9 , "[Date %04d/%02d/%02d]\n", 1900 + ltime->tm_year, ltime->tm_mon +1 , ltime->tm_mday );
      mvprintw( rows/2+1, cols/2 -9, "[TIME :%02d:%02d:%02d:]\n", ltime->tm_hour, ltime->tm_min, ltime->tm_sec);
      /////////////////////
      refresh();
      nodelay( stdscr, TRUE);
      /////////////////////
      ch = getch();
      if ( ch == 'q' )  
      {  
          gameover = 1;
      }
      else
         usleep( 2 * 10 * 1e5 );
      /////////////////////
    }
    endwin();
    printf("Bye\n");
}

