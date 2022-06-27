class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0){
            return false;
        }
        std::vector<string> stack = {};
        for(int i = 0; i < s.length();++i){
            string eval {s[i]};
            if (eval == "["){
                stack.push_back(eval);
            } 
            else if (eval == "("){
                stack.push_back(eval);
            } 
            else if (eval == "{"){
                stack.push_back(eval);
            } 
            else if (stack.size() == 0){
                return false;
            }
            else if (eval == "]"){
                if (stack.back() != "["){
                    return false;
                }
                stack.pop_back();
            }
            else if (eval == ")"){
                if (stack.back() != "("){
                    return false;
                }
                stack.pop_back();
            }
            else if (eval == "}"){
                if  (stack.back() != "{"){
                    return false;
                }
                stack.pop_back();
            }
        }
        if(stack.size() == 0){
            return true;
        }
        return false;
    }
};