
int t=0;
int mini(int k,int i)//a?&#710;&#160;&#733;o?÷÷?÷?&#174;?¨?&#8250;?è&#8482;&#171;&#219;k?&#219;&#8260;i
{
	if(k==1)t=t+1;
	for(;i<=k;i++)
	{
		if(k%i==0)mini(k/i,i);
	}
	return 0;
}
	
int main()
{
	int N,n;
	scanf("%d",&N);
	for(n=0;n<=N-1;n++)
	{
		int M;
		scanf("%d",&M);
		mini(M,2);
		printf("%d\n",t);
		t=0;
	}
}
