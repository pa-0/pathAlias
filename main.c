#include <stdio.h>
#include <windows.h>
#include <Shlwapi.h> 

int main(int argc, char *argv[])
{	
		char path[1000];
		GetModuleFileName( NULL, path, 1000 );
		PathRemoveFileSpecA(path);
	if (argc == 4){
		char buffer[10000];
		sprintf(buffer,"echo set PATH=%s;^%%PATH^%%> %s\\%s.bat\n",argv[1],path,argv[3]);
		system(buffer);
		sprintf(buffer,"echo %s %%* >> %s\\%s.bat",argv[2],path,argv[3]);
		system(buffer);
		printf("Batch file (hopefully) created\n");
	}else if (argc == 3){
		char buffer[10000];
		sprintf(buffer,"echo %s %%* > %s\\%s.bat",argv[1],path,argv[2]);
		system(buffer);
		printf("Batch file (hopefully) created\n");
	}else{
		printf("Usage: pathalias <path> <executable> <alias> \n");
		printf("This will create a batch file that adds <path> to a temporary path, and run the <executable> command, tha file name will be <alias>.bat\n");
		printf("Exemple: pathalias c:\\soft\\java8 java java8 \n\n");
		printf("Usage: pathalias <path\\executable> <alias>\n");
		printf("This will create a batch file that runs the <path\\executable>, tha file name will be <alias>.bat\n");
		printf("Exemple: pathalias c:\\soft\\java8\\java java8");
	}
    return 0;
}

