#include <iostream>

void OutPutMassive(int** array, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int CountZeroElementsInMassive(int** array, int row, int column) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (array[i][j] == 0) {
                count += 1;
                break;
            }
        }
    }
    return count;
}

int* RowMassiveWithIndexRow(int** array, int row, int column, int count) {
    int* ZeroCoutRow = (int*)malloc(count*sizeof(int));
    int x = 0;
    for (int i = 0; i < row; i++) {
        if(x == count){ break;}
        for (int j = 0; j < column; j++) {
            if (array[i][j] == 0){
                ZeroCoutRow[x] = i;
                x+=1;
                break;
            }
        }
    }
    return ZeroCoutRow;
}

void ReplaceMassive(int** &Massive, int* &RowMassive,int NewRow,int NewColumn) {
    int countOne = 0; int countTwo = 0;
    for (int i = 0; i < NewRow; i++){
        if (i == RowMassive[countOne]){
            countOne += 1;
        }
        else{
            Massive[countTwo] = Massive[i];
            countTwo += 1;
        }
    }
}

int main() {
    // П1
    unsigned int row = 2;
    unsigned int column = 2;

    // Создание массива 
    int** Massive = (int**)calloc(column,sizeof(int*));
    for (int i = 0; i < row; i++) {
        Massive[i] = (int*)calloc(row,sizeof(int));
    }

    // Ввод чисел в массив 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            int InToNumber;
            std::cin >> InToNumber;
            Massive[i][j] = InToNumber;
        }
    }
    // Индексы
    int A = Massive[0][0]; int B = Massive[0][1];
    // Коэффициенты
    int C = Massive[1][0]; int D = Massive[1][1];

    if ((A < 0) or (B< 0)) {
        std::cout << "Try one more time" << std::endl;
        return 0;
    }

    //Новые размеры
    int NewRow = A + row; int NewColumn = B + column;
    
    //Изменение массива
    Massive = (int**)realloc(Massive, NewColumn * sizeof(int*));
    for(int i = 0; i < NewRow; i++) {
        Massive[i] = (int*)malloc(NewRow*sizeof(int));
    }

    //Изменение данных массива
    for (int i = 0; i < NewRow; i++) {
        for (int j = 0; j < NewColumn; j++) {
            if (i == j) {
                Massive[i][j] = (C * i) + (D * j);
            }
            if ((i > 0) and (j == 0)) {
                Massive[i][j] = (C * i) + (D * j);
            }
            if ((i == 0) and (j > 0)) {
                Massive[i][j] = (C * i) + (D * j);
            }
            else
                Massive[i][j] = (C * i) + (D * j);

        }
    }

    // Постановка элементов в нужное положение
    Massive[NewRow-2][NewColumn-2] = A; Massive[NewRow-2][NewColumn-1] = B;
    Massive[NewRow-1][NewColumn-2] = C; Massive[NewRow-1][NewColumn-1] = D;

    
    std::cout << std::endl;
    
    OutPutMassive(Massive, NewRow, NewColumn);
 
    int count = CountZeroElementsInMassive(Massive, NewRow, NewColumn);
    int* RowMassive = RowMassiveWithIndexRow(Massive, NewRow, NewColumn,count);


    NewRow-=count;

    std::cout << std::endl;
    // Очистка элементов
    for(int i = 0; i<count; i++){
        free(Massive[RowMassive[i]]);
    }
    // Перестановка элементов массива в низ 
    ReplaceMassive(Massive,RowMassive,NewRow,NewColumn);
    //Удаление не нужных строк снизу
    Massive = (int**)realloc(Massive, (NewRow) * sizeof(int*));

    std::cout << std::endl;
    OutPutMassive(Massive, NewRow, NewColumn);
    for(int i = 0; i<count; i++){
        std::cout<<RowMassive[i]<<" ";
    }

    //Очистка всей выделенной памяти
    free(RowMassive);
    for (int i = 0; i <(NewRow); i++) {
        free(Massive[i]);
    }
    free(Massive);
    





    // П2
    int a; 
    int b; 
    std::cin>>a; std::cin>>b;
    
    int* NumA = &a;
    int* NumB = &b;
    int* Swap = new int;
    *Swap= *NumA ;
    *NumA = *NumB;
    *NumB = *Swap*2;
    
    std::cout<<a<<" "<< b;
    delete(Swap);

    return 0;
}
