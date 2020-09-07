#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_MENU_FILE	"menu.lst"

void 
select_menu( 
    char ** menu, int size )
{
    int    i = 0;

    srand( time( NULL ) );
    i = rand() %  size;

    printf( "selected menu = [%s]\r\n", menu[i] );
}

void 
remove_newline( 
    char * line )
{
    int    i = 0;

    if( NULL == line )
        return;

    for( i = 0; line[i] != '\0'; i++ )
    {
        if( line[i] == '\r'  || line[i] == '\n' )
        {
            line[i] = '\0';
            return;
        }
    }
}

int 
open_menu( 
    const char * fileName, 
    char **      menuList )
{
    FILE *      file = NULL;
    int         count = 0;
    char *      buffer = NULL;
    size_t      bufferSize = 0;
    ssize_t     read = 0;

    if( NULL == fileName )
        return -1;

    if( NULL == menuList )
        return -1;

    file = fopen( fileName, "r" );
    if( NULL == file )
        return -1;

    while( ( read = getline( &buffer, &bufferSize, file ) ) != -1 )
    {
        menuList[count++] = buffer;
        remove_newline( buffer );
        buffer = NULL;
        bufferSize = 0;
    }

    return count;
}

int 
main(
    int ac, char** av)
{
    int    i = 0;
    int    menu_len = 0;
    char * menu[1024] = {NULL, };
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
