int zhishu(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}//CHM-12-ZSPD-º¯ÊýÄ£°å 
