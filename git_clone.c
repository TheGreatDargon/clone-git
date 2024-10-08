#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 3 || argc > 3) {
    	printf("Invalid amount of arguments: Please enter three arguments ./program arg1 arg2\n");
    	return 0;
    }

    char repo[strlen(argv[1]) + 1];
    char path[strlen(argv[2]) + 1];

    strcpy(repo, argv[1]);
    strcpy(path, argv[2]);
    path[strlen(path) + 1] = '\0';

    // create command for remove command
    char rm_command[9 + strlen(path) + 1];
    rm_command[0] = 'r';
    rm_command[1] = 'm';
    rm_command[2] = ' ';
    rm_command[3] = '-';
    rm_command[4] = 'r';
    rm_command[5] = ' ';
    rm_command[6] = '-';
    rm_command[7] = 'f';
    rm_command[8] = ' ';
    strcat(rm_command, path);

    char choice = '\0';

    // Ask if you would like to delete the directory for cloning to
    printf("Would you like to delete the path you entered? (y or n) \n**Warning be very careful with the path you give it, this is permanent**\n");
    
    while(choice != 'n') {
    	scanf("%c", &choice);
    	if (choice == 'y') {
    		int result = system(rm_command);

    		// Result of 0 means command completed successfully
    		if (result == 0) {
    			printf("successfully removed the path.");
    			break;
    		}
    		// Command didn't complete successfully
    		else {
    			printf("There was an error when removing the path.");
    		}
    	}
    }
    

    // Create the command for system call
	char git_command[11 + strlen(repo) + strlen(path) + 1];

    strcat(git_command, "git clone ");
    strcat(git_command, repo);
    strcat(git_command, " ");
    strcat(git_command, path);

    // call the system function and give it the git command
    int result = system(git_command);

    if (result == 0) {
    	printf("Files successfully cloned to path.\n");
    }
    else {
    	printf("There was an error when cloning the repo.\n");
    }


    return 0;

}
