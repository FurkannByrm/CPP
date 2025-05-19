#include "log_analyzer/logAnalyzerWithRegex.hpp"
/*
    Yapilacak optimizasyonlar: 
    Kod Tekrarı: regex_map'teki desenleri işlerken Error Line ve IP için ayrı ayrı işlemler yapıyorsunuz. 
    Bu kod tekrarını azaltmak için daha genel bir yaklaşım benimseyebilirsiniz.

    Constructor'da Fazla İşlem: Constructor içinde çok fazla işlem yapıyorsunuz (definePattern, regex eşleştirme, dosya kaydetme).
    Constructor sadece sınıfın başlangıç durumunu ayarlamalı. İşlemleri ayrı bir metotta (örneğin, analyze()) yapabilirsiniz.

    Daha Temiz Kod: if blokları içinde IP ve Error Line için ayrı işlemler yapıyorsunuz. Bunun yerine, bu işlemleri bir yardımcı
    fonksiyona taşıyabilirsiniz.Range-based for Loop: std::map üzerinde iterasyon yaparken for (const auto& [key, value] : matches_) 
    gibi modern bir yaklaşım kullanabilirsiniz.

    Dosya Adını Parametre Olarak Almak: Dosya adını sabit bir şekilde kodlamak yerine, bu metot bir parametre alabilir. Örneğin:
    void saveLogError(const std::string& filename);
   
    Hata Kontrolü: Dosya okuma sırasında hata kontrolü yapıyorsunuz, bu iyi. Ancak, Analyzer sınıfı içinde de log verisinin geçerli 
    olup olmadığını kontrol edebilirsiniz.
    Daha Modüler Yapı: main fonksiyonunu daha modüler hale getirebilirsiniz. Örneğin, log dosyasını okuma işlemini ayrı bir fonksiyona taşıyabilirsiniz .



    Optimizations to be done: 

    Code Repetition: When processing patterns in regex_map, you perform separate operations for Error Line and IP. 
    You can take a more general approach to reduce this code repetition. 

    Too Much Operation in Constructor: You perform too much operation in Constructor (definePattern, regex matching, file saving). 
    Constructor should only set the initial state of the class. You can perform the operations in a separate method (for example, analyze()). 

    Cleaner Code: You perform separate operations for IP and Error Line inside if blocks. Instead, you can move these operations to a 
    helper function. Range-based for Loop: You can use a modern approach like for (const auto& [key, value] : matches_) when iterating over std::map. 

    Take File Name as Parameter: Instead of hard-coding the file name, this method can take a parameter. For example:
    void saveLogError(const std::string& filename);

    Error Checking: You are checking for errors while reading the file, which is good. However, you can also check whether the log data is 
    valid within the Analyzer class.

    More Modular Structure: You can make the main function more modular. For example, you can move the log file reading process to a separate function.



*/


Analyzer::Analyzer(const std::string& log_text) 
{
    definePattern();
    std::istringstream stream(log_text);
    std::string line;

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
    }



}

void Analyzer::saveLogError(){
    std::ofstream errorFile;
    errorFile.open ("/home/cengo/CPP/STL/utilities/mini_projects/log_analyzer/log/log_error_list.txt");
    for(const auto& error_list : error_line_list_){
        errorFile<<error_list<<"\n";
    }
    errorFile.close();
}


int main(){

 std::ifstream file("/home/cengo/CPP/STL/utilities/mini_projects/log_analyzer/log/example.log");
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
