#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    int i, num, j;

    printf("\nEnter the number: ");
    scanf("%d", &num);

    pid = fork();

    if(pid == 0){
	j = num;        for(i=1; j>1; j=j-1){
            i=i*j;
        }
        printf("\nThe factorial of %d is: %d", num, i);
    }
    else if(pid > 0){
        wait(NULL);
        printf("\nProcesso pai finalizado!\n");
    }
    else { // Erro ao criar processo filho
        printf("Erro ao criar processo filho.\n");
        exit(1);
    }

    return 0;
}

