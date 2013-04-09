%{
	#include "RanAna.h"

	int ranlex();
	inline void ranerror(const char *msg) { }

	bool Error;
  bool AccesoComas;
	char *RangoAEvaluar;
	QList<double> LValores;
%}
%union {
	double valor;
}

%token <valor> NUMBER
%left COMA DOS_PUNTOS GUION

%%
rango : lista_valores { AccesoComas = true; }
      | rango_valores { }
      | error { Error = true; }
      ;

lista_valores : lista_valores COMA NUMBER { LValores.push_back($3); }
              | NUMBER { LValores.push_back($1); }
              | NUMBER GUION NUMBER { int i; for (i = $1; i <= $3; i++) LValores.push_back(i); }
              ;

rango_valores : NUMBER DOS_PUNTOS NUMBER { LValores.push_back($1); LValores.push_back($3); }
              ;
%%

char *raninputptr;
char *raninputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtener los valores de rangos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultadoRangos GetValoresDeRango(char * Rango, QList<double> *ListaValores)
{
  RangoAEvaluar = Rango.c_str();
  LValores.clear();
  Error = false;
  AccesoComas = false;

	raninputptr = RangoAEvaluar;
	raninputlim = RangoAEvaluar + strlen(RangoAEvaluar);

  ranparse();

  (*ListaValores) = LValores;

  if (Error)
    return ERROR_RANGO;
  if (AccesoComas)
    return RANGO_COMAS;
  return RANGO_PUNTOS;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

