#include "functional.h"

void FunctionalHandler::WriteLines(vector<string>& messageList){
    for(const auto& line : messageList) {
        cout << line << endl;
    }
};

string FunctionalHandler::GetUserInput(string messageTitle, string inputRequired = "", string currentValue = ""){
    cout << messageTitle << endl;
    string input{""};
    cin >> input;
    return (
        inputRequired == "" ? input : (input == inputRequired ? inputRequired : currentValue));
};

string FunctionalHandler::get_PolicyName(){
    return PolicyName; 
};

void FunctionalHandler::set_PolicyName(string value){
    PolicyName = value;
};

FunctionalHandler::Action FunctionalHandler::DoNothing(){
    auto emptyFunction = [](){};
    return emptyFunction;
};

void FunctionalHandler::ExecuteAction(Action& action){
    try
    {
        action();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
};

void FunctionalHandler::ExecuteAction(Action& action, Condition& condition){
    try
    {
        if (condition()){
            action();
        } 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
};

void FunctionalHandler::ExecuteAction(Action& action, Condition& condition, Action& actionElse){
    try
    {
        if (condition()){
            action();
        } else {
            actionElse();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
};

void FunctionalHandler::ExecuteAction(Action& action, Action& actionIfException){
    try
    {
        action();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        actionIfException();
    }    
};

void FunctionalHandler::ExecuteActions(vector<Action>& actions){
    try
    {
        for(const Action& action : actions){
            action();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
};

void FunctionalHandler::ExecuteActions(vector<Action>& actions, Condition& condition){
    try
    {        
        if (condition()){
            for(const Action& action : actions){
                action();
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
};

void FunctionalHandler::RepeatActionIf(Action& action, Condition& condition){
    try
    {        
        while (condition()){
            action();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
};

void FunctionalHandler::ExecuteParallelActions(vector<Action>& actions){
    for_each(
        execution::par, actions.begin(), actions.end(), [](Action& action) {
            action();
        }
    );
};