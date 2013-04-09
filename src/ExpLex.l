%{
	#include "ExpSin.hpp"
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
  #include <Classes.hpp>
  #include <map>
  using namespace std;

	int yystringinput(char *buf, int maxsize);
  double GetValorVariable(char *Variable);

	#define YY_SKIP_YYWRAP
	static inline int yywrap () { return 1 ; }

  #undef YY_INPUT
	#define YY_INPUT(b,r,m) (r = yystringinput(b,m))
	#define min(a,b) ((a<b)?(a):(b))

	extern bool ErrorLexico;
  extern map<AnsiString,double> *MappingValores;
%}

Variable [a-zA-Z][a-zA-Z0-9_]*
espacio	[ \t\n]
numero	[+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?

%%
"<"		{ return LT; }
">"		{ return GT; }
"<="|"=<"	{ return LET; }
">="|"=>"	{ return GET; }
"!="|"<>"	{ return NEQ; }
"="	{ return EQUAL; }
[aA][nN][dD]|[yY]|"&"	{ return AND; }
[oO][rR]|[oO]|"|"	{ return OR; }
[nN][oO][tT]|[nN][oO]|"!"	{ return NOT; }
[iI][fF]|[Ss][iI]	{ return IF; }
[tT][hH][eE][nN]|[eE][nN][tT][oO][nN][cC][eE][sS]	{ return THEN; }
[sS][iI][ ][yY][ ][sS][oO][lL][oO][ ][sS][iI]|[iI][fF][fF]	{ return SIYSOLOSI; }
[xX][oO][rR]|"%"	{ return XOR; }
"+"	{ return PLUS; }
"-"	{ return MINUS; }
"*"	{ return PROD; }
"/"	{ return DIV; }
"#" { return RESTO; }
"("	{ return LP; }
")"	{ return RP; }
{numero}					      { explval.valor = atof(yytext); return NUMBER; }
{Variable}\.{Variable}	{ explval.valor = GetValorVariable(yytext); return NUMBER; }
{Variable}						  { explval.valor = GetValorVariable(yytext); return NUMBER; }
{espacio}+
%%

extern char *yyinputptr;
extern char *yyinputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función de entrada de texto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int yystringinput(char *buf, int maxsize)
{
	int n = min(maxsize, yyinputlim-yyinputptr);
	if (n > 0)
	{
  	memcpy(buf, yyinputptr, n);
		yyinputptr += n;
	}
	return n;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función que retorna el valor de una variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double GetValorVariable(char *Variable)
{
  map<AnsiString,double>::iterator Puntero;

  if ((Puntero = (*MappingValores).find(Variable)) != (*MappingValores).end())
    return((*Puntero).second);
  else
  {
    ErrorLexico = true;
    return 0;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

