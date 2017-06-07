/* time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <iostream>
using namespace std;
int main ()
{
 
  struct tm y2k = {0};
  double seconds;



  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);
  cout << "Current local time and date:" <<asctime(timeinfo);
  
  time_t tora;
  
  int pw =0;
  for (int i=0; i<10000;i++){
  
  	pw +=i;
  	cout << pw << endl;
  }
  
  time (&tora);
  seconds = difftime(rawtime,tora);
  
  cout << "\nsecondi di esecuzione: [ " << seconds << " ]";
  


  return 0;
}
