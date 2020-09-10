#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lunch.h"

int 
select_menu( 
    char ** menu, int size )
{
    int    i = 0;

    srand( time( NULL ) );
    i = rand() %  size;

    printf( "selected menu = [%s]\r\n", menu[i] );

    return i;
}

int 
remove_newline( 
    char * line )
{
    int    i = 0;

    if( NULL == line )
        return -1;

    for( i = 0; line[i] != '\0'; i++ )
    {
        if( line[i] == '\r'  || line[i] == '\n' )
        {
            line[i] = '\0';
            return 1;
        }
    }

    return 0;
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

