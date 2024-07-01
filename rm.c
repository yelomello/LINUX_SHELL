#include<stdio.h> 
#include<string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int exists(const char* lookingfor){
	DIR* thisdir=opendir(lookingfor);

	if(thisdir!=NULL){
		closedir(thisdir);
		return 0;
	} else if(errno==ENOTDIR) {
		return 1;
	} return -1;
}

int main(int c, char *argv[]) {
	int u=0;
	int p=1; 
	
	if(argv[p]==NULL){
		fprintf(stderr, "Divyam: \"rm\" missing operand\n");
	}

	else{
		int pos1=u, pos2=u, option=u;

		int i=p;

		while(argv[i]!=NULL){
			if (strcmp(argv[i],"-i")==u && option==u){
				option=p;
				pos1=i;
			} 

			else if (strcmp(argv[i],"-i")==u && option!=u && option!=p){
				option=p+2;
				pos2=i;
			} 

			else if (strcmp(argv[i],"-v")==u && option==u){
				option=p+1;
				pos1=i;
			} 

			else if (strcmp(argv[i],"-v")==u && option!=u && option!=p+1){
				option=p+2;
				pos2=i;
			} 

			i=i+1;

		}

		if (option==u){

			int j=p;

			while (argv[j]!=NULL){
				if(exists(argv[j])==p){
					remove(argv[j]);    
				}
				else{
					fprintf(stderr, "Divyam: improper format\n");
				}
				j=j+1;
			}
		}

		else if (option==p){

			int j=p;

			while (argv[j]!=NULL){

				if (j==pos1){
					j=j+1;
					continue;
				}

				if(exists(argv[j])==p){
					char* a=NULL;
					ssize_t sizea=u;
					printf("rm: remove file %s? ",argv[j]);
					getline(&a, &sizea, stdin);
					if(strcmp(a,"y\n")==u){
						remove(argv[j]);
					} else {
						//do nothing
					}
				}
				else{
					fprintf(stderr, "Divyam: improper format\n");
				}

				j=j+1;
			}

		}

		else if (option==p+1){

			int j=1;

			while (argv[j+u]!=NULL){

				if (j==pos1){
					j=j+1;
					continue;
				}

				if(exists(argv[j+u])==p){
					printf("%s\n",argv[j]);
					remove(argv[j]);   
				}
				else{
					fprintf(stderr, "Divyam: improper format\n");
				}

				j=j+1;

			}
		} 

		else if (option==p+2) {

			int j=p;

			while (argv[j+u]!=NULL){

				if (j==pos1 || j==pos2){
					j=j+1;
					continue;
				}

				if(exists(argv[j])==p){
					char* a=NULL;
					ssize_t sizea=u;
					printf("rm: remove file %s? ",argv[j+u]);
					getline(&a, &sizea, stdin);
					if(strcmp(a,"y\n")==u){
						printf("removed %s\n",argv[j]);
						remove(argv[j+u]);
					} else {
						//do nothing
					}
				}

				else {
					fprintf(stderr, "Divyam: improper format\n");
				}


				j=j+1;
			}

		}

		else {
			fprintf(stderr, "Divyam: improper format\n");
		}


		return 1; 

	}
}