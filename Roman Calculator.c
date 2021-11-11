/* Roman Calculator*/

#include<stdio.h>
 
int input(void); /*Reads the characters and makes the right checks */
int calculator(int,int);  /* Reads  the arithmetic  operation and checks */
void metatropeas(int);  /* Converts a decimal number to a roman numeral */
int main (){
	
	int num1,num2,num; /* num1 is the first number , num2 is the second number and num is the final number */
	printf("Enter the first number: ");
	num1=input(); /* Returns the number to the variable num1 */
	printf("The first number is %d\n", num1);
	printf("Enter the second number: ");
	num2=input(); /* Returns the number to the variable num2 */
	printf("The second number is %d\n", num2);
	printf("Enter the desired arithmetic operation: \n");
	num=calculator(num1,num2); /*Returns the final number to the variable num*/
	metatropeas(num1); /*Prints the converter number*/
	printf(" and "); 
	metatropeas(num2); /*Prints the converter number*/
	printf(" is ");
	metatropeas(num); /*Prints the converter number*/
	printf(" ( ");
	printf("%d",num); 
	printf(" )");	
	return 0; 
}

int input(void){ 
	char num;
	int cnt=0,sum=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0;
	while((num=getchar())!='\n'){
	 /*In this loop the program checks if the the roman numeral is entered correctly
	 (M -> D -> C -> L -> X -> V -> I ) 
	 Also the program checks the maximum number of roman numbers (D=1, C=4, L=1, X=4, V=1, I=4) */ 	
		switch(num){
			case 'I':
				sum+=1;  
				cnt1++;  
				break;         
			case 'V':
				sum+=5;
				cnt2+=5;  
				if (cnt1!= 0)
					cnt++;	
				break;
			case 'X':     
				sum+=10;   
				cnt3+=10;  
				if (cnt2 != 0 || cnt1 != 0)
					cnt++;
				break;
			case 'L':
				sum+=50;
				cnt4+=50;  
				if (cnt3 != 0 || cnt2 != 0 || cnt1 != 0)
					cnt++;
				break;
			case 'C':
				sum+=100;
				cnt5+=100;  
				if (cnt4 != 0 || cnt3 != 0 ||cnt2 != 0 || cnt1 != 0)
					cnt++;
				break;
			case 'D':
				sum+=500;
				cnt6+=500;  
				if (cnt5!= 0 || cnt4 != 0 || cnt3 != 0 || cnt2 != 0 || cnt1 != 0)
					cnt++;
				break;
			case 'M':
				sum+=1000;
				if (cnt1!= 0 || cnt2!= 0 || cnt3!= 0 || cnt4!= 0 || cnt5!= 0 || cnt6!= 0)
					cnt++;
				break;
			default:
          	       cnt++;    
          	       break;  
        } 
		    
    }
    if(cnt!=0 || cnt1>=5 || cnt2>=10 || cnt3>=50 || cnt4>=100 || cnt5>=500 || cnt6>=1000 || sum==0){  
        printf("Incorect number. Please enter the number again: ");
        sum=input(); /*calls the function again*/
    }
    return sum;
}


int calculator (int num1,int num2){ 
/*In this function the program does the mathematical operations 
for the two numbers and checks if the user enters the right arithmetic operation*/
	char op;
	int results=0;
	scanf("%s",&op);
if(num1>=num2){  /* Checks if the first number is bigger than the second one */
	if(op=='+'){
		printf("The sum of ");
		results=num1+num2;
	}
	else if(op=='-'){
		printf("The subtraction of ");
		results=num1-num2;
	}
	else if(op=='*'){
		printf("The multiplication of ");
		results=num1*num2;
	}
	else if(op=='/'){
		printf("The division of ");
		results=num1/num2;
	}
	else {
		printf("Invalid arithmetic operation: ");
	 	results=calculator(num1,num2);
    }
}
if(num2>=num1){ // Checks if the first number is bigger than the second one */
	if(op=='+'){
		printf("The sum ");
		results=num1+num2;
	}
	else if(op=='-'){
		printf("The subtraction ");
		results=num2-num1;
	}
	else if(op=='*'){
		printf("The multiplication ");
		results=num1*num2;
	}
	else if(op=='/'){
		printf("The division ");
		results=num2/num1;
	}
	else {
		printf("Invalid arithmetic operation: ");
	 	results=calculator(num1, num2);
    }
}
return results;
}

void metatropeas(int num){ 
/* This function converts the decimal numbers to the roman numerals */
	int i=num;
    while(i>0){
        for(i=num;i>=1000;i-=1000){    
            printf("M");
            num-=1000;
        }
        for(i=num;i>=500;i-=500){
            printf("D");
            num-=500;
        }
        for(i=num;i>=100;i-=100){
            printf("C");
            num-=100;
        }
        for(i=num;i>=50;i-=50){
            printf("L");
            num-=50;
        }
        for(i=num;i>=10;i-=10){
            printf("X");
            num-=10;
        }
        for(i=num;i>=5;i-=5){
            printf("V");
            num-=5;
        }
        for(i=num;i>=1;i-=1){
            printf("I");
            num-=1;
        }
    } 
}
