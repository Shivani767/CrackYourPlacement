/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start=0,balance=0,deficit=0;
       
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
           
           if(balance<0){
               start=i+1;
               deficit+=balance;
               balance=0;
           }
       }
       
       return deficit+balance>=0 ? start : -1;
    }
};

