
#include "../inc/rasp.hpp"

using namespace cv;

std::string exec(const char *cmd)
{ // leitura da saída do terminal de determinada função
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

bool capture_img(Mat frame)
{
	std::string plate1, plate2;
	std::string plate;
	imwrite("./WebCamImage.png", frame); // salva o frame atual no arquivo WebCamImage.png para ser lido pelo openalpr
    system("clear");
    std::cout << "Presence Detected " << std::endl;
    plate = exec("alpr -c br -p @@@#### -n 2 ./WebCamImage.png"); // salva a saída do comando de terminal do OpenALPR em uma variável
    if (strlen(plate.c_str()) > 25)
    { // pega as letras e numeros da placa caso alguma seja reconhecida
        std::string plateL(plate, 24, 3);
        plateL[3] = '\0';
        std::string plateN(plate, 27, 4);
        plateN[4] = '\0';
        std::cout << plate << std::endl;
        std::string plateR(plate, 8, 1);
        plateR[1] = '\0';
        plate1 = plateL + plateN;
        //std::cout << plateR << std::endl;
        if (plateR != "1")
        { // se houverem duas possibilidades de placa, salva a segunda em outra variável
            std::string plateL2(plate, 77, 3);
            plateL2[3] = '\0';
            std::string plateN2(plate, 80, 4);
            plateN2[4] = '\0';
            std::cout << plate1 << std::endl;
            std::cout << plate2 << std::endl;
			plate2 = plateL + plateN;
        }
    }
    else{ // se não reconhece alguma placa, mostra somente o output do comando de terminal
        std::cout << plate << std::endl;
	}
	std::vector<std::string>plates = get_sheet("01930123019230192301923091", "A2:A5");
	if(compare_sheet_plate(plates, plate1)){
		std::cout << compare_sheet_plate(plates, plate1) << std::endl;
		return 1;
	}
	if(compare_sheet_plate(plates, plate2)){
		std::cout << compare_sheet_plate(plates, plate2) << std::endl;
		return 1;
	}
	return 0;
}
