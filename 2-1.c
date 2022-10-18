#include <stdio.h>
#include <string.h>
#include <assert.h>

int tok( char *parr, char *str, char **pstr )
{
	char *ret = strtok( parr, str );
	int i = 0;
	pstr[i] = ret;
	i++;

	while( ret != NULL )
	{
		ret = strtok( NULL, str );
		if( ret == NULL )
		{
			break;
		}
		pstr[i] = ret;
		i++;
	}

	return i;
}

void depMax( int max, char **parr, char **pmax, int size )
{
	int i = 0;
	for( i=0; i<size; i++ )
	{
		int len = strlen(parr[i]);
		if( max == len )
		{
			*pmax = parr[i];
			*pmax++;
		}
	}
}

void depMin( int min, char **parr, char **pmin, int size )
{
	int i = 0;
	for( i=0; i<size; i++ )
	{
		int len = strlen(parr[i]);
		if( min == len )
		{
			*pmin = parr[i];
			*pmin++;
		}
	}
}

void len( char **parr, char **pmax, char **pmin, int size )
{
	int i = 0;
	int max = 0;
	int min = strlen(parr[0]);
	for( i=0; i<size; i++ )
	{
		int len = strlen(parr[i]);

		if( len >= max )
		{
			max = len;
		}
		if( len <= min )
		{
			min = len;
		}
	}
	depMax( max, parr, pmax, size );
	depMin( min, parr, pmin, size );
}

void show( char **prr, int size )
{
	int i = 0;
	for( i=0; i<size; i++ )
	{
		if( prr[i] != NULL )
		{
			printf( "%s \n", prr[i] );
		}
	}
}

int main()
{
	char arr[] = "Happy families, a prosperous nation and a harmonious world";
	char *pstr[20] = {0};
	char *maxArr[10] = {0};
	char *minArr[10] = {0};

	//	tok		len/min/max		show
	int num = tok( arr, " ,.", pstr );
	len( pstr, maxArr, minArr, num );

	show( maxArr, sizeof(maxArr)/sizeof(char *) );
	show( minArr, sizeof(minArr)/sizeof(char *) );
	return 0;
}

