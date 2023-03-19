#include <stdio.h>
#include <string.h>

typedef struct Tanggal {
    int day, year;
    char month[15];
} Date;

void input(Date, Date);
int sameday(Date, Date);

int main(int argc, char const *argv[])
{
    Date day1, day2;

    printf("day1\nDate: ");
    scanf("%d", &day1.day);
    fflush(stdin);
    printf("Month: ");
    fgets(day1.month, sizeof(day1.month), stdin);
    printf("Year: ");
    scanf("%d", &day1.year);

    printf("day2\nDate: ");
    scanf("%d", &day2.day);
    fflush(stdin);
    printf("Month: ");
    fgets(day2.month, sizeof(day2.month), stdin);
    printf("Year: ");
    scanf("%d", &day2.year);

    if(sameday(day1, day2)) {
        printf("It is the same day\n");
    } else {
        printf("It is not the same day\n");
    }

    return 0;
}

int sameday(Date day_1, Date day_2) {
    int flag;
    int str = strcmp(day_1.month, day_2.month);

    if((day_1.day == day_2.day) && (!str) && (day_1.year == day_2.year)) {
        flag = 1;
        printf("same\n");
    } else {
        flag = 0;
        printf("diff\n");
    }

    return flag;
}