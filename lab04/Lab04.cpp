#include <iostream>

int main(){
    // 4.1
    
    int count = 0;
    int CountArray =  3+4;
    int NumberInArray ;
    // Input Number in an array
    int array[CountArray];
    for (int i = 0; i<CountArray; i++){
        std::cout<<"Number in array = ";
        std::cin>>NumberInArray;
        array[i] = NumberInArray;
    }  
    //Count correct number in an array
    for (int i = 0; i<CountArray; ++i){
      if (array[i]%5==0){
        ++count;
      }
    }

    if (count== CountArray){
        //Replace
        for (int i =0; i<CountArray;++i){
            for (int j = 0; j<CountArray;j++){
                if (array[j]> array[i]){

                    int tmp = array[i];
                    array[i] = array[j];        // I Can better
                    array[j] = tmp;

                }
            }
        }
    
        for (int i =0; i<CountArray;++i){
            std::cout<<array[i]<<" ";
        }
    }
    else{
        std::cout<<"Not Correct"<<std::endl;
    }
    
    
    //4.2
    //*
    int NumberInMassive;
    const int column = 4;
    const int row = 3;
    int CountNegativeNumber = 0;
    int array[column]={0,0,0,0};
    int MassiveArray[row][column]= {};
    
    // Import Number in Massive
    for(int i = 0;i<row;i++){
        for(int j = 0; j<column;j++){
            // std::cout<<"Number In Massive = ";
            std::cin>>NumberInMassive;
            MassiveArray[i][j] = NumberInMassive;
        }
    } 

    std::cout<<std::endl;
    
    // OutPut MassiveArray
    for(int i = 0;i<row;i++){
        for(int j = 0; j<column;j++){
        std::cout<<MassiveArray[i][j]<<"   ";
        }
        std::cout<<std::endl;
    }
    
    // Count Negative Number in Massive
    for (int j = 0; j<column; j++){
        for(int i = 0;i<row;i++){
            if((MassiveArray[i][j])<0){
                CountNegativeNumber+=1;
            }
        }
        array[j] = CountNegativeNumber;
        CountNegativeNumber = 0;
    }

    std::cout<<std::endl;
    
    // Find Column 
    int CountColumn=0;
    int Max = -10;
    int tmp = 0;
    for(int i = 0; i<column;i++){
        if (array[i]>Max){
            Max = array[i];
            tmp = i;
        }      
    }
    
    // replace to correct massive
    for (int i =0; i<row;i++){
        MassiveArray[i][tmp] = -1;
    }

    // Output correct massive
    std::cout<<std::endl;
    for(int i = 0;i<row;i++){
        for(int j = 0; j<column;j++){
        std::cout<<MassiveArray[i][j]<<"   ";
        }
        std::cout<<std::endl;
    }
    //*/
    return 0;
}