

//task 3 #4 problem

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (){   
    double sections[2][4];//array for coordinates {{x1,y1,x2,y2},{x1,y1,x2,y2}}
  
    printf("Enter the coordinates of the first segment(x;y):\n");
    for (int j = 0; j < 4; j++){
	    scanf ("%lf", &sections[0][j]);
	}
	printf("Enter the coordinates of the second segment(x;y):\n");
    for (int j = 0; j < 4; j++){
	    scanf ("%lf", &sections[1][j]);
	}
    double x, y;
    int flag = 1;


    if (sections[0][0] != sections[0][2] && sections[1][0] == sections[1][2]){
        double k1, b1;
        x = sections[1][0];
        k1 = (sections[0][3] - sections[0][1]) /
	        (sections[0][2] - sections[0][0]);
        b1 = sections[0][1] - k1 * sections[0][0];
        y = k1 * sections[1][0] + b1;
    }

    else if (sections[0][0] == sections[0][2] && sections[1][0] != sections[1][2]){
        double k2, b2;
        x = sections[0][0];
        k2 = (sections[1][3] - sections[1][1]) /
	        (sections[1][2] - sections[1][0]);
        b2 = sections[1][1] - k2 * sections[1][0];
        y = k2 * sections[0][0] + b2;
    }

    else if (sections[0][0] == sections[0][2] && sections[1][0] == sections[1][2]){
        x = sections[0][0];
        if (fmin(fmax(sections[0][1],sections[0][3]),fmax(sections[1][1],sections[1][3]))>= 
            fmax(fmin(sections[0][1],sections[0][3]),fmin(sections[1][1],sections[1][3]))){
            y = fmin(fmax(sections[0][1],sections[0][3]),fmax(sections[1][1],sections[1][3]));
        }
        
        else flag = 0;
        
    }
    else{
        double k1, k2, b1, b2;
        k1 = (sections[0][3] - sections[0][1]) /
	    (sections[0][2] - sections[0][0]);
        k2 = (sections[1][3] - sections[1][1]) /
	    (sections[1][2] - sections[1][0]);
        b1 = sections[0][1] - k1 * sections[0][0];
        b2 = sections[1][1] - k2 * sections[1][0];
        if (k1 == k2 && b1 == b2){
	        if (fmin(fmax(sections[0][2],sections[0][0]),fmax(sections[1][2],sections[1][0]))>= 
                fmax(fmin(sections[0][2],sections[0][0]),fmin(sections[1][2],sections[1][0]))){
                x = fmin(fmax(sections[0][2],sections[0][0]),fmax(sections[1][2],sections[1][0]));
                y = k1 * x + b1;
            } 
            
            else flag = 0;

	    }
	    
	    else if (k1 == k2) flag = 0;
	    
        else{
	        x = (b2 - b1) / (k1 - k2);
	        y = k1 * x + b1;
	    }
    }
    if (flag
        &&x <= fmax (sections[0][0], sections[0][2])
        && x <= fmax (sections[1][0], sections[1][2])
        && x >= fmin (sections[0][0], sections[0][2])
        && x >= fmin (sections[1][0], sections[1][2])
        && y <= fmax (sections[0][1], sections[0][3])
        && y <= fmax (sections[1][1], sections[1][3])
        && y >= fmin (sections[0][1], sections[0][3])
        && y >= fmin (sections[1][1], sections[1][3]))
    {
        printf ("x:%lf y:%lf\n", x, y);
    }
    else
        printf ("Theese sections are not crossing!\n");
    return 0;
}


