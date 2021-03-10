#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, n, male=0, female=0;
    float height, biggest_height=0, smaller_height=999;
    float women_average_height, women_height=0,women_height_sum=0;
    char gender[2], biggest_height_gender[8];

    printf("\n Survey");
    printf("\n ============================== \n");
    printf("\n Write the number of interviewed: "); scanf("%d",&n);

    i=1;
    while(i<=n){

        printf("\n Data of interviewed %d", i);

        printf("\n Height: ");
        scanf("%f", &height);
        fflush(stdin);

        printf(" Gender(f/m): ");
        fgets(gender,2,stdin);

        if(height < smaller_height)
            smaller_height = height;

        if (height > biggest_height){
            biggest_height = height;
            strcpy(biggest_height_gender,gender);
                if(strcmp(biggest_height_gender,"f")==0)
                    strcpy(biggest_height_gender,"Female");
                else
                    strcpy(biggest_height_gender,"Male");
        }

        if(strcasecmp(gender,"f")==0){
            female ++;
            women_height = height;
            women_height_sum = women_height_sum + height;
        }
        else
            male++;

    women_average_height = women_height_sum/female;

    i++;
    }

    printf("\n The smaller height is %.2f", smaller_height);
    printf("\n The biggest height is %.2f", biggest_height);
    printf("\n Average women height is %.2f", women_average_height);
    printf("\n There are %d men", male);
    printf("\n The tallest person gender is %s", biggest_height_gender);

    printf("\n\n\n THE END\n");

    return 0;
}
