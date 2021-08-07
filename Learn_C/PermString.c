#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s){
    int i,j=0; 
	int k=-1, l=0;
	char *tmp,*var1,*var2;
	int x,y;

	for(i = 0;i<n-1; i++){
		if (strcmp(s[i],s[i+1])<0 && k<i){
			k = i;	
		}
	}
	if (k==-1)
	{
		return 0;
	}

	for(i = 0;i<n; i++){
		if (strcmp(s[k],s[i])<0 && l<i)
			l = i;		
	}
	/*
	*Swap
	*/
	tmp=s[k];
	s[k]=s[l];
	s[l]=tmp;

	/*
	*reverse Swap
	*/
	y=n-1;
	while(k+1<y)
    {
     	tmp=s[k+1];
		s[k+1]=s[y];
		s[y]=tmp;
        k++;
        y--;
    }



	return 1;
}

int main(){
	char **s;
	int n;
	int ret;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	//ret = strcmp(s[0],s[1]);
	//printf("%d\n",ret);
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}