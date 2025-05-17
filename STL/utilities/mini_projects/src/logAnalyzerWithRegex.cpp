#include "utilities/logAnalyzerWithRegex.hpp"



Analyzer::Analyzer(const std::string& log_text) 
{
    definePattern();
    // std::cout<<log_text<<std::endl;
    std::istringstream stream(log_text);
    std::string line;
    

    //Version1 vector regex:
    // for(const auto& pattern_array : pattern_){
    //     auto state_begin = std::sregex_iterator(log_text.begin(), log_text.end(), pattern_array);
    //     auto state_end   = std::sregex_iterator();
    //     // std::cout<<"Found "<<std::distance(state_begin,state_end)<<" state"<<"\n";
    //     if(std::smatch match; std::regex_search(log_text, match, pattern_array)){

    //         matches_[match.str()] = std::distance(state_begin,state_end);
    //     }
        
    // }
    
    //Version2 std::map regex:
    for(const auto& map: regex_map){
        auto state_begin = std::sregex_iterator(log_text.begin(), log_text.end(), map.second);
        auto  state_end  = std::sregex_iterator();
        if(std::smatch match; std::regex_search(log_text, match, map.second)){
            matches_[map.first] = std::distance(state_begin,state_end);
            if(map.first == "IP" ){
                while(state_begin!=state_end){
                 match = *state_begin;
                 //same Ip adress is unallowable
                 if(std::find(ip_list_.begin(),ip_list_.end(),match.str()) == ip_list_.end()){
                    ip_list_.push_back(match.str());
                 }
                ++state_begin;
             }
            }
            else if(map.first == "Error Line"){
                while (state_begin!=state_end)
                {
                    match = *state_begin;
                    error_line_list_.push_back(match.str());
                    ++state_begin;
                }
                
            }            
        }
    }


    viewMatches();
    saveLogError();
}


void Analyzer::definePattern()
{
    // pattern_.push_back(std::regex(R"(^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])$)"));
    // pattern_.push_back(std::regex(R"(\[ERROR\])"));
    // pattern_.push_back(std::regex(R"(\[INFO\])"));

    regex_map["Error"] = std::regex(R"(\[ERROR\])");
    regex_map["Error Line"]= std::regex(R"(^.*\[ERROR\].*(?:\n[ \t].*)*)", std::regex_constants::multiline);
    regex_map["Info"]  = std::regex(R"(\[INFO\])");
    regex_map["IP"]    = std::regex(R"(\b(\d{1,3}\.){3}\d{1,3}\b)");

}

void Analyzer::viewMatches()const{

    for(std::map<std::string, int>::const_iterator it = matches_.begin();it!= matches_.end(); it++){
        std::cout<<it->first<<" statement used "<<it->second<<" times."<<"\n";
        if(it->first == "IP"){
            std::cout<<"Ip adresses on the processing: "<<"\n";
            for(const auto& ip_list : ip_list_){
                std::cout<<ip_list<<"\n";
            }
        }
        // if(it->first == "Error Line"){
        //     std::cout<<"Error Line List:"<<"\n";
        //     for(const auto& error_list : error_line_list_)
        //     {
        //         std::cout<<error_list<<"\n";
        //     }
        // }

    }

    // for(const auto& view : matches_){
    //     std::cout<<view.first<<" Used "<<view.second<<" times"<<"\n";
    // }

}

void Analyzer::saveLogError(){
    std::ofstream errorFile;
    errorFile.open ("/home/cengo/CPP/STL/utilities/mini_projects/log/log_error_list.txt");
    for(const auto& error_list : error_line_list_){
        errorFile<<error_list<<"\n";
    }
    errorFile.close();
}


int main(){

 std::ifstream file("/home/cengo/CPP/STL/utilities/mini_projects/log/example.log");
    if(!file.is_open()){
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string log((std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>());    
    file.close();
    Analyzer analyzer(log);

    return 0;
}