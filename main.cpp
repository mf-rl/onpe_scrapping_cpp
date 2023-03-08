#include <iostream>
#include <locale.h>
#include <vector>
#include "constants.h"
#include "messages.h"
#include "functional.h"
#include "screens.h"
#include "mainProcess.h"

using namespace std;

int main(){
    string opt{};
    string sel{};
    string tip_pro{};
    string mesa_sel{};

    function optNotValid = [&opt]() -> bool { return (opt[0] != ProcesarPrimeraV && opt[0] != ProcesarSegunvaV); };
    function tipProNotValid = [&tip_pro]() -> bool { return (tip_pro[0] != ProcesoTotal && tip_pro[0] != ProcesoParcial); };
    function selNotValid = [&sel]() -> bool { return (sel[0] != ProcesoUbigeo && sel[0] != ProcesoMesa); };
    function tableNotValid = [&mesa_sel]() -> bool { return (mesa_sel != "" && sizeof(mesa_sel[0]) > 6); };
    function tipProIsPartial = [&tip_pro]() -> bool { return tip_pro[0] == ProcesoParcial; };
    function selIsTable = [&sel]() -> bool { return sel[0] == ProcesoMesa; };
    function selIsUbigeo = [&sel]() -> bool { return sel[0] == ProcesoUbigeo; };
    function tableIsEmpty = [&mesa_sel]() -> bool { return mesa_sel == ""; };

    FunctionalHandler fhandler;
    MainProcess mainProcess;

    function readInput = [&fhandler](string& selectedOption, vector<string> title){
        fhandler.WriteLines(title);
        selectedOption = fhandler.GetUserInput(WAIT_FOR_ANSWER, "", "");
    };

    function getInputOptions = [&readInput, &opt](){
        return readInput(opt, optionsScreen);
    };

    function getInputTipPro = [&readInput, &tip_pro](){
        return readInput(tip_pro, tipProScreen);
    };

    function getInputSel = [&readInput, &sel](){
        return readInput(sel, selParScreen);
    };

    function getInputUbi = [&readInput, &mesa_sel](){
        return readInput(mesa_sel, tableNumberScreen);
    };

    function showTipProPartialScreen = [&fhandler, &getInputSel, &selNotValid](){
        fhandler.WriteLines(printSeparator);
        fhandler.RepeatActionIf(getInputSel, selNotValid);
    };

    function showTableNumberScreen = [&fhandler, &getInputSel, &tableIsEmpty](){
        fhandler.WriteLines(printSeparator);
        fhandler.RepeatActionIf(getInputSel, tableIsEmpty);
    };

    function showUbigeoScreen = [&fhandler, &getInputUbi, &tableNotValid]{
        fhandler.WriteLines(printSeparator);
        fhandler.RepeatActionIf(getInputUbi, tableNotValid);
    };
    
    fhandler.WriteLines(titleScreen);
    fhandler.RepeatActionIf(getInputOptions, optNotValid);
    fhandler.RepeatActionIf(getInputTipPro, tipProNotValid);
    fhandler.ExecuteAction(showTipProPartialScreen, tipProIsPartial);
    fhandler.ExecuteAction(showTableNumberScreen, selIsTable);
    fhandler.ExecuteAction(showUbigeoScreen, selIsUbigeo);

    mainProcess.ExecuteProcess(opt[0], tip_pro[0], sel[0], mesa_sel);

    fhandler.WriteLines(processFinishedScreen);
    cin.get();

    return 0;
}