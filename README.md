# lazy_program_parser
A lazy way to insert conditional compilation in C/C++ code

this is an utility i used wile studying for an OS exam. This program saves you the burden of adding #ifdef *symbolic_constant* and #endif every time you need to add some debug code, 
or anything that will be compiled conditionally. The utility is pretty straightforwar, it uses the sytax

@ "string to printf %d\n" argument

and translates in t

#ifndef CONSTANT_SPECIFIED_ON_COMMAND_LINE

  printf("string to printf %d\n", argument);

#endif

by using the command

lpp SYM_CONSTANT filename.c
