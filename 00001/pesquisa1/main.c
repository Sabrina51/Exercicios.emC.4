#include <stdio.h>
#include <stdlib.h>

main()
{

int i, quan_i_p=0, c;
float idade, peso, altura, idade_m, alt_int=0, idade_s;
float quant_p=0, p_olho_a, olho_a=0, ruiv=0;
char olho_c[2], cab_c[2];

    printf("\n Entre com a quantidade de pessoas: ");scanf("%d",&c);

    i=0;
    while(i<c){

        printf("\n Idade: "); scanf("%f", &idade);fflush(stdin);
        printf(" Peso (Kg): "); scanf("%f", &peso);fflush(stdin);
        printf(" Altura: "); scanf("%f", &altura);fflush(stdin);
        printf("\n A - Azul\n P - Preto\n V - Verde\n C - Castanho\n Cor dos olhos: "); fgets(olho_c, 2, stdin);fflush(stdin);
        printf("\n P - Preto\n C - Castanho\n L - Louro\n R - Ruivo\n Cor dos cabelos: "); fgets(cab_c, 2, stdin);

        quant_p++;

        if((idade > 50) && (peso < 60)){
           quan_i_p++;
        }

        if(altura < 1.50){
            idade_s = idade_s + idade;
            alt_int++;
        }

        idade_m = idade_s/alt_int;

        if(strcasecmp(olho_c, "a")==0){
            olho_a++;
        }

        p_olho_a = olho_a*100/quant_p;

        if((strcasecmp(cab_c, "r")==0) && (strcasecmp(olho_c, "a")!=0))
            ruiv++;

    i++;
    }

    printf("\n A quantidade de pessoas com mais de 50 anos com menos de 60Kg e %d", quan_i_p);
    printf("\n A media das idades das pessoas com altura inferior a 1,50 e %0.f", idade_m);
    printf("\n A Porcentagem de pessoas com olhos azuis entre todas as pessoas analisadas e %0.f%%", p_olho_a);
    printf("\n A Quantidade de pessoas ruivas e que não possuem olhos azuis e %0.f", ruiv);

    printf("\n\n FIM!\n");
    return 0;
}
