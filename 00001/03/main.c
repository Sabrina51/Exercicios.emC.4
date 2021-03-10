#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    //INPUTS
    int i, n, product_code;
    float product_quantity;

    //OUTPUTS
    float unit_value, total, off, total_plus_off;

    printf("\n Which quantity of products? ");scanf("%d", &n);
    printf("\n ");

    i=1;
    while(i <= n){

        printf("\n Product %d", i);

        printf("\n Enter with code: "); scanf("%d", &product_code);
        while((product_code < 1) || (product_code > 40)){
            printf("\n Please, write a valid product code! "); scanf("%d", &product_code);
        }

        printf(" Enter with quantity of itens: "); scanf("%f", &product_quantity);

        if((product_code >= 1) && (product_code <= 10))
             unit_value = 10;

        else if((product_code >= 11) && (product_code <= 20))
             unit_value = 15;

        else if((product_code >= 21) && (product_code <= 30))
             unit_value = 20;

        else if((product_code >= 31) && (product_code <= 40))
             unit_value = 30;

        total = unit_value*product_quantity;

        if(total < 250)
            off = total*0.05;

        else if((total >= 250) && (total <= 500))
            off=total*0.10;

        else if(total > 500)
            off=total*0.15;

        total_plus_off = total - off;

        printf("\n Unit value of product $%.2f", unit_value);
        printf("\n Total $%.2f", total);
        printf("\n Off $%.2f", off);
        printf("\n Total with off $%.2f", total_plus_off);
        printf("\n ==================================");

        printf("\n");

        i++;
    }

    printf("\n THE END!\n");
    return 0;
}
