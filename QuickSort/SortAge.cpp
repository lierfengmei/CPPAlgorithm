
void SortAges(int ages[],int length)
{
  if(ages==NULL || length<=0) return;
  const int oldestAge = 99;
  int timesOfAge[oldestAge+1]={0};
   
  //每个年龄计数完毕
  for(int i=0;i<length;i++)
   {
     int age = ages[i];
     if(age<0 || age>oldestAge) 
       throw new std::exception("The age value is out of range!");
     timesOfAge[age]++;
   }  

   //对年龄进行排序 timesOfAge[i]
   int index = 0;
   for(int i=0;i<=oldestAge;i++)
   {
     for(int j=0;j<timesOfAge[i];j++)
        age[index++] = i;
   }


}
