#ifndef FUNCTIONALHANDLER_H
#define FUNCTIONALHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <execution>
#include "constants.h"
using namespace std;

class FunctionalHandler
{
    typedef function<void()> Action;
    typedef function<bool()> Condition;
    public:
        void WriteLines(vector<string>& messageList);
        string GetUserInput(string messageTitle, string inputRequired, string currentValue);
        string get_PolicyName();
        void set_PolicyName(string value);        
        Action DoNothing();
        void ExecuteAction(Action& action);
        void ExecuteAction(Action& action, Condition& condition);
        void ExecuteAction(Action& action, Condition& condition, Action& actionElse);
        void ExecuteAction(Action& action, Action& actionIfException);
        void ExecuteActions(vector<Action>& actions);
        void ExecuteActions(vector<Action>& actions, Condition& condition);
        void RepeatActionIf(Action& action, Condition& condition);
        void ExecuteParallelActions(vector<Action>& actions);
    private:
        string PolicyName{PROPAGATE_POLICY_NAME};
};

#endif