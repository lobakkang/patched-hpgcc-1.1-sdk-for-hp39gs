
int strrev(char *buffer, int size)
{
	int i;
	char temp;
	for(i=0;i<(size/2);i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[size-i];
		buffer[size-i] = temp;
	}
	return(0);
}
