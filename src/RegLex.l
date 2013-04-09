%{
  #include "RegSin.cpp"
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
 // #include <Classes.hpp>

  #include <map>
  using namespace std;

  int regstringinput(char *buf, int maxsize);

  #define YY_SKIP_YYWRAP
  static inline int regwrap () { return 1 ; }

  #undef YY_INPUT
  #define YY_INPUT(b,r,m) (r = regstringinput(b,m))
  #define min(a,b) ((a<b)?(a):(b))

  extern map<QString,double> MapCoef;
%}

numero  [0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?
Variable [a-zA-Z][a-zA-Z0-9_]*

%%
"+"       { return SUMA; }
"-"       { return REST; }
"*"       { return PROD; }
{numero}  { reglval.valor = atof(yytext); return NUMBER; }
{Variable} { reglval.cadena = strdup(yytext); return VAR; }
.
%%

extern char *reginputptr;
extern char *reginputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función de entrada de texto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int regstringinput(char *buf, int maxsize)
{
  int n = min(maxsize, reginputlim-reginputptr);
  if (n > 0)
  {
    memcpy(buf, reginputptr, n);
    reginputptr += n;
  }
  return n;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
