AC_PREREQ([2.69])
AC_INIT([lunch], [1.0], [Harry-Harriso@github.com])


AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC
AM_PROG_CC_C_O

AM_PROG_AR
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AC_HEADER_STDC

AC_FUNC_MALLOC

PKG_CHECK_MODULES([CHECK], [check >= 0.9.4])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	tests/Makefile])

AC_OUTPUT
