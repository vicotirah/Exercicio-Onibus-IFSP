#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 24

//variáveis
int janela[N]={0}, corredor[N]={0}, contadorj=0, contadorc=0;
int op, assento;

//funções
void veLugar(int i, int vetor[]){
  for(int j = 0; j<i; j++){
        if(vetor[j]==0){
              printf("\nAssento %d: 0", j+1);
        }else{
            printf("\nAssento %d: 1", j+1);
        }
  }
}
void escolheLugar(int vetor[], int *contador, int assento) {
    if(vetor[assento-1]==0){
      vetor[assento-1]=1;
            (*contador)++;
        }else{
          printf("\nEsse assento ja foi comprado!\n");
        }
}
int main(){
  setlocale(LC_ALL, "Portuguese");
  do{
      if(contadorj==N && contadorc==N){
        printf("\nO ônibus está cheio!");
        break;      
      }else{
        printf("\nOpções:\n1-Janela\n2-Corredor\n3-Sair\nEscolha a opção:");
        scanf("%d", &op);	
      switch(op){
        case 1:
          printf("\nOpção escolhida: Janela\n");
          if(contadorj==N){
            printf("\nNão há mais assentos na janela!\n");
            break;
          }else{        	
        veLugar(N, janela);	     
            printf("\nEscolha o número do seu assento: ");
            scanf("%d", &assento);
        escolheLugar(janela,&contadorj,assento);
            break; 	
          }
        case 2:
           printf("\nOpção escolhida: Corredor\n");
          if(contadorc==N){
            printf("\nTodos os assentos do corredor estão ocupados\n");
            break;
        }else{
            veLugar(N, corredor);	
            printf("\nEscolha o número do seu assento: ");
            scanf("%d", &assento);
            escolheLugar(corredor,&contadorc,assento);
      }		
          break;		
        case 3:
          break;
        }
      }
  }while(op!=3);	
  printf("\nObrigado pela preferência!");	 
 return 0; 
}
