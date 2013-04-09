%{
	#include "RanSin.cpp"
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
 // #include <Classes.hpp>

  #include <QList>
  using namespace std;

	int ranstringinput(char *buf, int maxsize);

	#define YY_SKIP_YYWRAP
	static inline int ranwrap () { return 1 ; }

  #undef YY_INPUT
	#define YY_INPUT(b,r,m) (r = ranstringinput(b,m))
	#define min(a,b) ((a<b)?(a):(b))

	//extern list<double> LValores;
  //extern bool AccesoComas;
%}

numero	[+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?

%%
","       { return COMA; }
":"       { return DOS_PUNTOS; }
".."      { return GUION; }
{numero}  { ranlval.valor = atof(yytext); return NUMBER; }
.
%%

extern char *raninputptr;
extern char *raninputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función de entrada de texto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ranstringinput(char *buf, int maxsize)
{
	int n = min(maxsize, raninputlim-raninputptr);
	if (n > 0)
	{
  	memcpy(buf, raninputptr, n);
		raninputptr += n;
	}
	return n;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

