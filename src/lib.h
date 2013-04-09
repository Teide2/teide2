#ifndef BISON_LIB_H
# define BISON_LIB_H

#ifndef YYSTYPE
typedef union {
	double valor;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
# define	NUMBER	257
# define	LP	258
# define	RP	259
# define	IF	260
# define	THEN	261
# define	SIYSOLOSI	262
# define	AND	263
# define	OR	264
# define	XOR	265
# define	LT	266
# define	GT	267
# define	LET	268
# define	GET	269
# define	NEQ	270
# define	EQUAL	271
# define	PLUS	272
# define	MINUS	273
# define	PROD	274
# define	DIV	275
# define	RESTO	276
# define	NOT	277
#include <qstring.h>
extern YYSTYPE explval;

extern YYSTYPE ranlval;
#define	COMA	258
#define	DOS_PUNTOS	259
#define	GUION	260 

#endif /* not BISON_LIB_H */
