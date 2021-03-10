#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i;
    float value_unit, tax, coast_storage, total;
    char refrigeration[2], category[2], classification[10];

    i=1;
    while(i<=2){

        printf("\n Product %d", i);
        printf("\n =============================================\n");
        printf("\n Write the price per unit($): "); scanf("%f", &value_unit); fflush(stdin);

        printf("\n\n Choose refrigeration need");
        printf("\n ---------------------------------------------\n");
        printf("\n Y for products that need refrigeration \n N for products that don't need refrigeration\n Option: ");
        fgets(refrigeration, 2, stdin); fflush(stdin);

        printf("\n\n Choose the category");
        printf("\n ---------------------------------------------\n");
        printf("\n F - Food \n C - Cleaning \n G - Garment\n Option: ");
        fgets(category, 2, stdin); fflush(stdin);

        if(value_unit < 50){
            if(strcasecmp(category,"f")==0)
                coast_storage = 5;
            else if(strcasecmp(category,"c")==0)
                coast_storage = 10;
            else
                coast_storage = 15;
        }

        if(value_unit > 50 && value_unit < 70){
            if(strcasecmp(refrigeration,"y") ==0)
                coast_storage = 21;
            else
                coast_storage = 12;
        }

        if(value_unit > 70){
            if((strcasecmp(refrigeration,"y") ==0) && (strcasecmp(category, "f")==0))
              coast_storage = 6;
            else if ((strcasecmp(refrigeration, "n") ==0) && (strcasecmp(category, "c")==0))
              coast_storage = 2;
            else{
                if(strcasecmp(category,"g")==0)
                    coast_storage = 4;
                else if(strcasecmp(category,"f")==0)
                    coast_storage = 0;
                else if(strcasecmp(category,"c")==0)
                    coast_storage = 1;
            }
        }

        if(value_unit < 50)
            strcpy(classification,"Cheap");
        else if((value_unit > 50) && (value_unit < 70))
            strcpy(classification,"Normal");
        else
            strcpy(classification,"Expensive");

        if((strcasecmp(refrigeration, "y") ==0) && (strcasecmp(category,"f")==0))
            tax = value_unit*0.4;
        else
            tax = value_unit*0.2;

        total = value_unit + coast_storage +  tax;

        printf("\n Coast Storage $%.2f", coast_storage);
        printf("\n Tax $%.2f", tax);
        printf("\n Product classification: %s", classification);
        printf("\n Total $%.2f \n\n", total);

    i++;
    }

    printf("\n THE END ");

    return 0;
}
