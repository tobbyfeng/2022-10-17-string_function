#include <stdio.h>
#include <string.h>
#include <assert.h>

void dep( char *srr, char *arr, int size )
{
	int i = 0;
	for( i=0; i<size; i++ )
	{
		if( (srr[i]<='a'||srr[i]>='z') &&  (srr[i]<='A'||srr[i]>='Z')  )
		{
			arr[i] = srr[i];
		}
	}
}

void rev( char *str )
{
	char *tmp = (str + strlen(str) - 1);
	while( str <= tmp )
	{
		char val = *str;
		*str = *tmp;
		*tmp = val;

		str++;
		tmp--;
	}
}

void tok( char *srr, char *str )
{
	char *ret = strtok(srr, str);
	rev( ret );	

	while( ret != NULL )
	{
		ret = strtok( NULL, str );
		if( ret == NULL )
		{
			break;
		}

		rev( ret );
	}
}

void func( char *srr, char *arr, int size )
{
	int i = 0;
	for( i=0; i<size; i++ )
	{
		if( arr[i] != 0 )
		{
			srr[i] = arr[i];
		}
	}
}

int main()
{
	char srr[] = "Mike Shinoda, Rob Bourdon, and Brad Delson.";
	char arr[50] = {0};

	dep( srr, arr, sizeof(srr) );
	tok( srr, ", ." );
	func( srr, arr, sizeof(srr) );
	printf( "%s \n", srr );
	return 0;
}

