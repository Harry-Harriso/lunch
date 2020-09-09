#ifndef __LUNCH_H__
#define __LUNCH_H__

#define MAX_MENU          1000
#define DEFAULT_MENU_FILE "menu.lst"

int 
select_menu( 
    char ** menu, int size );

int 
remove_newline( 
    char * line );

int
open_menu(
    const char * fileName, 
    char **      menuList );

#endif /* __LUNCH_H__ */
