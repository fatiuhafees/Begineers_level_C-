// since strupr and strlwr dont work we have to get creative
#include <stdio.h>

void ToUp ( char* );
void main()
{
char string[] = { "This is my STRING" };
printf( "%s\n", string );
ToUp( string );
printf( "%s\n", string );

}

void ToUp ( char *p )
{
while( *p )
{
*p=toupper( *p );
p++;
}
}