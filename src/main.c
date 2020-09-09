#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "lunch.h"

int 
main(
    int ac, char** av)
{
    int    menu_len = 0;
    char * menu[MAX_MENU] = {NULL, };
    char   menu_file[PATH_MAX] = {0, };

    if( ac > 1 )
        strcpy( menu_file, av[1] );
    else
        strcpy( menu_file, DEFAULT_MENU_FILE );

    printf( "menu file = [%s]\r\n", menu_file);
    menu_len = open_menu( menu_file, menu );
    printf( "menu length = [%d]\r\n", menu_len );
    select_menu( menu, menu_len );

    return 0;
}
