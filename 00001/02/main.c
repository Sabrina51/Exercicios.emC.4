#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i,q, country_origin;
    char hazardous_cargo[2], type_transportation[2];
    float transportation_value, security_value;
    float final_value, unit_value, tax;

    printf("\n Product Info");
    printf("\n ========================================================================================================");
    printf("\n\t ATTENTION! For products from Mexico or air transportation has an additional security fee");
    printf("\n ========================================================================================================");
    printf("\n\n Quantity of products: ");scanf("%d", &q);

    i=1;
    while(i<=q){
        printf("\n ** Product %d **", i);

        printf("\n Unit Value($): ");scanf("%f",&unit_value);fflush(stdin);

        printf("\n Hazardous cargo");
        printf("\n Y -YES\n N - NOT\n Selected: ");
        fgets(hazardous_cargo,2,stdin);

        printf("\n Country");
        printf("\n 1 - EUA\n 2 - MEXICO\n 3 - OUTROS\n Selected: ");
        scanf("%d", &country_origin);fflush(stdin);

        printf("\n Transportation");
        printf("\n T - TERRESTRIAL\n F - FLUVIAL\n A - AIR\n Selected: ");
        fgets(type_transportation,2,stdin);fflush(stdin);

        // TAB TAX
        if(unit_value <= 100)
            tax = unit_value*0.05;

        else if(unit_value > 100)
            tax = unit_value*0.10;

        // TRANSPORTATION TAB VALUE
        if(strcasecmp(hazardous_cargo, "y") == 0){
            if(country_origin == 1)
                transportation_value =50;

            else if(country_origin == 2)
                transportation_value =35;

            else if(country_origin == 3)
                transportation_value = 24;
        }

        if(strcasecmp(hazardous_cargo, "n") == 0){
            if(country_origin == 1)
                transportation_value = 12;

            else if(country_origin == 2)
                transportation_value = 34;

            else if(country_origin == 3)
                transportation_value = 60;
        }

        // SECURITY CALC
        if(country_origin == 2 || strcasecmp(type_transportation, "a") == 0)
            security_value = unit_value/2;

        final_value = unit_value + tax + transportation_value + security_value;

        if(security_value !=0){
            printf("\n =======================================");
            printf("\n *Security fee amount $%.2f\n", security_value);
        }
        else
            printf("\n =======================================\n");

    printf("\n Final value $%.2f", final_value);
    printf("\n Tax total $%.2f", tax);
    printf("\n Transportation value $%.2f \n", transportation_value);
    printf("\n =======================================");

    security_value=0;

    i++;

    }

    printf("\n THE END!\n");
    return 0;
}
