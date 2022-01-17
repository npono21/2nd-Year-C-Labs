/*
Lab 1
	Student: Nicholai Ponomarev
	Student #: 101182048
*/

#include <stdio.h>
#include <stdlib.h>

/* main: generate some simple output. */

int main(void)
{
	printf("Hello, world!\n");
	printf("C programming is fun!\n");
	return EXIT_SUCCESS;
}

/* Answers to Exercise 2 Questions:
	a) error #2001: Syntax error: expected '}' but found 'end of input'.

	b) warning #2099: Missing type specifier; assuming 'int'.

	c) POLINK: error: Unresolved external symbol 'main' - referenced from 'crt64.lib(_crt0.obj)'.
	   POLINK: fatal error: 1 unresolved external(s).

	d) warning #1066: Found '/*' inside comment.
	   Building hello.exe.
	   POLINK: error: Unresolved external symbol 'main' - referenced from 'crt64.lib(_crt0.obj)'.
       POLINK: fatal error: 1 unresolved external(s).


	e) warning #2018: Undeclared function 'pintf' (did you mean: printf?); assuming 'extern' returning 'int'.
	   Building hello.exe.
       POLINK: error: Unresolved external symbol 'pintf' - referenced from 'C:\Users\nickp\OneDrive\Documents\University\Second Year\Fall Semester\SYSC 2006-A Foundations of Imperative Programming\Labs\Lab 1\hello\output\main.obj'.
       POLINK: fatal error: 1 unresolved external(s).


	f) error #2001: Syntax error: expected ';' but found ')'.

	g) error #2061: Invalid statement termination.

	h) error #2001: Syntax error: expected ';' but found '}'
*/
