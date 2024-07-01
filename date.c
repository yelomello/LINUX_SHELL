#include<stdio.h>
#include<string.h>
#include<time.h>

int main(int argc,char **argv) {
    int u=0;
    int j=1;
	time_t t;
	t = time(NULL);
	struct tm *timeid;

	if(argv[j]==NULL){ 
		timeid = localtime(&t);
		printf("%s", asctime(timeid));
	}

	else if(strcmp(argv[j],"--help")==u){
		printf("Usage: date [OPTION]... [+FORMAT] \n or:  date [-u|--utc|--universal] [MMDDhhmm[[CC]YY][.ss]] \n Display the current time in the given FORMAT \n   -u, --utc, --universal     print or set Coordinated Universal Time (UTC)\n   --help     \t\t      display this help and exit\n");

	}

	else if(strcmp(argv[j],"-u")==u || strcmp(argv[j],"--utc")==u || strcmp(argv[j],"--universal")==u){  
		timeid = gmtime(&t);
		printf("%s", asctime(timeid));
	}

	else {
		fprintf(stderr, "Divyam: improper format\n");
	}

	return 1;
}