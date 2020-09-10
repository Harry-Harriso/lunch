#include <check.h>
#include <string.h>
#include <stdlib.h>
#include "lunch.h"

#define EXIT_SUCCESS 0

START_TEST(test_select_menu)
{
    char * menu[] = {"hello", "world", "hahaha"};
    int    result = 0;

    result = select_menu( menu, 3 );
    fail_unless( result < 3, 
        "Result exceed maximum menu count." );
}
END_TEST

START_TEST(test_remove_newline)
{
    char * has_newline = strdup( "hello \r\n" );
    char * has_no_newline = strdup( "world " );
    int    result = 0;

    result = remove_newline( has_newline );
    fail_unless( result == 1, 
        "Cannot found newline." );
    result = remove_newline( has_no_newline );
    fail_unless( result == 0, 
        "Found weird newline." );
    result = remove_newline( NULL );
    fail_unless( result == -1, 
        "This will occur segement fault." );

    free( has_newline );
    free( has_no_newline );
}
END_TEST

Suite *
lunch_suite()
{
    Suite *s = suite_create( "Lunch" );
    TCase *tc_core = tcase_create( "Core" );

    tcase_add_test( tc_core, test_remove_newline );
    tcase_add_test( tc_core, test_select_menu );
    suite_add_tcase( s, tc_core );

    return s;
}

int
main(void)
{
    int failed;
    Suite *s = lunch_suite();
    SRunner *sr = srunner_create( s );
    srunner_run_all( sr, CK_VERBOSE );
    failed = srunner_ntests_failed( sr );
    srunner_free( sr );

    return ( failed == 0 ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
