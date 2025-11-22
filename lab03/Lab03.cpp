#include <iostream>
#include <cmath>

//Вариант 4
int main(){
    //3.1
    
    int CountNumberElements;
    std::cout<<"CountNumberElements = ";
    std::cin >> CountNumberElements;
    
    int MaxNumber = -pow(2,16);
    int SumNegativeNum = 0;
    int ElementLists;
    int count = 0;
    for(int i=0; i<CountNumberElements; ++i){
        
        std::cout<<"ElementLists =";
        std::cin>>ElementLists;
        if (ElementLists<0){
            SumNegativeNum+=ElementLists;
        }
        if (ElementLists>MaxNumber){
            MaxNumber = ElementLists;
            count =0;
        }
        if (MaxNumber == ElementLists){
            count+=1;
            
        }
    }
    std::cout<<"MaxNumber = "<<MaxNumber<<std::endl;
    std::cout<<"CountMaxNumbers = "<<count<<std::endl;

    if (SumNegativeNum<0){
        std::cout<<"SumNegativeNum = "<<SumNegativeNum<<std::endl;
    }



    
    // 3.2
    
    int A;
    std::cout<<"A = "; std::cin>>A;
    int MaxNum = 0;
    int NumberA = A;
    if ((A<1000)&&(A>-1000)){
        A = abs(A);
        int tmp = A;
        while(A>0){
            tmp = A%10;
            A/=10;
            if (MaxNum<tmp){
                MaxNum = tmp;
            }
        }
        
        std::cout<<"MaxNum = "<< MaxNum<<std::endl;
        std::cout<<"NumberA = "<<NumberA<<std::endl;
    }
    
    return 0;
}