#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <cstdlib>

void OutputMassive(std::vector<int>& Massive){
    std::cout<<std::endl;
    std::cout<<"[";
    for( int n : Massive){
        std::cout<<n<<" ";
    }
    std::cout<<"]";
}
void SearchingElement(std::vector<int>& Massive){
    int num;
    int count = 0;
    std::cout<<"Введите число = ";
    std::cin>>num;
    for(int n: Massive){
        count+=1;
    }
    std::cout<<"\n";
    std::cout<<"[";
    for(int i=0; i < count; i++){
        if (Massive[i] == num){
            std::cout<<i<<" ";
        }
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
        Massive.push_back(0);
    }
    OutputMassive(Massive);
}
void AddToEnd(std::vector<int>& Massive){
    int num;
    std::cout<<"Введите число = ";
    std::cin>>num;
    Massive.push_back(num);
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
                           ////////////
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

int main(){
    int number;
    std::vector<int> massive  = {9,10,20,31};
    bool flag = true;
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

    // Пункт 2 
    const unsigned int row = 10;
    std::array<int,row> arr = {};
    for (int i = 0; i<row; i++){
        arr[i] = rand
    }



    std::cout<<"\n";

    std::cout<<"FINISH";
    return 0;
}