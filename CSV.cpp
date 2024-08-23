#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void extract_data(const std::string& html_content, std::ofstream& file){
    std::vector<std::string> products={
        "Product1, $10, 4.5",
        "Product2, $20, 4.0",
        "Product3, $30, 3.5",

    };
    file << "Name,Price,Rating\n";
    for (const auto& product : products){
        file <<product << "\n";
    }
}

int main(){
    std::string html_content = "<html>...</html";
    
    std::ofstream file("products.csv");
    if(!file.is_open()){
        std::cerr<<"Error opening file for writing." << std::endl;
        return 1;
        
    }
    extract_data(html_content,file);
    file.close();
    std::cout<<"Product information has been saved to products.csv" <<std::endl;
    return 0;
}


