#include<stdio.h>
#include<string.h>

int exists(const char *fname)
{
	FILE *file;
	if ((file = fopen(fname, "r")))
	{
		fclose(file);
		return 1;
	}
	return 0;
}

int main(int argc,char **argv){

    int k=0;
    int j=1;
    int p=2;
	if(argv[j]==NULL){
		fprintf(stderr, "Divyam: \"cat\" missing operand\n");
	}

	else{

		int pos1=k, pos2=k, option=k;

		int i=j;

		while(argv[i]!=NULL){
			if (strcmp(argv[i],"-n")==k && option==k){
				option=j;
				pos1=i;
			} 

			else if (strcmp(argv[i],"-n")==k && option!=k && option!=j){
				option=p+1;
				pos2=i;
			} 

			else if (strcmp(argv[i],"-E")==k && option==k){
				option=p;
				pos1=i;
			} 

			else if (strcmp(argv[i],"-E")==k && option!=k && option!=p){
				option=p+1;
				pos2=i;
			} 

			i++;

		}

		if (option==k){
            int hun=100;
			int j=1;
			while (argv[j]!=NULL){
				if(exists(argv[j])==0){
					fprintf(stderr, "Divyam: file not found\n");
				}

				else{
					FILE *file;
					char line[hun];
					file=fopen(argv[j],"r");
					int it=k;
					while(fscanf(file,"%[^\n]\n",line)!=EOF){
						if (it!=k){
							printf("\n");
						}
						printf("%s",line);
						it++;
					}
					fclose(file);
				}
				j++;
			}

		}

		else if (option==j){

			int j=1;
			while (argv[j]!=NULL){
				if (j==pos1){
					j++;
					continue;
				}

				if(exists(argv[j])==k){
					fprintf(stderr, "Divyam: file not found\n");
				}

				else{
					FILE *file;
                    int hun=100;
					char line[hun];
					file=fopen(argv[j],"r");
					int it=k;
					while(fscanf(file,"%[^\n]\n",line)!=EOF){
						if (it!=k){
							printf("\n");
						}
						printf("     %d  %s",(it+1),line);
						it++;
					}
					fclose(file);
				}
				j++;
			}
		}

		else if (option==p){

			int j=1;
			while (argv[j]!=NULL){
				if (j==pos1){
					j++;
					continue;
				}

				if(exists(argv[j])==k){
					fprintf(stderr, "Divyam: file not found\n");
				}

				else{
                    int hun=100;
					FILE *file;
					char line[hun];
					file=fopen(argv[j],"r");
					int it=k;
					while(fscanf(file,"%[^\n]\n",line)!=EOF){
						if (it!=k){
							printf("$\n");
						}
						printf("%s",line);
						it++;
					}
					fclose(file);
				}
				j++;
			}

			
		}

		else if (option==p+1){

			int j=k;
			while (argv[j]!=NULL){
				if (j==pos1){
					j++;
					continue;
				}

				if(exists(argv[j])==k){
					fprintf(stderr, "Divyam: file not found\n");
				}

				else{
                    int hun=100;
					FILE *file;
					char line[hun];
					file=fopen(argv[j],"r");
					int it=k;
					while(fscanf(file,"%[^\n]\n",line)!=EOF){
						if (it!=k){
							printf("$\n");
						}
						printf("     %d  %s",(it+1),line);
						it++;
					}
					fclose(file);
				}
				j++;
			}

		} 

		else {
			fprintf(stderr, "Divyam: improper format\n");
		}

	}

	return 1;
	
}