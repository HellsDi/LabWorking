#include <iostream>
#include <cmath>

using namespace std;

// Запускается и завершается метод main, который вычисляет площадь поверхности и объем шара    
                                                                                                           
void fun(){
    const float pi = 3.1415f;

    float radius;
    cout << "radius = ";
    cin >> radius;

    float SurfaceArea = pow(radius,2)*4*pi;
    double Volume = (4 * abs(pow(radius,3))*pi)/3;


    cout<< "Sarface area = "<< SurfaceArea << endl;
    cout<< "Type = "<< typeid(SurfaceArea).name()  << " Size = " << sizeof(SurfaceArea) << " MaxSize = "<< numeric_limits<float>::max()<<" <MinSize = "<< numeric_limits<float>::min()<<endl;

    cout<< "Volume = "<< Volume << endl;
    cout<< "Type = "<< typeid(Volume).name() << " Size = " << sizeof(Volume)<< " MaxSize = "<< numeric_limits<double>::max() <<" <MinSize = "<<numeric_limits<double>::lowest()<<endl;
}
int main(){
    fun();
    return 0;
}       
/* Использование float должно быть только положительным для 
Коррекного вычисления площади поверхности и объема шара*/