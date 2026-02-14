#pragma once
#include <string>     
#include <vector>     

class Book{
private:
    std::string author_;
    std::string title_ ;
    std::vector<std::string> composition_;
    int count_page_;
    float estimation_ ; 
    int cost_ ;

private:
    std::vector<std::string> add_elements(std::vector<std::string> a,std::vector<std::string> b, std::string author_a, std::string author_b) const;
    std::vector<std::string> add_elements(std::vector<std::string> a,std::vector<std::string> b) const;
    
    std::vector<std::string> add_elements_div(std::vector<std::string> a,std::vector<std::string> b, std::string author_a, std::string author_b) const;
    std::vector<std::string> add_elements_div(std::vector<std::string> a,std::vector<std::string> b) const;

    bool is_set_cost(float x);
    bool is_set_estimation(float estimation);
    
public:
    Book();
    ~Book();
    Book(std::string author,std::string title, std::vector<std::string> composition, int count_page, float estimation,int cost);
    Book(const Book &b);
    //GET
    std::string get_title() const ;
    std::string get_author() const ;
    std::vector<std::string> get_composition() const ;
    int get_count_page() const ;
    float get_estimation() const ;
    int get_cost() const ;

    void seting_cost(float x);
    void output_info();

    Book operator+(const Book& b) const;
    Book& operator+=(const Book& b);
    Book operator/(const Book& b)const;
    
    //SET
    void set_estimation(float estimation);
};
