#include "mainProcess.h"
#include <json/json.h>
#include <fstream>

void MainProcess::ExecuteProcess(char opt, char tip_pro, char sel, string mesa_sel){
    _opt = opt;
    _tip_pro = tip_pro;
    _sel = sel;
    _mesa_sel = mesa_sel;

    Json::Value settings;
    std::ifstream settings_file("appSettings.json", std::ifstream::binary);
    settings_file >> settings;

    Json::Value _endPointSet = _opt == ProcesarPrimeraV ? settings["Api"]["First"] : settings["Api"]["Second"];

    cout << _endPointSet["Title"] << endl;

}