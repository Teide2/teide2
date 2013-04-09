%{
	#include "VariablesDeEdits.h"
	#include <stdio.h>
	#include <stdlib.h>

	#define YY_SKIP_YYWRAP
	static inline int yywrap () { return 1 ; }

	QStringList *StlListaVariables;
%}

Variable [a-zA-Z][a-zA-Z0-9_]*

%%
"<"
">"
"<="
">="
"!="|"<>"
"="
[aA][nN][dD]|[yY]|"&"
[oO][rR]|[oO]|"|"
[nN][oO][tT]|[nN][oO]|"!"
[iI][fF]|[Ss][iI]
[tT][hH][eE][nN]|[eE][nN][tT][oO][nN][cC][eE][sS]
[sS][iI][ ][yY][ ][sS][oO][lL][oO][ ][sS][iI]|[iI][fF][fF]
[xX][oO][rR]|"%"
"+"
"-"
"*"
"/"
"("
")"
{Variable}\.{Variable}	{ if (StlListaVariables->indexOf(yytext) == -1)
											StlListaVariables->append(yytext);
									}
{Variable}						{ if (StlListaVariables->indexOf(yytext) == -1)
											StlListaVariables->append(yytext);
									}
.
%%
/* ---------------------------------------------------------------------------
	Obtener los Variables de la Edit.
--------------------------------------------------------------------------- */
QStringList *GetVariablesDeEdit(QString Edit)
{
	StlListaVariables = new QStringList();
	yy_scan_string(Edit);
	yylex();
	yy_delete_buffer(YY_CURRENT_BUFFER);
	return StlListaVariables;
}
