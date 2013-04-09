/*******************************************************************************
** TareasComunes.cpp: tareas comunes.
**
** author: M-S Hernández-García
*******************************************************************************/


#include "TareasComunes.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la media del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double CalcularMedia(double *v, unsigned n)
{
	unsigned i;
	double r = 0;

	for (i = 0; i < n; i++)
		r += v[i];
	r /= (double)n;
	return r;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la mediana del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double CalcularMediana(double *v, unsigned n)
{
	double r;

	// primero hay que ordenar el vector de entrada
	qsort((void *)v, n, sizeof(double), ordfun);
	// mediana si n es par
	if ((n % 2) == 0)
	{
		r = (double)(v[n/2] + v[(n/2)+1]) / (double)2;
	}
	// mediana si n es impar
	else
	{
		r = v[(n+1)/2];
	}
	return r;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la media recortada del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double CalcularMediaR(double *v, unsigned n, unsigned rec)
{
	unsigned i, lb, ub;
	double r = 0;

	// primero hay que ordenar el vector de entrada
	qsort((void *)v, n, sizeof(double), ordfun);
	// eliminamos los extremos en el cálculo
	if (n > (2 * rec))
	{
		lb = rec;
		ub = n - rec;
		n -= (2 * rec);
	}
	else
	{
		lb = 0;
		ub = n;
  }
	for (i = lb; i < ub; i++)
		r += v[i];
	r /= (double)n;
	return r;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la moda del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double CalcularModa(double *v, unsigned n)
{
	unsigned i, frec;
	int max_frec;
	double valor;

	// primero hay que ordenar el vector de entrada
	qsort((void *)v, n, sizeof(double), ordfun);

	i = 0;
	max_frec = -1;
	valor = 0;
	while (i < n)
	{
		frec = 1;
		while ((i < (n - 1)) && (v[i] == v[i + 1]))
		{
			frec++;
			i++;
		}
		if ((int)frec > max_frec)
		{
			valor = v[i];
			max_frec = frec;
		}
		i++;
	}
	return valor;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función de ordenación de menor a mayor tamaño para vectores
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ordfun(const void *A, const void *B)
{
	double *RegA, *RegB;

	RegA = (double *)A;
	RegB = (double *)B;
	if ((*RegA) < (*RegB))
		return -1;
	if ((*RegA) == (*RegB))
		return 0;
	if ((*RegA) > (*RegB))
		return 1;
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función de ordenación de los registros donantes.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int OrdenacionMatrizRegistrosDonantes(const void *A, const void *B)
    {
      TipoRegistroDonante *RegA, *RegB;

      RegA = (TipoRegistroDonante *)A;
      RegB = (TipoRegistroDonante *)B;
      if ((*RegA).Distancia < (*RegB).Distancia)
        return -1;
      if ((*RegA).Distancia == (*RegB).Distancia)
        return 0;
      if ((*RegA).Distancia > (*RegB).Distancia)
        return 1;
      return 0;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Función de ordenación de las variables a traves de su peso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int OrdenacionPesosVariablesDescendente(const void *A, const void *B)
    {
      TipoPesoVariable *VarA, *VarB;

      VarA = (TipoPesoVariable *)A;
      VarB = (TipoPesoVariable *)B;
      //if ((*VarA).Peso > (*VarB).Peso)
      //  return -1;
      //if ((*VarA).Peso == (*VarB).Peso)
      //  return 0;
      if ((*VarA).Peso < (*VarB).Peso)
        return 1;
      return 0;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

