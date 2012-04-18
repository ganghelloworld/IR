int reverse(int a)
{
	int tag = 1;
	if(a == 0) return 0;
	if(a < 0)
	{
		tag = -1;
		a *= -1;
	}
	int b = 0;
	do{
		b *= 10;
		b += a % 10;
		a /= 10;
	}while(a != 0);
	b *= tag;
	return b;
}
