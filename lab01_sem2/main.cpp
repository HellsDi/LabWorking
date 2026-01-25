#include <iostream>

class Book{
private:
    std::string title_ ;
    int count_page_;
    float estimation_ ;
    int cost_ ;

protected:
    std::string author_;
protected:
    bool is_set_cost(float x){
            if(x>0.01f){
                return true;
            }          
            throw std::invalid_argument("invalid_argument");
    }
    bool is_set_estimation(float estimation){
            if(estimation>0.0f){
                return true;    
            }
            throw std::invalid_argument("invalid_argument");
    }
public:
    Book(){
        author_ = "...";
        title_ ="...";
        count_page_ = 0;
        estimation_ =  0.f;
        cost_ = 0;
    }
    ~Book(){
        std::cout<<"Clear list"<<std::endl;
    }

    Book(std::string author,std::string title, int count_page, float estimation,int cost):
    author_(author), title_(title), count_page_(count_page), estimation_(estimation), cost_(cost){
        author_ = author;
        title_ = title;
        count_page_ = count_page;
        estimation_ = estimation;
        cost_ = cost;
    }
    Book(const Book &b){
        author_ = b.author_;
        title_ = b.title_;
        count_page_ = b.count_page_;
        estimation_ = b.estimation_;
        cost_ = b.cost_;
    }

    std::string get_author() const {return author_;}
    std::string get_title() const {return title_;}
    int get_count_page() const {return count_page_;}
    float get_estimation() const {return estimation_;}
    int get_cost() const {return cost_;}


    void set_estimation(float estimation){
        if(is_set_estimation(estimation)){
            estimation_ = estimation;
        }
    }
    void seting_cost(float x){
        if(is_set_cost(x)){
            cost_ = x;
        }
    } 
    void output_info(){
        std::cout<<"Author: "<<get_author()<<"\n";
        std::cout<<"Title: "<<get_title()<<"\n";
        std::cout<<"Count pages: "<<get_count_page()<<"\n";
        std::cout<<"Estimation: "<<get_estimation()<<"\n";
        std::cout<<"Cost: "<<get_cost()<<"\n";
    }  
};

int main(){
    std::cout<<"\n";
    Book book;
    book.output_info();
    book.get_author();
    book.get_title();
    book.get_cost();
    book.get_estimation();
    book.get_cost();

    std::cout<<"\n";    
    
    Book book1("Le Petit Prince","Antoine de Saint-Exupery", 224, 8.8f, 572.f);
    book1.output_info();

    book1.get_author();
    book1.get_title();
    book1.get_cost();
    book1.get_estimation();
    book1.get_cost();
    std::cout<<"\n";    
    
    Book book2(book1);
    
    float a;
    float b;


    try{
        std::cout<<"change estimation: ";
        std::cin>>a;    
        book2.set_estimation(a);
    }catch(std::invalid_argument){
        std::cout<<"Not correct argument"<<std::endl;
    }

      
    try{
        std::cout<<"change cost: ";
        std::cin>>b;  
        book2.seting_cost(b);
    }catch(std::invalid_argument ){
        std::cout<<"Not correct argument"<<std::endl;
        std::cout<<"\n";
    }

    book2.output_info();
    book2.get_author();
    book2.get_title();
    book2.get_cost();
    book2.get_estimation();
    book2.get_cost();     

    std::cout<<"\n";    
    return 0;
}

// Le Petit Prince 
// Antoine de Saint-Exupery
// 224
// 8.8
// 572