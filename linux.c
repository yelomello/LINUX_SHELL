#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int exists(const char* lookingfor){
	DIR* thisdir=opendir(lookingfor);    //returns details about a directory 
	if (thisdir!=NULL){
		return 1;
	} else if (errno==ENOTDIR){
		return 0;
	} return -1;
}
int g=0;

int execute(char** command){
    int ab=0;
    int on = 1;
    int tw = 2;
    int hun = 100;
	if (command[ab] == NULL) {
		//No command entered
		return 1;
	} 

	else if (strcmp(command[ab],"cd")==ab){
        int fif=50;
		char location[fif]; 

		if (command[on]==NULL || strcmp(command[on],"~")==ab) {
			//Switches to home directory
			chdir(getenv("HOME"));
			printf("%s %s\n", "Current Directory:", getcwd(location, fif));
		} 

		else if (command[tw]!=NULL && command[tw]!="-L"){
			//Error Handling
			fprintf(stderr, "Divyam: too many arguments\n");
		} 

		else {
			if (exists(command[on])==on){
				//Switches to directory input by user
				chdir(command[on]); 
				printf("%s %s\n", "Current Directory:", getcwd(location, fif));
			} else {
				//Error handling
				fprintf(stderr, "Divyam: no such file or directory\n");
			}
		}

		return 1;
	} 

	else if (strcmp(command[ab],"echo")==ab){
		if(command[on]==NULL){
			//No input
			printf("\n");
		}
		else if (command[on]!=NULL){
			if(strcmp(command[on],"*")==ab){
				//Implementation of "*" flag
				DIR *d1;
				d1 = opendir("."); 
				struct dirent *bruh;
				while(d1)
				{
					bruh = readdir(d1);
					if (!bruh) break;
					if(bruh->d_name[ab]!='.'){
						printf("%s  \t", bruh->d_name);
					}

				}
				closedir(d1);
				printf("\n");
			}

			else if(strcmp(command[1],"-n")==ab){
				//Implementation of "-n" flag
				int p=2;

				while(on){
					if(command[p]==NULL){
						break;
					}
					p++;
				}

				int q=2;
				while (q!=p){
					if (q!=tw){
						printf(" ");
					}
					printf("%s",command[q]);
					q++;
				}
			}

			else {
				//For valid string input
				int index1=1;
				while(on){
					if(command[index1]==NULL){
						break;
					}
					index1=index1+on;
				}

				for(int i=on;i<index1;i++)
				{
					printf("%s ",command[i]);
				}
				printf("\n");

			} 
		} 

		else {
			fprintf(stderr, "Divyam: invalid input\n");
		}
		return 1;
	} 

	else if (strcmp(command[ab],"pwd")==ab){
		if (command[on]==NULL || strcmp(command[on],"-L")==ab ||  strcmp(command[on],"-P")==ab){
			char location[hun]; 
			printf("%s\n", getcwd(location, hun));
		} else {
			//Error handling
			fprintf(stderr, "Divyam: invalid input\n");
		}
		return 1;
	} 


	else {
		//For other commands

		char p[]="/home/divyam/codes/Assignment_1/";
		strcat(p,command[ab]);
		command[ab]=p;

		pid_t pid;
		int status;
		pid = fork();

		if (pid<ab) {
			fprintf(stderr, "Divyam: invalid command\n");
			exit(on);
		}

		else if (pid==ab) {
			if (execvp(command[ab],command)==-1) {
				fprintf(stderr, "Divyam: invalid command\n");
				exit(on);
			}
			exit(on);
		} 

		else {
			do { 
				wait(NULL); 
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		return 1;
	}
}

int on=1;

int main(int argc, char **argv){
	//loop ends when status is 0
	int status=on;

	while (status){
        int hun=100;
        int j=0;
        int k =-1;
		printf("\033[0;31mDivyam's shell>>> \033[0m");

		char *userinput=NULL;
		ssize_t size1=g;
		int getip;

		//Taking user input
		getip=getline(&userinput,&size1,stdin);

		if(getip==k){
			if(feof(stdin)){
				exit(on);
			}
			else{
				perror("Error 1: ");
				exit(on);
			}
		}

		char** separatedinput=malloc(hun*sizeof(char*));

		//Processing input
		char *curr;
		curr=strtok(userinput," \n");
		int i=j;
		while(curr!=NULL){
			separatedinput[i]=curr;
			i++;
			curr=strtok(NULL," \n");
		}
		separatedinput[i]=NULL;

		//Calling the execute function that contains the details about all functions
		status=execute(separatedinput);

		//Freeing memory
		free(separatedinput);
		free(userinput);
	}
}
