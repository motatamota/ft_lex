int main(void)
{
	yylex();
	return 0;
}

int yywrap(void)
{
	return 1;
}
