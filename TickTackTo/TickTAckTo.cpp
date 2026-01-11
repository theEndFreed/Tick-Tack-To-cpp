
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>

void PrintField(const std::vector<std::vector<std::string>>& v) {
    for (const auto& row : v) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int UserInput(std::vector<std::vector<std::string>>& v){
    int row;
    int col;

    std::cout << "Enter row and column (0, 1, or 2) to place your mark: " << std::endl;
    while(true) {
        std::cin >> row >> col;
        if(row >= 0 && row <= 2 && col >= 0 && col <= 2 && v[row][col] == "#") break;
        std::cout << "Invalid input, try again.\n";
    }

    v[row][col] = "X";
    return 0; 
}

bool winCheck(const std::vector<std::vector<std::string>>& v){   
    for (const auto& row : v) {
        if(!row.empty() && row[0] != "#"){
            bool all_the_same = std::all_of(row.begin(), row.end(), [&](const std::string& x) {return x == row[0];});
            if(all_the_same) return true;
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] != "#") return true;
    }
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[1][1] != "#" 
    || v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[1][1] != "#") return true;

    return false;
}

bool ValideMoves(const std::vector<std::vector<std::string>>& v){
    for (const auto& row : v) {
        for (const auto& cell : row) {
            if(cell == "#") return true;
        }
    }
    return false;
}

int AiMove(std::vector<std::vector<std::string>>& v){
    int rand_row;
    int rand_col;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    while(true){

        rand_row = dis(gen);
        rand_col = dis(gen);

        if(v[rand_row][rand_col] == "#") break;
    }

    v[rand_row][rand_col] = "O";

    return 0;
}

int main() {
    std::vector<std::vector<std::string>> Play_field = {{"#","#","#"},{"#","#","#"},{"#","#","#"}};

    PrintField(Play_field);

    while(!winCheck(Play_field) && ValideMoves(Play_field)){
       
        UserInput(Play_field);
        PrintField(Play_field);

        if(winCheck(Play_field) || !ValideMoves(Play_field)) break;

        std::cout<< " " << std::endl;


        AiMove(Play_field);
        PrintField(Play_field);
    }

    std::cout<< " " << std::endl;
    std::cout<< " " << std::endl;
    PrintField(Play_field);
    std::cout<< " " << std::endl;
    std::cout << "Ende of Game" << std::endl;
    std::cout << "Press any Key to Exit" << std::endl;
    
    system("pause");
    
    return 0;
} 

