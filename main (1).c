

//task 3 #4 problem

#include <stdio.h>

double
average (double a, double b)
{
  return (a + b) / 2;
}

double
max (double a, double b)
{
  return a > b ? a : b;
}

double
min (double a, double b)
{
  return a < b ? a : b;
}

int
main ()
{
  double sections[2][4];
  //array for coordinates {{x1,y1,x2,y2}{x1,y1,x2,y2}}
  for (int i = 0; i < 2; i++)
    {
      printf (i ? "Enter the coordinates of the second segment(x;y):\n" :
	      "Enter the coordinates of the first segment(x;y):\n");
      for (int j = 0; j < 4; j++)
	{
	  double cordinate;
	  scanf ("%lf", &cordinate);
	  sections[i][j] = cordinate;
	}
    }
  //computation
  double k1, k2, b1, b2, x, y;



  if (sections[0][0] != sections[0][2] && sections[1][0] == sections[1][2])
    {
      //if the first section is parallel to y axis
      x = sections[1][0];
      k1 = (sections[0][3] - sections[0][1]) /
	(sections[0][2] - sections[0][0]);
      b1 = sections[0][1] - k1 * sections[0][0];
      y = k1 * sections[1][0] + b1;
    }

  if (sections[0][0] == sections[0][2] && sections[1][0] != sections[1][2])
    {
      //if the second section is parallel to y axis
      x = sections[0][0];
      k2 = (sections[1][3] - sections[1][1]) /
	(sections[1][2] - sections[1][0]);
      b2 = sections[1][1] - k1 * sections[1][0];
      y = k2 * sections[0][0] + b2;
    }

  if (sections[0][0] == sections[0][2] && sections[1][0] == sections[1][2])
    {
      //if both of the sections are parallel to y axis
      x = sections[0][0];
      /*if the center of the first section is higher than the center of the second section,
         y = max(y(second)),and vice versa */
      y =
	average (sections[0][1], sections[0][3]) >= average (sections[1][1],
							     sections[1][3]) ?
	max (sections[1][1], sections[1][3]) : max (sections[0][1],
						    sections[0][3]);
    }

  else
    {
      //k = (y2 - y1) / (x2 - x1)
      k1 = (sections[0][3] - sections[0][1]) /
	(sections[0][2] - sections[0][0]);
      k2 = (sections[1][3] - sections[1][1]) /
	(sections[1][2] - sections[1][0]);
      //b = y1 - k * x1
      b1 = sections[0][1] - k1 * sections[0][0];
      b2 = sections[1][1] - k1 * sections[1][0];
      if (k1 == k2 && b1 == b2)
	{
	  //case when sections are parallel to each other
	  x =
	    average (sections[0][0],
		     sections[0][2]) >= average (sections[1][0],
						 sections[1][2]) ?
	    max (sections[1][0], sections[1][2]) : max (sections[0][0],
							sections[0][2]);
	  y = k1 * x + b1;
	}
      else
	{
	  x = (b2 - b1) / (k1 - k2);
	  y = k1 * x + b1;
	}

    }
  if (x <= max (sections[0][0], sections[0][2])
      && x <= max (sections[1][0], sections[1][2])
      && x >= min (sections[0][0], sections[0][2])
      && x >= min (sections[1][0], sections[1][2])
      && y <= max (sections[0][1], sections[0][3])
      && y <= max (sections[1][1], sections[1][3])
      && y >= min (sections[0][1], sections[0][3])
      && y >= min (sections[1][1], sections[1][3]))
    {
      printf ("x:%lf y:%lf\n", x, y);
    }
  else
    printf ("Theese sections are not crossing!\n");
  return 0;
}
