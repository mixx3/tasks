#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getRandomPoint(){
    double rand1 = rand() / (double)RAND_MAX;
    double rand2 = rand() / (double)RAND_MAX;
    return rand1 - rand2;
}

int main(){
    int n;
    scanf("%d", &n);
    if (n < 2) exit(1);
    int number_of_points;
    scanf("%d", &number_of_points);
    if (number_of_points < 1) exit(1);
    double range = 2 / (double)n;
    int* points_in_range;
    points_in_range = calloc(n, sizeof(int));
    if (!points_in_range){
        printf("Allocation failed!\n");
        exit(1);
    }
    srand(time(NULL));
    for (int p = 0; p < number_of_points; p++){
        int index;
        double point = getRandomPoint();
        if (point < 0 && point != -1 || point == 1) index = (int)(point / range) - 1;
        else index = (int)(point / range);
        points_in_range[index + n / 2] ++;
    }
    printf("Center of range: Elements in range\n");
    for (int i = 0; i < n; i++){
        printf("%lf: %d\n", -1 +range * (2*i + 1) / 2,points_in_range[i]);
    }
    free(points_in_range);
    return 0;
}






