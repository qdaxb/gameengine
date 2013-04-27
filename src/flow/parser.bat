

rem *** Run Bison to generate the parser
bison --defines --verbose -o yacc.cpp yacc.y
flex -olex.cpp lex.l
@pause


rem if exist yacc.h del lexsymb.h
rem ren parse.cpp.h lexsymb.h

:End
