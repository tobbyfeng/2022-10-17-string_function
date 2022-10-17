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

int tok( char *srr, char *str, char **prr )
{
	char *ret = strtok(srr, str);
	
	int i = 0;
	prr[i] = ret;
	i++;

	while( ret != NULL )
	{
		ret = strtok( NULL, str );
		prr[i] = ret;
		i++;
		//printf( "%s \n", ret );
	}
	return i;
}

void rev( char **psrr, int num )
{
	int i = 0;
	for( i=0; i<=num; i++ )
	{
		//printf( "%s \n", psrr[i] );
		char *string = psrr[i];
		if( string == NULL )
		{
			break;
		}
		
		//printf( "%s \n", string );
		int len = strlen( string );

		int j = 0;
		for( j=0; j<len/2; j++ )
		{
			char idx = *(string+j);
			*(string+j) = *(string+len-1-j);
			*(string+len-1-j) = idx;
		}
		printf( "%s \n", psrr[i] );
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
	char *psrr[50] = {0};

	dep( srr, arr, sizeof(srr) );
	int num = tok( srr, ", .", psrr );
	rev( psrr, num );
	printf( "%s \n", arr );
	func( srr, arr, sizeof(srr) );
	printf( "%s \n", srr );
	return 0;
}

