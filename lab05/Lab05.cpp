#include <iostream>
#include <cmath>
const int row = 3;  
int Function(int num){
    std::cout<<"Use count input numbers"<<std::endl;
    int count = 0; int MaxNum = 0;
    num = abs(num);
    int tmp = num;
    while (num>0){
        tmp = num%10; num/=10;
        if (tmp>MaxNum){
            MaxNum = tmp; count =0;
        }
        if (MaxNum == tmp){
            count+=1;
        }
    }
    std::cout<<"Count = ";
    return count;
}
void Lab01(){
    const float pi = 13.1415f;
    float radius;
    std::cout << "radius = ";
    std::cin >> radius;
    float SurfaceArea = pow(radius,2)*4*pi;
    double Volume = (4 * abs(pow(radius,3))*pi)/3;
    std::cout<< "Sarface area = "<< SurfaceArea << std::endl;
    std::cout<< "Type = "<< typeid(SurfaceArea).name()  << " Size = " << sizeof(SurfaceArea) << " MaxSize = "<< std::numeric_limits<float>::max()<<" <MinSize = "<<std::numeric_limits<float>::lowest()<<std::endl;
    std::cout<< "Volume = "<< Volume << std::endl;
    std::cout<< "Type = "<< typeid(Volume).name() << " Size = " << sizeof(Volume)<< " MaxSize = "<< std::numeric_limits<double>::max() <<" <MinSize = "<<std::numeric_limits<double>::lowest()<<std::endl;
}
float Function(int a, int b, int c){
    std::cout<<"Use average number"<<std::endl;
    int num = abs(a+b+c);
    int minN = pow(2,16);
    int count = 0;
    int array[row] = {a,b,c};
    bool flag = true;
    if ((a!=b)and(a!=c) and (b!=c)){
            flag = true;
    }
    else{
        flag = false;
    }

    for (int i = 0;  i<row; i++){
        if (array[i]!=0){
            count +=1;
            if(array[i]<=minN){
                minN = array[i];
            }
        }
    }

    if (flag){
        float AverageNum = float(num)/count;
        std::cout<<"AverageNum = ";
        return AverageNum;
    } 
    else{
        std::cout<<"MinNum = ";
        return minN;
    }
}


int main(){
    int functions;
    int count = 0; int tmp = 0; int array[row] = {};
    std::cout<<"NumberFunctions = "; std::cin>>functions;   
    switch (functions){
    case 1:
        int num;
        for (int i = 0; i<row;i++){
            std::cout<<"Numbers = "; std::cin>> num;
            array[i] = num;
            if (array[i]!=0){
                count +=1;
                tmp = array[i];
            }
        }
        if (count == 1){
            std::cout<<Function(tmp);
        }
        else{
            int a = array[0]; 
            int b = array[1]; 
            int c = array[2];
            std::cout<<Function(a,b,c);
        }
        break;
    case 2:
        Lab01();
        break;
    default:
        std::cout<<"Not correct";
        break;
    }
    
    return 0;
}