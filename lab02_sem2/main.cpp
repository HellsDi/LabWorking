#include "Book.hpp"
#include <iostream>

int main(){
    std::cout<<"\n";
    Book book("Antoine","Little",{"a","b","c","h","j","f","d"}, 224, 8.8f, 572);
    Book book1("Antoine","Little",{"i","q","w"}, 2241, 8.8f, 5972);

    book/=book1;
    book.output_info();
    std::cout<<"\n";   
    return 0;
}

// Le Petit Prince 
// Antoine de Saint-Exupery
// 224
// 8.8
// 572