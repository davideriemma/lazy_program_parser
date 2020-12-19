#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 512

int main(int argc, char ** argv)
{
	if(argc != 3)
	{
		perror("Error, wrong number of arguments");
	}
	else
	{
		char * filename = argv[1], * macroname = argv[2], * tempname = tempnam(".", filename), buffer[MAX_BUFFER_SIZE];
		FILE * filein = fopen(filename, "r"), * fileout = fopen(tempname, "w");

		if(filein == NULL || fileout == NULL)
		{
			perror("Error opening files");
		}
		else
		{
			int ch;
			while((ch = getc(filein)) != EOF)
			{
				if(ch != '@')
				{
					fputc(ch, fileout);
				}
				else
				{

					unsigned int in_string_flag = 0;

					fprintf(fileout, "#ifdef %s\n\tprintf(", macroname);

					while((ch = getc(filein)) != '\n')
					{
						ungetc(ch, filein);

						fscanf(filein, "%s", buffer);

						if(strchr(buffer, '"'))
						{
							fprintf(fileout, "%s ", buffer); //scrive la prima virgoletta
							while(!in_string_flag)
							{
								fscanf(filein, "%s", buffer);

								if(strchr(buffer, '"'))
								{
									in_string_flag = 1;
									fprintf(fileout, "%s ", buffer);
								}
								else
								{
									fprintf(fileout, "%s ", buffer);
								}
							}
						}
						else
						{
							fprintf(fileout, ", %s", buffer);
						}
					}

					fprintf(fileout, ");\n#endif\n");
				} //else individuazione '@'
			}
		} //else verifica apertura files

		free(tempname); //free the string as specified
		fclose(filein);
		fclose(fileout);

		rename(tempname, filename);
	} //else verifica argomenti
}
