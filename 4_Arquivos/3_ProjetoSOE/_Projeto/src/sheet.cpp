/*
Função onde estão as funções relacionadas ao Google Sheet.
*/

#include "../inc/sheet.hpp"

std::vector<std::string> exec_int(const char* cmd) { // leitura da saída do terminal de determinada função
    std::array<char, 128> buffer;
    std::vector<std::string>result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        std::string tmp = buffer.data();
        if(tmp == "\n"){
            continue;
        }
        std::replace(tmp.begin(), tmp.end(), '\n', '\0');
        result.push_back(tmp);
    }
    // result.push_back("PAS1234");
    // result.push_back("ABC3214");
    // result.push_back("CBA6547");
    return result;
}

std::vector<std::string> get_sheet(std::string sheet_id, std::string range) {
    std::vector<std::string> a;
    // TODO: mudar os caminhos para os caminhos relativos e absolutos
    a = exec_int(". /home/guilherme/faculdade/so_embarcados/Sistemas-Embarcados/env/bin/activate && python python/sheet.py");
    return a;
}

// compara se existe a placa na lista de plates
bool compare_sheet_plate(std::vector<std::string> plates, std::string plate) {
    if (std::find(plates.begin(), plates.end(), plate) != plates.end()) {
        return true;
    }
    return false;
}
