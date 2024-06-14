#include "cal.h"

int getNumOfDaysInMonth(int mon, int year)
{

switch(mon)
  {
  	case 1:
  	case 3:
	case 5: 	
	case 7:
	case 8:
	case 10:
	case 12:			  	
	  	sprintf("\n This month have 31 Days ");
	  	break;
	
	case 4:	
	case 6:
	case 9:
	case 11:			    	
	  	sprintf("\n This month have 30 Days ");  
		break;
	
	case 2:
	  	sprintf("\n This month have 28 or 29 Days");  
	
	default:		  	
	    sprintf("\n Please enter Valid Number between 1 to 12");
  }
  return 0;
}