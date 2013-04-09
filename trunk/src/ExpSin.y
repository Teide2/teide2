%{
	#include "ExpAna.h"

	int yylex();
	inline void yyerror(const char *msg) { }

	bool Resultado;
	bool ErrorLexico;
	bool ErrorSintactico;
	char *ExpresionAEvaluar;
  QMap<QString,double> *MappingValores;
  QMap<QString,double> *MappingMissing;
%}
%union {
	double valor;
}

%token <valor> NUMBER
%type <valor> result
%type <valor> expression
%left LP RP
%left IF THEN 
%left SIYSOLOSI
%left PLUS MINUS
%left PROD DIV
%left RESTO
%left AND OR XOR
%left LT GT LET GET NEQ EQUAL
%left NOT

%%
result : expression { Resultado = $1; }
       | error { ErrorSintactico = true; }
       ;

expression : NUMBER { $$ = $1; }
           | LP expression RP { $$ = $2 ; }
           | expression LT expression { $$ = ($1 < $3); }
           | expression GT expression { $$ = ($1 > $3); }
           | expression LET expression { $$ = ($1 <= $3); }
           | expression GET expression { $$ = ($1 >= $3); }
           | expression NEQ expression { $$ = ($1 != $3); }
           | expression EQUAL expression { $$ = ($1 == $3); }
           | expression AND expression { $$ = ($1 && $3); }
           | expression OR expression { $$ = ($1 || $3); }
           | expression XOR expression { $$ = ((!$1 && $3) || ($1 && !$3)); }
           | NOT expression { $$ = !$2; }
           | IF expression THEN expression { $$ = (!$2 || $4); }
           | expression PLUS expression { $$ = ($1 + $3); }
           | expression MINUS expression { $$ = ($1 - $3); }
           | expression PROD expression { $$ = ($1 * $3); }
           | expression DIV expression { $$ = ($1 / $3); }
           | expression RESTO expression { $$ = ($1 - (floor($1 / $3) * $3)); }
           | expression SIYSOLOSI expression { $$ = !((!$1 && $3) || ($1 && !$3)); }
           ;
%%

char *yyinputptr;
char *yyinputlim;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar la expresión con las variables y los valores definidos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresion(char* Expresion, QMap<QString,double> *MapValores)
{
  ExpresionAEvaluar = Expresion;
  //MappingValores = &MapValores->toStdMap();
  MappingValores = MapValores;
	ErrorLexico = false;
	ErrorSintactico = false;
	yyinputptr = ExpresionAEvaluar;
	yyinputlim = ExpresionAEvaluar + strlen(ExpresionAEvaluar);
  yyparse();

	if ((ErrorSintactico == false) && (ErrorLexico == false))
		return (TResultado)Resultado;					/* Sin errores */
	if ((ErrorSintactico == true) && (ErrorLexico == false))
		return ERROR_SINTACTICO;				/* Error sintáctico */
	if ((ErrorSintactico == false) && (ErrorLexico == true))
		return ERROR_LEXICO;							/* Error léxico */
	if ((ErrorSintactico == true) && (ErrorLexico == true))
		return ERROR_SINTACTICO_Y_LEXICO;	/* Error sintáctico y léxico */

  return (TResultado)Resultado;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar la expresión con los missing y los valores definidos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresion(char* Expresion, QMap<QString,double> *MapValores, QMap <QString, double> *MapMissing)
{
  ExpresionAEvaluar = Expresion;
  //MappingValores = &MapValores->toStdMap();
  MappingValores = MapValores;
  MappingMissing = MapMissing;
	ErrorLexico = false;
	ErrorSintactico = false;
	yyinputptr = ExpresionAEvaluar;
	yyinputlim = ExpresionAEvaluar + strlen(ExpresionAEvaluar);
  yyparse();

	if ((ErrorSintactico == false) && (ErrorLexico == false))
		return (TResultado)Resultado;					/* Sin errores */
	if ((ErrorSintactico == true) && (ErrorLexico == false))
		return ERROR_SINTACTICO;				/* Error sintáctico */
	if ((ErrorSintactico == false) && (ErrorLexico == true))
		return ERROR_LEXICO;							/* Error léxico */
	if ((ErrorSintactico == true) && (ErrorLexico == true))
		return ERROR_SINTACTICO_Y_LEXICO;	/* Error sintáctico y léxico */

  return (TResultado)Resultado;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

