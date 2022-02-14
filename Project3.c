#include <stdio.h>
#include <stdlib.h>


int checkCrn(int crn)
{
    int i = 0;
    int CRN[] = {4587, 4599, 8997, 9696, 4580, 4581, 4582, 4583, 3587, 4519, 6997, 9494};
    for (i = 0; i < 12; i++)
        if (CRN[i] == crn)
            return 1;
    return 0;
}


int getCreditHours(int crn)
{
    switch (crn)
    {
    case 4587:
        return 4;
    case 4599:
        return 3;
    case 8997:
        return 1;
    case 9696:
        return 5;
    case 4580:
        return 3;
    case 4581:
        return 4;
    case 4582:
        return 2;
    case 4583:
        return 2;
    case 3587:
        return 4;
    case 4519:
        return 3;
    case 6997:
        return 1;
    case 9494:
        return 3;
    default:
        return 0;
    }
}
char *printPrefix(int crn)
{
    switch (crn)
    {
    case 4587:
        return "MAT 236";
    case 4599:
        return "COP 220";
    case 8997:
        return "GOL 124";
    case 9696:
        return "COP 100";
    case 4580:
        return "MAT 230";
    case 4581:
        return "MAT 231";
    case 4582:
        return "MAT 232";
    case 4583:
        return "MAT 233";
    case 3587:
        return "MAT 256";
    case 4519:
        return "COP 420";
    case 6997:
        return "GOL 127";
    case 9494:
        return "COP 101";
    default:
        return "\t";
    }
}
void main()
{
    double ch = 120.25, fee = 35;
    int crn[3], hours[3];
    while (1)
    {
        double total = 0;
        int i = 0, sid, n, credsum = 0, flag;
        char c;
        printf("Enter the student id: \n");
        scanf("%d", &sid);
        printf("Enter how many courses up to 3:  \n");
        scanf("%d", &n);
        if (n > 3 || n < 1)
        {
            printf("Invalid number of courses\n");
            n = 0;
            scanf("%d", &flag);
        }
        else
        {
            printf("Enter the %d course number(s)\n", n);
            for (i = 0; i < n; i++)
                scanf("%d", &crn[i]);
            for (i = 0; i < n; i++)
            {
                if (checkCrn(crn[i]) == 0)
                {
                    printf("Sorry Invalid CRN(s)\n\n");
                    flag = -1;
                    break;
                }
                hours[i] = getCreditHours(crn[i]);
                credsum = credsum + hours[i];
            }
        }
        if (flag != -1)
            if (credsum > 7)
                printf("Sorry we can't process more than 7 credit hours\n");
            else
            {
                printf("VALENCE COMMUNITY COLLEGE\n ORLANDO FL 10101\n");
                printf("---------------------\n\n");
                printf("Fee invoice prepared for Student V%d \n\n ", sid);
                printf("1 Credit hour = %.2f \n\n", ch);
                printf("CRN\tCR_PREFIX\tCR_HOURS\n");
                for (i = 0; i < n; i++)
                {
                    double d = hours[i] * ch;
                    printf("%d\t%s\t%d\t$ %.2f\n", crn[i], printPrefix(crn[i]), hours[i], d);
                    total = total + d;
                }
                total = total + fee;
                printf("\n\tHealth & id fees $ %.2f\n", fee);
                printf("--------------------------------------\n");
                printf("\t Total Payments $ %.2f\n", total);
            }
        printf("Would you like to continue Y=yes N=no\n");
        scanf("%c");
        scanf("%c", &c);
        do
        {
            if (c == 'N' || c == 'n')
            {
                printf("Thank you for using the program, Goodbye!\n");
                exit(0);
            }
            if (c != 'Y' && c != 'y')
            {
                printf("INVALID ENTRY It has to y or n\n");
                scanf("%c");
                scanf("%c", &c);
            }
        } while (c != 'Y' && c != 'y');
    }
}