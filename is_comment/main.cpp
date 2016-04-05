//
//  main.cpp
//  is_comment
//
//  Created by Mateus Mesturini Meruvia on 2/19/16.
//  Copyright © 2016 Mateus Mesturini Meruvia. All rights reserved.
//

#include <iostream>
#include <string>

bool is_identifier(std::string str){
    int n,i, current=0;
    n = str.length();
    
    if(str[1] == '/'){ // comments of the "//" type
    
        for(i=0; i<n; i++){
        
            if (i == 0 || i == 1) { // two first postion are "/"
                if( str[i] == '/' ){ // check if is a slash
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
        
            if (i > 1) { // from the third position can be any char
                if( str[i] >= 32 && str[i] <= 126 ){ // check if is a char from the asc table
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
        
            if(current == i) { // if 'current' and 'i' have the same value at this point it means that
                return false;  // none of the previous conditions were fullfilled, so its not a integer, returns FALSE
            }
        
        }
        return true;
    }

    if(str[1] == '*'){ // comments of the "/*  */" type

        for(i=0; i<n; i++){
            
            if (i == 0) { // first position has to be a  "/"
                if( str[i] == '/' ){ // check if is a slash
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
            
            if (i == 1) { // first position has to be a  "*"
                if( str[i] == '*' ){ // check if is a slash
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
            
            if (i > 1 && i < n-2) { // from the third position can be any char until the position n-2
                if( str[i] >= 32 && str[i] <= 126 ){ // check if is a char from the asc table
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
            
            if (i == n-2) { // first position has to be a  "*"
                if( str[i] == '*' ){ // check if is a slash
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
            if (i == n-1) { // first position has to be a  "/"
                if( str[i] == '/' ){ // check if is a slash
                    if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                        current++;
                    }
                }
            }
            
            
            if(current == i) { // if 'current' and 'i' have the same value at this point it means that
                return false;  // none of the previous conditions were fullfilled, so its not a integer, returns FALSE
            }
        }
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    std::string comment;
    
    while (1) {
        
        std::cout << "Input: ";
        std::getline (std::cin,comment); // reads a string from the standart input
        
        
        if(is_identifier(comment)==true){
            printf("Output: ACCEPTED\n\n");
        }else{
            printf("Output: NOT ACCEPTED\n\n");}
    }
    return 0;
}