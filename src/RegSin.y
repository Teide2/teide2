%{
  #include "RegAna.h"

  int reglex();
  inline void regerror(const char *msg) { }

  bool RegError;
  char *EcuacionAEvaluar;
  QMap<QString,double> MapCoef;
%}
%union {
  double valor;
  char* cadena;
}

%token <valor> NUMBER
%token <cadena> VAR
%left SUMA REST PROD

%%
ecuacion : lista_general { }
         | error { RegError = true; }
         ;

lista_general: coef_ind { }
             | coef_ind lista_elementos { }
             ;

lista_elementos: lista_elementos elemento { }
               | elemento { }
               ;

elemento: SUMA NUMBER PROD VAR  { MapCoef.insert(map<QString,double>::value_type($4, $2)); }
        | REST NUMBER PROD VAR  { MapCoef.insert(map<QString,double>::value_type($4, -$2)); }
        ;

coef_ind: NUMBER   { MapCoef.insert(map<QString,double>::value_type("B0", $1)); }
        ;
%%

char *reginputptr;
char *reginputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtener los valores de la ecuación de regresión.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GetValoresDeRegresion(char* EcRegresion, map<QString,double> *MappingCoef)
{
  EcuacionAEvaluar = EcRegresion; //.c_str();
  MapCoef.clear();
  RegError = false;

  reginputptr = EcuacionAEvaluar;
  reginputlim = EcuacionAEvaluar + strlen(EcuacionAEvaluar);

  regparse();

  (*MappingCoef) = MapCoef;

  if (RegError)
    return false;
  else
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
