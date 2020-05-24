int daohuan(int n)
{
	int o=n,s=0;
	while(o!=0)
	{
		s=s*10+o%10;
		o/=10;
	}	
	return s;
}//CHM-13-DH-º¯ÊýÄ£°å
