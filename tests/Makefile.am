TESTS = check_lunch
check_PROGRAMS = check_lunch
check_lunch_SOURCES = check_lunch.c $(top_builddir)/src/lunch.h
check_lunch_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
check_lunch_LDADD = $(top_builddir)/src/liblunch.a @CHECK_LIBS@
