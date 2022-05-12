


#include <iostream>
using namespace std;

class Time{

    public:
        Time( int h = 0, int m = 0, int s = 0 ){ 
            (*this).setTime(h, m, s);
        }

        void setTime(int h, int m, int s){
            if(h>=0 && h<24 && m>=0 && m<60 && s>=0 && s<60){
                (*this).setHour(h);  cout<< this->totalSeconds <<"\n";
                (*this).setMinute(m);  cout<< this->totalSeconds <<"\n";
                (*this).setSecond(s);  cout<< this->totalSeconds <<"\n";     

                cout<<"set time finish\n\n";
            }
            else cout<<"invalid\n";
        }

        void setHour(int h){
            if(h>=0 && h<24){
                int m =(*this).getMinute();
                int s =(*this).getSecond();
                (this->totalSeconds) = 3600*h + 60*m + s;
            }
            else cout<<"invalid\n";
        }
    
        void setMinute(int m){
            if(m>=0 && m<60){
                int h =(*this).getHour();
                int s =(*this).getSecond();
                (this->totalSeconds) = 3600*h + 60*m + s;
            }
            else cout<<"invalid\n";
        }

        void setSecond(int s){
            if(s>=0 && s<60){
                int h =(*this).getHour();
                int m =(*this).getMinute();
                (this->totalSeconds) = 3600*h + 60*m + s;
            }
            else cout<<"invalid\n";
        }
        
        int getHour(){
            int H = (this->totalSeconds)/3600;
            return H;
        }

        int getMinute(){
            int ts_temp = (this->totalSeconds);
            int H = ts_temp/3600;
            ts_temp = ts_temp - 3600*H;
            int M = ts_temp/60;
            return M;
        }

        int getSecond(){
            int ts_temp = (this->totalSeconds);
            int H = ts_temp/3600;
            ts_temp = ts_temp - 3600*H;
            int M = ts_temp/60;
            int S = ts_temp - 60*M;
            return S;
        }   
    
		void printUniversal(void){
            int h = (*this).getHour();
            int m = (*this).getMinute();
            int s = (*this).getSecond();

            cout<<h<<" : "<<m<<" : "<<s<<"\n\n";
        }

		void printStandard(void){
            int h = (*this).getHour();
            int m = (*this).getMinute();
            int s = (*this).getSecond();
            int state = 1;//state=0, print PM; state=1, print AM

            if(h>12){
                h = h -12;
                state = 0;//print PM
            }

            cout<< h <<" : "<< m <<" : "<< s;
            if(state == 1) 
                cout<<"\t\tAM\n\n";
            else{ //state ==0
                cout<<"\t\tAM\n\n";
            }
        }
		
    private:
        int totalSeconds;

};  

int main(){
    Time a(3,6,1), b(1,2,3), c, d;
    int h=0, m=0, s=0;

    cout<< c.getHour()<<" : " <<c.getMinute()<<" : "<<c.getSecond()<<"\n\n"; 

    c.setTime(23, 59, 59);

    cout<< c.getHour() << " : " <<c.getMinute() <<" : "<< c.getSecond() <<"\n\n";    

    c.setHour(4);
    c.setMinute(63);
    c.setSecond(52);
    
    cout<< c.getHour()<<" : " <<c.getMinute()<<" : "<<c.getSecond()<<"\n\n";         

	c.printUniversal();
	c.printStandard();

    return 0;
}

	//[Error] 'int Time::totalSeconds' is private
    //cout<< c.totalSeconds<<"\n";