
void main()
{
  int year, cntr, x, y;
  x=3;
  y=1;
  year = x;
  cntr = y;	

  year = 1990; 
 
  if ( (year/400)*400 == year)		

	cntr = 1;

  else if ( (year/100)*100 == year)

	cntr = 2;

  else if ( (year/4)*4 == year )

	cntr = 3;

  else
	cntr = 4;
 
}
