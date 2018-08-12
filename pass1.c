#include<stdio.h>
#include<string.h>
struct estab
{
  char csname[10];
  char extsym[10];
  int address;
  int length;
}es[20];
void main()
{
	char input[10],name[10],symbol[10],ch;  int count=0,progaddr,csaddr,add,len;
	FILE *fp1,*fp2;
	fp1=fopen("INPUT.DAT","r");
	fp2=fopen("ESTAB.DAT","w");
	printf("\n\nEnter the address where the program has to be loaded : ");
	scanf("%x",&progaddr); // TAKING THE PROGRAM ADDRESS FROM THE USER,GENERALLY IT IS DONE BY THE OS
	csaddr=progaddr;
	fscanf(fp1,"%s",input);
	while(strcmp(input,"END")!=0)
	{
		if(strcmp(input,"H")==0)
		{
			fscanf(fp1,"%s",name);
			strcpy(es[count].csname,name);
			strcpy(es[count].extsym,"  ");
			fscanf(fp1,"%x",&add);
			es[count].address=add+csaddr;
			fscanf(fp1,"%x",&len);
			es[count].length=len;
			fprintf(fp2,"%s ** %x %x\n",es[count].csname,es[count].address,es[count].length);
			count++;
		}
		else if(strcmp(input,"D")==0)
		{
			fscanf(fp1,"%s",input);
			while(strcmp(input,"R")!=0)
			{
				strcpy(es[count].csname,"  ");
				strcpy(es[count].extsym,input);
				fscanf(fp1,"%x",&add);
				es[count].address=add+csaddr;
				es[count].length=0;
				fprintf(fp2,"** %s %x\n",es[count].extsym,es[count].address);
				count++;
				fscanf(fp1,"%s",input);
			}
			csaddr=csaddr+len;
		}
		else if(strcmp(input,"T")==0)
		{
			while(strcmp(input,"E")!=0)
			fscanf(fp1,"%s",input);
		}
		fscanf(fp1,"%s",input);
	}
  fclose(fp1);
  fclose(fp2);
  fp2=fopen("ESTAB.DAT","r");
  ch=fgetc(fp2);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp2);
  }
  fclose(fp2);
}