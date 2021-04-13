#include<iostream>
using namespace std;

class clockType{
	public:
		void setTime(int hours,int minutes,int seconds);
		void getTime(int &hours, int& minutes, int& seconds) const;
		void printTime() const;
		void incrementSeconds();
		void incrementMinutes();
		void incrementHours();
		bool equalTime(const clockType& otherClock) const;
		clockType(int hours, int minutes, int seconds);
		clockType();
	private:
		int hr;
		int min;
		int sec;

};
void clockType::setTime(int hours,int minutes,int seconds){
if(0<= hours && hours < 24)
	hr = hours;
else
	hr = 0;
if(0 <= minutes && minutes < 60)
	min = minutes;
else
	min = 0;
if(0<= seconds && seconds < 60)
	sec = seconds;
else
	sec =0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const{
hours = hr;
minutes = min;
seconds = sec;
}

void clockType::printTime() const{
if(hr<10)
	cout << "0";
cout << hr <<":";
if(min <10)
	cout << "0";
cout << min <<":";
if(sec < 10)
	cout << "0";
cout << sec;
cout << endl;
}
void clockType::incrementHours(){
hr++;
if(hr > 23)
	hr = 0;
}
void clockType::incrementMinutes(){
min++;
if(min >59){
min =0 ;
incrementHours();
}

}
void clockType::incrementSeconds(){

sec++;
if(sec > 59){
sec = 0;
incrementMinutes();

}
}
bool clockType::equalTime(const clockType& otherClock) const{

return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);

}
clockType::clockType(){
hr =0;
min=0;
sec = 0;

}
clockType::clockType(int hours, int minutes, int seconds){
if(0<= hours && hours < 24)
        hr = hours;
else
        hr = 0;
if(0 <= minutes && minutes < 60)
        min = minutes;
else
        min = 0;
if(0<= seconds && seconds < 60)
        sec = seconds;
else
        sec =0;
}
int main(){

clockType clock1;
clockType clock2;
clock1.setTime(6,15,55);
clock1.printTime();
clock2.setTime(6,15,55);
if(clock1.equalTime(clock2)){
	cout << "both the clocks are equal" << endl;
}
clock1.incrementHours();
clock1.incrementMinutes();
clock1.incrementSeconds();
clock1.printTime();
int hours, minutes, seconds;
clock1.getTime(hours,minutes,seconds);
cout << hours << ":" << minutes << ":" << seconds << endl;

 const clockType clock3;
 int hours1, minutes1, seconds1;
clock3.getTime(hours1,minutes1,seconds1);
cout << hours1 << ":" << minutes1 << ":" << seconds1 << endl;
clock3.printTime();
if(clock3.equalTime(clock2)){
        cout << "both the clocks are equal" << endl;
}
else{
	cout << "both the clocks are not equal" <<endl;
}

clock3.setTime(9,10,45);
return 0;
}
