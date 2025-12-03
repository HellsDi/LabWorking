#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <cstdlib>

// Пункт 1
// ---------------------------------------------
void OutputMassive(const std::vector<int>& Massive){
    std::cout<<std::endl;
    std::cout<<"[";
    for(int i = 0; i<(Massive.size());i++){
        if ((i+1)==Massive.size()){
            std::cout<<Massive[i];
        }
        else{
            std::cout<<Massive[i]<<" ";
        }
    }
    std::cout<<"]";
}
void SearchingElement(const std::vector<int>& Massive){
    int num;
    int count = 0;
    std::cout<<"Введите число = ";
    std::cin>>num;
    std::cout<<"\n";
    std::cout<<"[";
    for(int i =0; i<(Massive.size());i++){
       count+=1; 
    }

    for(int i = 0; i<(Massive.size());i++){
        
        if ((Massive[i] == num) and ((count-1)==0)) {
            std::cout<<i;
        }

        else if (((count-1)!=0) and (Massive[i] == num)){
            std::cout<<i<<" ";
        }
        count-=1;
    }

    std::cout<<"]";
}
void OptionNumFour(std::vector<int>& Massive){

    OutputMassive(Massive);
    std::cout<<"\n";
    int tmp = std::numeric_limits<int>::max();
    for(int num: Massive){
        if ((abs(num)<tmp) and (num!=0)){
            tmp = num;
        }
    }
    for(int x =0; x<tmp; x++){
        Massive.reserve(Massive.size()+tmp);
        Massive.push_back(0);
    }
    OutputMassive(Massive);
}
void AddToEnd(std::vector<int>& Massive){
    int num;
    std::cout<<"Введите число = ";
    std::cin>>num;
    Massive.reserve(Massive.size()+1);
    Massive.push_back(num);
}
void AddToBeggin(std::vector<int>& Massive){
    int num;
    std::cout<<"Введите число = ";
    std::cin>>num;
    Massive.reserve(Massive.size()+1);
    Massive.insert(Massive.begin(),num);
}
void ConsoleMenu(int i, std::vector<int>& Massive, bool& flag){
    switch (i){
    case 0:
        flag = false;
        break;
    case 1:
        OutputMassive(Massive);
        break;
    case 2:
        AddToBeggin(Massive);
        break;
    case 3:
        AddToEnd(Massive); ////
        break;
    case 4:
        Massive.clear();
        break;
    case 5:
        SearchingElement(Massive);
        break;
    case 6:
        OptionNumFour(Massive);
        break;
    default:
        std::cout<<"Wrong, try again."<<std::endl;
        break;
    }
}
// ---------------------------------------------

//Пункт 2
// ---------------------------------------------
void OutputMassive(const std::array<int,10>& Massive, int row){
    std::cout<<std::endl;
    std::cout<<"[";
    for(int i = 0; i<(row);i++){
        if ((i+1)==row){
            std::cout<<Massive[i];
        }
        else{
            std::cout<<Massive[i]<<" ";
        }
    }
    std::cout<<"]";
}
void SortWithOut(std::array<int,10> Massive, int row){
    for(int i = 0; i<(row); i++){
        for(int j =0; j<(row-1-i); j++){
            if (Massive[j]>Massive[j+1]){
                int tmp = Massive[j];
                Massive[j] = Massive[j+1];
                Massive[j+1] = tmp;
            }
        }
    }
}
void SortWithAmpersand(std::array<int,10>& Massive, int row){
    for(int i = 0; i<(row); i++){
        for(int j =0; j<(row-1-i); j++){
            if (Massive[j]>Massive[j+1]){
                int tmp = Massive[j];
                Massive[j] = Massive[j+1];
                Massive[j+1] = tmp;
            }
        }
    }
}
void SortWithIndicator(std::array<int,10>* Massive, int row){
    for(int i = 0; i<(row); i++){
        for(int j =0; j<(row-1-i); j++){
            if ((*Massive)[j]> (*Massive)[j+1] ){
                int &tmp = (*Massive)[j];
                (*Massive)[j] = (*Massive)[j+1];
                (*Massive)[j+1] = (tmp);
            }
        }
    }
}
// ---------------------------------------------

int main(){
    //Пункт 1
    // ---------------------------------------------
    int number;
    std::vector<int> massive = {9,20,1,4};
    bool flag = false;
    while (flag){
        std::cout<<std::endl;
        std::cout<<"-------------------------------"<<std::endl;
        std::cout<<"0. Выход"<<std::endl;
        std::cout<<"1. Просмотр массива."<<std::endl;
        std::cout<<"2. Добавить элемент в начало."<<std::endl; //
        std::cout<<"3. Добавить элемент в конец."<<std::endl; //
        std::cout<<"4. Очистка всего массива."<<std::endl;
        std::cout<<"5. Поиск элемента в массиве."<<std::endl;
        std::cout<<"6. Задание варианта (Вариант 4)."<<std::endl;
        std::cout<<"-------------------------------"<<std::endl;

        std::cout<<"Введите число = ";
        std::cin>>number;
        std::cout<<std::endl;
        ConsoleMenu(number, massive, flag);
    }
    // ---------------------------------------------

    // Пункт 2 
    // ---------------------------------------------
    const unsigned int row = 10;
    std::array<int,row> arr = {};
    //Заполнение массива
    for (int i = 0; i<row; i++){
        arr[i] = (rand()%(20))-10;
    }
    OutputMassive(arr,row);
    std::cout<<"\n";
    // ---------------------------------------------
    // По значению
    SortWithOut(arr,row);
    OutputMassive(arr,row);
    std::cout<<"\n";
    //По указателю
    SortWithIndicator(&arr,row);
    OutputMassive(arr,row);
    std::cout<<"\n";
    //По ссылке
    SortWithAmpersand(arr,row);
    OutputMassive(arr,row);
    std::cout<<"\n";

    // ---------------------------------------------
   
    
    

    
    std::cout<<"\n";
    std::cout<<"FINISH";
    return 0;
}