#include <stdio.h>
#include <string.h>

#pragma warning (disable:4996)

void writeToFileHtml();
void htmlFilePictures();
void htmlWithDiv();
void htmlWithSomeDivs();
void generateHtmlFromPattern();
int main()
{
	//writeToFileHtml();
	//htmlFilePictures();
	//htmlWithDiv();
	//htmlWithSomeDivs();
	generateHtmlFromPattern();
}

void writeToFileHtml()
{
	char str[100];
	FILE* f = fopen("web.html", "w");
	if (!f)
	{
		exit(1);
	}
	strcpy(str,"<html><head></head><body><img src=\"cat.jpg\" /><body/></html>");
	fputs(str, f);
	fclose(f);
}

void htmlFilePictures()
{
	char str[100];
	FILE* f = fopen("pictures.html", "w");
	if (!f)
	{
		exit(1);
	}
	strcpy(str, "<html><head></head><body>");
	fputs(str, f);
	for (int i = 0; i < 20; i++)
	{
		strcpy(str, "<img src=\"audi.jpg\">");
		fputs(str, f);
	}
	strcpy(str, "<body / >< / html>");
	fclose(f);
}

void htmlWithDiv() 
{
	char str[100];
	char str2[100];
	scanf("%s", str2);
	FILE* f = fopen("greenDiv.html", "w");
	if (!f)
	{
		exit(1);
	}
	strcpy(str, "<html><head></head><body><div style=\"background-color: green\"><img src=\"");
	fputs(str, f);
	fputs(str2, f);
	strcpy(str,"\"></div></body></html>");
	fputs(str, f);
	fclose(f);
}

void htmlWithSomeDivs()
{
	char str[100];
	int numOfDivs;
	scanf("%d", &numOfDivs);
	FILE* f = fopen("manyDivs.html", "w");
	if (!f)
	{
		exit(1);
	}
	strcpy(str, "<html><head></head><body>");
	fputs(str, f);
	for (int i = 0; i < numOfDivs; i++) 
	{
		strcpy(str, "<div style=\"height:100px; width:100px; background-color: purple\"></div>");
		fputs(str, f);
	}
	strcpy(str, "</body></html>");
	fputs(str,f);
	fclose(f);
}

void generateHtmlFromPattern()
{
	char str[100];
	char str1[100];
	char str2[1000]="";
	char* token = 0,*token2=0;
	printf("Please enter your name: ");
	gets(str);
	FILE* f = fopen("test.html", "r"); //
	if (!f)
	{
		exit(1);
	}
	while (fgets(str1, sizeof(str1), f))
	{
		token = strtok(str1, "[");
		strcat(str2, token);
		token = strtok(NULL, "]"); 
		if (token)
		{
			strcat(str2, str);
			token = strtok(NULL, "]");
			strcat(str2, token);
		}
	}
	fclose(f);
	f = fopen("dupe.html", "w");
	if (!f)
	{
		exit(1);
	}
	fputs(str2,f);
	fclose(f);
}