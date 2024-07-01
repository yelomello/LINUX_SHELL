#include <dirent.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char **argv) {
	DIR *directory1;
	struct dirent *de;
    int u=0;
    int p=1;

	int pos1=u, pos2=u, option=u, isargpresent=u;

	int i=p;

	while (argv[i]!=NULL){
		if (strcmp(argv[i],"-1")==u && option==u){
			option=p;
			pos1=i;
		} 

		else if (strcmp(argv[i],"-1")==u && option!=u && option!=p){
			option=p+2;
			pos2=i;
		} 

		else if (strcmp(argv[i],"-a")==u && option==u){
			option=p+1;
			pos1=i;
		} 

		else if (strcmp(argv[i],"-a")==u && option!=u && option!=p+1){
			option=p+2;
			pos2=i;
		} 

		else if (strcmp(argv[i],"-a")!=u && strcmp(argv[i],"-1")!=u){
			isargpresent=p;
		}

		i++;
	}

	if (option==u){

		if (isargpresent==p){

			int j=p;

			while (argv[j]!=NULL){
				directory1 = opendir(argv[j]);

				if (directory1==NULL){
					fprintf(stderr, "Divyam: cannot open specified directory\n");
					j=j+1;
					continue;
				}

				printf("%s:\n", argv[j]);

				while ((de = readdir(directory1)) != NULL){
					if((de->d_name[u]!='.')){
						printf("%s\t ", de->d_name);
					}
				}

				printf("\n\n");
				closedir(directory1);
				j=j+1;
			}

		} else {

			directory1 = opendir(".");

			if (directory1==NULL){
				fprintf(stderr, "Divyam: cannot open specified directory\n");
				return 1;
			}

			while ((de = readdir(directory1)) != NULL){
				if((de->d_name[u]!='.')){
					printf("%s\t ", de->d_name);
				}
			}
			printf("\n");
			closedir(directory1);
		}
	}

	else if (option==p){

		if (isargpresent==p){

			int j=p;

			while (argv[j]!=NULL){

				if (j==pos1){
					j=j+1;
					continue;
				}

				directory1 = opendir(argv[j]);

				if (directory1==NULL){
					fprintf(stderr, "Divyam: cannot open specified directory\n");
					j=j+1;
					continue;
				}

				printf("%s:\n", argv[j]);

				while ((de = readdir(directory1)) != NULL){
					if((de->d_name[u]!='.')){
						printf("%s\n", de->d_name);
					}
				}

				printf("\n");
				closedir(directory1);
				j=j+1;
			}

		} else {

			directory1 = opendir(".");

			if (directory1==NULL){
				fprintf(stderr, "Divyam: cannot open specified directory\n");
				return 1;
			}

			while ((de = readdir(directory1)) != NULL){
				if((de->d_name[u]!='.')){
					printf("%s\n", de->d_name);
				}
			}
			closedir(directory1);
		}

	}

	else if (option==p+1){
		if (isargpresent==p){

			int j=p;

			while (argv[j]!=NULL){

				if (j==pos1){
					j=j+1;
					continue;
				}

				directory1 = opendir(argv[j]);

				if (directory1==NULL){
					fprintf(stderr, "Divyam: cannot open specified directory\n");
					j=j+1;
					continue;
				}

				printf("%s:\n", argv[j]);

				while ((de = readdir(directory1)) != NULL){
					printf("%s\t ", de->d_name);
				}

				printf("\n\n");
				closedir(directory1);
				j=j+1;
			}

		} else {

			directory1 = opendir(".");

			if (directory1==NULL){
				fprintf(stderr, "Divyam: cannot open specified directory\n");
				return 1;
			}

			while ((de = readdir(directory1)) != NULL){
				printf("%s\t ", de->d_name);
			}
			printf("\n");
			closedir(directory1);
		}
	}

	else if (option==p+2){
		if (isargpresent==p){

			int j=p;

			while (argv[j]!=NULL){

				if (j==pos1 || j==pos2){
					j=j+1;
					continue;
				}

				directory1 = opendir(argv[j]);

				if (directory1==NULL){
					fprintf(stderr, "Divyam: cannot open specified directory\n");
					j=j+1;
					continue;
				}

				printf("%s:\n", argv[j]);

				while ((de = readdir(directory1)) != NULL){
					printf("%s\n", de->d_name);
				}

				printf("\n");
				closedir(directory1);
				j=j+1;
			}

		} else {

			directory1 = opendir(".");

			if (directory1==NULL){
				fprintf(stderr, "Divyam: cannot open specified directory\n");
				return 1;
			}

			while ((de = readdir(directory1)) != NULL){
				printf("%s\n", de->d_name);
			}
			closedir(directory1);
		}
	}

	else {
		fprintf(stderr, "Divyam: improper format\n");
	}

	return 1;
}
