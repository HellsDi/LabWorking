#include "Book.hpp"
#include <exception>
#include <vector>
#include <iostream>
#include <string> 
#include <random> 

// Book::
    std::vector<std::string> Book::add_elements(std::vector<std::string> a,std::vector<std::string> b, std::string author_a, std::string author_b)const{
        std::vector<std::string> tmp;
        for(int i = 0; i<a.size(); i++){
            std::string k = author_a +": " + a[i];
            tmp.resize(tmp.size()+1,(k));
        }
        for(int i = 0; i<b.size(); i++){
            std::string k = author_b +": " + b[i];  
            tmp.resize(tmp.size()+1,(k));
        }
        return tmp;
    }   
    std::vector<std::string> Book::add_elements(std::vector<std::string> a,std::vector<std::string> b)const{
        std::vector<std::string> tmp = a;
        std::vector<std::string> tmp_ = a;
        for(int i =0;i<b.size();i++){
        bool flag = false;
        for(int j=0; j<tmp.size();j++){
            if (b[i]== tmp[j]){
                flag = true;
                break;
            }
        }
        if (!flag){
            tmp_.resize(tmp_.size()+1,b[i]);
        }
        }
        return tmp_;
    }  

    std::vector<std::string> Book::add_elements_div(std::vector<std::string> a,std::vector<std::string> b, std::string author_a, std::string author_b)const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> int_dis(0, 1);
        
        std::vector<std::string> tmp_;

        for(int i = 0; i<a.size(); i++){
            std::string k = author_a +": " + a[i];
            tmp_.resize(tmp_.size()+1,(k));
        }
        for(int i = 0; i<b.size(); i++){
            std::string k = author_b +": " + b[i];  
            tmp_.resize(tmp_.size()+1,(k));
        }
        std::vector<std::string> tmp = tmp_;
        tmp_.clear();
        for(int i = 0; i<tmp.size();i++){
            if (int_dis(gen))
                tmp_.resize(tmp_.size()+1, tmp[i]);
        }
        return tmp_;
    }   
    std::vector<std::string> Book::add_elements_div(std::vector<std::string> a,std::vector<std::string> b) const  {
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> int_dis(0, 1);
        std::vector<std::string> tmp = a;
        std::vector<std::string> tmp_;
        for(int i =0;i<b.size();i++){
        bool flag = false;
            for(int j=0; j<a.size();j++){
                if (b[i]== a[j]){
                    flag = true;
                    break;
                }
            }
            if (!flag){
                tmp.resize(tmp.size()+1,b[i]);
            }
        }
        tmp_ = tmp;
        tmp.clear();
        for(int i = 0; i<tmp_.size();i++){
            if(int_dis(gen))
                tmp.resize(tmp.size()+1, tmp_[i]);
        }
        return tmp;
    }  

    bool Book::is_set_cost(float x){
            if(x>0.01f){
                return true;
            }          
            throw std::invalid_argument("invalid_argument");
    }
    bool Book::is_set_estimation(float estimation){
            if(estimation>0.0f){
                return true;    
            }
            throw std::invalid_argument("invalid_argument");
    }

    Book::Book(){
        author_ = "...";
        title_ ="...";
        composition_ = {"Nothing"};
        count_page_ = 0;
        estimation_ =  0.f;
        cost_ = 0;

    };
    Book::~Book(){
        composition_.clear();
        
        std::cout<<"Clear list"<<std::endl;
    };
    Book::Book(std::string author,std::string title, std::vector<std::string> composition, int count_page, float estimation,int cost):
    author_(author),composition_(composition),count_page_(count_page), estimation_(estimation), cost_(cost){
        author_ = author;
        title_ = title;
        composition_ = composition;
        count_page_ = count_page;
        estimation_ = estimation;
        cost_ = cost;
    };
    Book::Book(const Book &b){
        author_ = b.author_;
        title_ = b.title_;
        composition_ = b.composition_;
        count_page_ = b.count_page_;
        estimation_ = b.estimation_;
        cost_ = b.cost_;

    };
    
    //GET
    std::string Book::get_title() const {return title_;}
    std::string Book::get_author() const {return author_;}
    std::vector<std::string> Book::get_composition() const {return composition_;}
    int Book::get_count_page() const {return count_page_;}
    float Book::get_estimation() const {return estimation_;}
    int Book::get_cost() const {return cost_;}

   
    void Book::seting_cost(float x){
        if(is_set_cost(x)){
            cost_ = x;
        }
    } 
    void Book::output_info(){
        std::cout<<"Author: "<<get_author()<<"\n";
        std::cout<<"Title: "<<get_title()<<"\n";
        std::cout<<"Composition: ";
        for(int i = 0; i<composition_.size(); i++){
            std::cout<<composition_[i]<<" ";
        }
        std::cout<<"\n";
        
        std::cout<<"Count pages: "<<get_count_page()<<"\n";
        std::cout<<"Estimation: "<<get_estimation()<<"\n";
        std::cout<<"Cost: "<<get_cost()<<"\n";
    }  
    
    Book Book::operator+(const Book& b) const {

    Book result = *this;
    result.count_page_ = count_page_ + b.count_page_;
    result.title_ = title_;
    result.cost_ = int((cost_ + b.cost_) - 0.15f * (cost_ + b.cost_));
    result.estimation_ = estimation_;

    if (author_ == b.author_){
        result.author_ = b.author_;
        result.composition_ = add_elements(composition_, b.composition_);
    }
    else if (author_ != b.author_){
        result.composition_ = add_elements(composition_, b.composition_, author_, b.author_);
        result.author_ = author_+ " and "+ b.author_;
    }

    return result;
}
    Book& Book::operator+=(const Book& b){

        count_page_ += b.count_page_;
        cost_  = int((cost_+b.cost_) - 0.15f*(cost_+b.cost_));

        if (author_ == b.author_){
            author_ = b.author_;
            composition_ = add_elements(composition_, b.composition_);
        }
        else if (author_ != b.author_){
            composition_ = add_elements(composition_, b.composition_,author_,b.author_);
            author_ = author_+ " and "+ b.author_;
        }
        return *this;
    }
    Book Book::operator/(const Book& b)const {
        Book result = *this;
        result.title_ = title_;
        result.cost_  = cost_ + int((cost_+b.cost_) + 0.10f*(cost_+b.cost_));
        result.count_page_ = (b.count_page_+count_page_)-0.30f*(b.count_page_+count_page_);
        result.estimation_ = estimation_;
        
        if (author_ == b.author_){
            result.author_ = b.author_;
            result.composition_ = add_elements_div(composition_, b.composition_);
        }
        else if (author_ != b.author_){
            result.composition_ = add_elements_div(composition_, b.composition_, author_, b.author_);
            result.author_ = author_+ " and "+ b.author_;
        }
        return result;
    }
    
    //SET
    void Book::set_estimation(float estimation){
        if(is_set_estimation(estimation)){
            estimation_ = estimation;
        }
    }
