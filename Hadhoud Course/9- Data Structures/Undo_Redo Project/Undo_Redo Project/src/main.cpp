#include <iostream>
#include "../Header Files/stack.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }



template<typename _Ty>
class Undo_Redo
{
private:
	MG::stack<_Ty> _History; // holds the values after _Set_value() or redo()
	MG::stack<_Ty> _Temp; // holds the poped values after Undo()

public:
	constexpr Undo_Redo() = default;

	// no copy or move 
	// -----------------------------------------------
	Undo_Redo(const Undo_Redo&) = delete;
	Undo_Redo(Undo_Redo&&) = delete;
	Undo_Redo& operator=(const Undo_Redo&) = delete;
	Undo_Redo& operator=(Undo_Redo&&) = delete;
	// -----------------------------------------------

	// set & get
	// setting a new value make (_Temp) empty
	constexpr void _Set_Value(const _Ty& _val) // takes lvalue ref
	{
		_Temp.~stack(); // clear _Temp
		_History.push(_val);
	}
	constexpr void _Set_Value(_Ty&& _val) // takes rvalue ref
	{
		_Temp.~stack(); // clear _Temp
		_History.push(std::move(_val));
	}

	constexpr _Ty _Get_Value() const
	{
		// return an empty temporary object if _History is empty
		// to avoid error
		return (_History.empty()) ? _Ty() : _History.top();
	}

	__declspec(property(get = _Get_Value, put = _Set_Value)) _Ty Value;


	constexpr void undo()
	{
		if (!_History.empty()) {
			// move/push the top() of _History to _Temp
			_Temp.push(std::move(_History.top()));
			_History.pop(); // pop it
		}
	}

	constexpr void redo()
	{
		if (!_Temp.empty()) {
			// move/push the last poped value after undo()
			_History.push(std::move(_Temp.top()));
			_Temp.pop(); // pop it
		}
	}


};



MAIN_BEGIN

Undo_Redo<std::string> Test;

std::cout << "\nValue Before Set = " << Test.Value;
Test.Value = "1";
std::cout << "\nValue After Set = " << Test.Value;
Test.Value = "2";
std::cout << "\nValue After Set = " << Test.Value;
Test.Value = "3";
std::cout << "\nValue After Set = " << Test.Value;
Test.Value = "4";
std::cout << "\nValue After Set = " << Test.Value;

Test.undo();
std::cout << "\nValue After undo() = " << Test.Value;
Test.undo();
std::cout << "\nValue After undo() = " << Test.Value;
Test.undo();
std::cout << "\nValue After undo() = " << Test.Value;
Test.undo();
std::cout << "\nValue After undo() = " << Test.Value;
Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;
Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;
Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;
Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;
Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;

Test.Value = "5";
std::cout << "\nValue After Set (_Temp is empty) = " << Test.Value;

Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;
Test.redo();
std::cout << "\nValue After redo() = " << Test.Value;

std::cout << "\n\n";

MAIN_END