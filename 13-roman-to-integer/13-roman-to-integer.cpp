class Solution {
public:
    map<string,int> value;
    int romanToInt(string s) {
        int total = 0;
       
        
        value.insert(pair<string,int>("IV",4));
        value.insert(pair<string,int>("IX",9));
        value.insert(pair<string,int>("XL",40));
        value.insert(pair<string,int>("XC",90));
        value.insert(pair<string,int>("CD",400));
        value.insert(pair<string,int>("CM",900));
        
        for(int i = 0; i < s.length();++i){
            switch(s[i]){
                case 'I':
                    if(i+1 == s.length()){
                        total = total + 1;
                        cout << "total1 " << total << "\n";
                    }
                    else if(value.count(std::string(1,s[i]) + std::string(1,s[i+1])) == 0){
                        total = total + 1; //error
                        //cout << "total2 " << total << "\n";
                    }
                    else{
                        total = total + value.at(std::string(1,s[i]) + std::string(1,s[i+1]));
                        //cout << value.at((std::string(1,s[i])) + std::string(1,s[i+1])) << "\n";
                        //cout << "total3 " << total << "\n";
                        i++;
                    } 
                    break;
                case 'V':
                    total = total + 5;
                    break;
                case 'X':
                     if(i+1 == s.length()){
                        total = total + 10;
                        //cout << "total1 " << total << "\n";
                    }
                    else if(value.count(std::string(1,s[i]) + std::string(1,s[i+1])) == 0){
                        total = total + 10; 
                        //cout << "total2 " << total << "\n";
                    }
                    else{
                        total = total + value.at(std::string(1,s[i]) + std::string(1,s[i+1]));
                        //cout << value.at((std::string(1,s[i])) + std::string(1,s[i+1])) << "\n";
                       // cout << "total3 " << total << "\n";
                        i++;
                    } 
                    break;
                case 'L':
                    total = total + 50;
                    break;
                case 'C':
                     if(i+1 == s.length()){
                        total = total + 100;
                        //cout << "total1 " << total << "\n";
                    }
                    else if(value.count(std::string(1,s[i]) + std::string(1,s[i+1])) == 0){
                        total = total + 100; 
                        //cout << "total2 " << total << "\n";
                    }
                    else{
                        total = total + value.at(std::string(1,s[i]) + std::string(1,s[i+1]));
                        //cout << value.at((std::string(1,s[i])) + std::string(1,s[i+1])) << "\n";
                        //cout << "total3 " << total << "\n";
                        i++;
                    } 
                    break;
                case 'D':
                    total = total + 500;
                    break;
                case 'M':
                    total = total + 1000;
                    break;
            } 
        }
        return total;
    }
    
};