//Libraries
#include <iostream>
#include <string>

//Program Headers
#include "type.h"
#include "symbol.h"
#include "scope.h"

//File Header
#include "checker.h"

using namespace std;

//Scope Pointers
Scope* GLO_SCOPE = new Scope(); //Pointer to global scope
Scope* CUR_SCOPE = GLO_SCOPE; //Pointer to current scope (initialized to the global scope by default)


void openScope(){
    cout << "Open Scope\tEnclosing(" << CUR_SCOPE << ")\tNew(";
    Scope newScope(CUR_SCOPE); //Initialize new scope instance with current scope as the parent
    CUR_SCOPE = &newScope; //Set current scope to point to newest scope
	cout << CUR_SCOPE << ")" << endl;
}

void closeScope(){
    cout << "Close scope" << endl;
    CUR_SCOPE = CUR_SCOPE->getParent();
}

void printArrayDec(string name, unsigned ind, int spec){
    cout << "Declare array " << name << " with ind " << ind << " and spec " << spec << endl;
}

void printScalarDec(string name, unsigned ind, int spec){
    cout << "Declare scalar " << name << " with ind " << ind << " and spec " << spec << endl;
}

void printVarDec(string name, unsigned ind, int spec){
    cout << "Declare variable " << name << " with ind " << ind << " and spec " << spec << endl;
}

void printFunDec(string name, unsigned ind, int spec){
    cout << "Declare function " << name << " with ind " << ind << " and spec " << spec << endl;
}

void printSymUse(){
    cout << "Used symbol" << endl; //TODO: get this to say what symbol was used.
}

void declareArray(string name, int spec, unsigned ind, unsigned length){
    Type t(ARRAY, spec, ind);
    t.length = length;
    Symbol sym(name, t);
	cout << "Declare Array " << name << " with ind " << ind << " and spec " << spec << endl;
}

void declareVar(string name, Type t){
    Symbol sym(name, t);
	cout << "Declare Variable " << name << "with type " << t.get_kind_string() << endl;
}


