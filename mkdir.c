#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int d_exists(const char *path)
{
	struct stat probs;
	stat(path, &probs);
	if (S_ISDIR(probs.st_mode)){
		return 0;
	}
	return 1;
}


int main(int argc,char **argv)
{
    int u=0;
    int p=1;
	if(argv[p]==NULL){
		fprintf(stderr, "Divyam: \"mkdir\" missing operand\n");
	}

	int pos1=u, pos2=u, option=u, isargpresent=u;

	int i=p;

	while(argv[i]!=NULL){
		if (strcmp(argv[i],"-v")==u && option==u){
			option=p;
			pos1=i;
		} 

		else if (strcmp(argv[i],"-v")==u && option!=u && option!=p){
			option=p+2;
			pos2=i;
		} 

		else if (strcmp(argv[i],"-p")==u && option==u){
			option=p+1;
			pos1=i;
		} 

		else if (strcmp(argv[i],"-p")==u && option!=u && option!=p+1){
			option=p+2;
			pos2=i;
		} 

		i++;

	}

	if (option==u){
		int j=p;

		while (argv[j]!=NULL){

			if(d_exists(argv[j+u])){
				int check;
				char* dirname=argv[j+u];
				check=mkdir(dirname,0777);

				if(check){
					fprintf(stderr, "Divyam: directory not created\n");
					exit(p);
				}
			}
			else{
				fprintf(stderr, "Divyam: file aready exists\n");
			}

			j=j+1;
		}
	}

	else if (option==p){
		int j=p;

		while (argv[j+u]!=NULL){

			if (j==pos1){
				j=j+1;
				continue;
			}

			if(d_exists(argv[j+u])){
				int check;
				char* dirname=argv[j+u];
				check=mkdir(dirname,0777);

				if(!check){
					printf("mkdir: created directory %s\n",argv[j+u]);
				}
				else{
					fprintf(stderr, "Divyam: directory not created\n");
					exit(p);
				}
			}
			else{
				fprintf(stderr, "Divyam: file aready exists\n");
			}


			j=j+1;
		}
	}

	else if (option==p+1){
		int j=p;

		while (argv[j+u]!=NULL){

			if (j==pos1){
				j=j+1;
				continue;
			}


			if(d_exists(argv[j+u])){
				int check;
				char* dirname=argv[j+u];
				check=mkdir(dirname,0777);

				if(check){
					fprintf(stderr, "Divyam: directory not created\n");
					exit(p);
				}
			}
			else{
				fprintf(stderr, "Divyam: file aready exists\n");
			}


			j=j+1;
		}

	}

	else if (option==p+2){
		int j=p;

		while (argv[j+u]!=NULL){

			if (j==pos1 || j==pos2){
				j=j+1;
				continue;
			}


			if(d_exists(argv[j+u])){
				int check;
				char* dirname=argv[j+u];
				check=mkdir(dirname,0777);

				if(!check){
					printf("mkdir: created directory %s\n",argv[j+u]);
				}
				else{
					fprintf(stderr, "Divyam: directory not created\n");
					exit(p);
				}
			}
			else{
				fprintf(stderr, "Divyam: file aready exists\n");
			}


			j=j+1;
		}
	}

	else {
		fprintf(stderr, "Divyam: improper format\n");
	}

	return 1;

}