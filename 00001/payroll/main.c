#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

   int i, n;
   float total_slry=0, total_pcs=0, b_s=0;
   float piece_m=0, piece_f=0, male=0, female=0;
   float average_pcs_m, average_pcs_f;
   float number_piece, salary;
   char id[5], gender[2], id_b;

    printf("\n =========================================================");
    printf("\n = \t\t\t payroll\t\t\t = ");
    printf("\n =========================================================");

    printf("\n Employees Informations\n");
    printf("\n Number of employees: "); scanf("%d", &n);fflush(stdin);

        i=1;
        while(i<=n){
        printf("\n Employee %d", i);
        printf("\n Operator ID (xxxxx): "); fgets(id,5,stdin); fflush(stdin);
        printf(" Number of pieces: "); scanf("%f", &number_piece);fflush(stdin);
        printf(" Gender(f/m): "); fgets(gender, 2, stdin);fflush(stdin);

        if(number_piece <= 30)
            salary = 1120;

        else if(number_piece >= 31 && number_piece <= 35)
            salary = number_piece*(1120*0.03) + 1120;

        else
            salary = number_piece*(1120*0.05) + 1120;

        if(strcasecmp(gender,"m")==0){
            male++;
            piece_m = piece_m + number_piece;
        }

        if(strcasecmp(gender,"f")==0){
            female++;
            piece_f = piece_f + number_piece;
        }

        total_slry = total_slry + salary;
        total_pcs = total_pcs + number_piece;

        if(salary > b_s)
            b_s = salary;
            id_b = id;

        printf(" ----------------------------------------------");
        printf("\n Operator ID: %s Salary $%.2f", id, salary);
        printf("\n ----------------------------------------------\n\n");

        i++;
        }

    if(male != 0)
      average_pcs_m = piece_m/male;
    else
        average_pcs_m = 0;

    if(female != 0)
        average_pcs_f = piece_f/female;
    else
        average_pcs_f = 0;

    printf("\n Total payroll $%.2f", total_slry);
    printf("\n Total piece %.0f", total_pcs);
    printf("\n Average of parts manufactured by men %.0f", average_pcs_m);
    printf("\n Average of parts manufactured by women %.0f", average_pcs_f);
    printf("\n Operator ID with biggest salary - %s",id);

    printf("\n\n\n THE END ");


}
