#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    // INPUTS
    int appli, age;
    char gender[2], experience[2];

    //PROCESS DATES
    float average, percent_plus_45;

    //COUNTS
    int i, less_age_male = 999;
    int male = 0, female = 0;
    int count_age_men = 0, count_men = 0;
    int count_men_45 = 0, count_women_35 = 0;

    printf("\n Which numbers of applicants? ");
    scanf("%d",&appli); fflush(stdin);

    i=1;
    while(i <= appli){

        // INPUT AND VALIDATIONS AREA
        printf("\n =======================================");
        printf("\n Applicant %d",i);
        printf("\n Gender(f/m): "); fgets(gender, 2, stdin); fflush(stdin);

            while((strcasecmp(gender,"m") !=0) && (strcasecmp(gender,"f") !=0)){
                printf("\n Please, try a valid gender! \n Choose F for female or M for male ==> "); fgets(gender, 2, stdin); fflush(stdin);
                printf("\n");
            }

        printf(" Age: "); scanf("%d", &age); fflush(stdin);

        printf(" Experience(y/n): "); fgets(experience, 2, stdin); fflush(stdin);

            while((strcasecmp(experience,"y") !=0) && (strcasecmp(experience,"n") !=0 )){
                printf("\n Please, try a valid option! \n Choose Y for yes or N for not ==> "); fgets(experience, 2, stdin); fflush(stdin);
                printf("\n");
            }

        // COUNT AREA

        if (strcasecmp(gender,"m") ==0){
            male++;
            if(age > 45)
                count_men_45++;
        }else{
            female++;
            if((age < 35) && (strcasecmp(experience,"y") ==0))
                count_women_35++;

            if(strcasecmp(experience,"y") ==0){
                if(age < less_age_male)
                    less_age_male = age;
            }
        }

        if((strcasecmp(experience,"y") ==0) && (strcasecmp(gender,"m") ==0)){
            count_age_men = count_age_men + age;
            count_men++;
            average = count_age_men/count_men;
        }

        i++;
    }

    percent_plus_45 = count_men_45 * 100 / male;

    printf("\n Male applicants %d", male);
    printf("\n Female applicants %d", female);
    printf("\n Age men average with experience is %.0f years old", average);
    printf("\n Percentage of men 45+ years old %.0f%%", percent_plus_45);
    printf("\n Women 35- years old with experience %d", count_women_35);
    printf("\n Smaller woman age with experience %d", less_age_male);

    printf("\n\n THE END!\n");
    return 0;
}
