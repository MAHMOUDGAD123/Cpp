#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



class clsCalculator
{
private:

	enum en_Operations
	{
		eNoOp = 0,
		eCanLstOp = 1,
		eAdd = '+',
		eSub = '-',
		eMul = '*',
		eDiv = '/',
		eMod = '%'
	};

	en_Operations _Op = eNoOp;
	double _UserInput = 0, _Result = 0, _PrevResult = 0;
	bool _DivBy0 = false, _Mod0 = false;
	vector <double> _vResultsHistory;
	vector<string> _vOperationsHistory;

	string To_String(double N)
	{
		stringstream ss;
		string Str;

		ss << N;
		ss >> Str;
		return Str;
	}

	string OperationToString()
	{
		return To_String(_PrevResult) + " " + char(_Op) + " " + To_String(_UserInput) + " = " + To_String(_Result);
	}

	// Messages
	void No_OpMSG()
	{
		cout << "\n- No Operation!\n";
	}

	void AddMSG()
	{
		cout << "\n- Result After Adding " << _UserInput << " = " << _Result << "\n";
	}

	void SubMSG()
	{
		cout << "\n- Result After Subtracting " << _UserInput << " = " << _Result << "\n";
	}

	void MulMSG()
	{
		cout << "\n- Result After Multiply By " << _UserInput << " = " << _Result << "\n";
	}

	void DivMSG()
	{
		if (_DivBy0)
		{
			cout << "\n- You Can't Divide By Zero\n";
			return Clear();
		}
		else
			cout << "\n- Result After Dividing By " << _UserInput << " = " << _Result << "\n";
	}

	void ModMSG()
	{
		if (_Mod0)
		{
			cout << "\n- Result Is Undefined\n";
			return Clear();
		}
		else
			cout << "\n- Result After Mod " << _UserInput << " = " << _Result << "\n";
	}

	void CancelLastOpMSG()
	{
		cout << "\n- Result After Canceling Last Operation = " << _Result << "\n";
	}


public:

	// Operations
	void Clear()
	{
		_Op = en_Operations::eNoOp;
		_Result = _PrevResult = _UserInput = 0;
		_DivBy0 = _Mod0 = false;
		_vResultsHistory.clear();
	}

	void ClearHistory()
	{
		_vOperationsHistory.clear();
	}

	void CancelLastOperation()
	{
		if (_vResultsHistory.size() > 1)
		{
			_Op = en_Operations::eCanLstOp;
			_vResultsHistory.pop_back();
			_Result = _vResultsHistory.back();
			_vOperationsHistory.pop_back();
		}
		else
			return Clear();
	}

	void Add(double N)
	{
		_Op = en_Operations::eAdd;
		_PrevResult = _Result;
		_UserInput = N, _Result += N;
		_vResultsHistory.push_back(_Result);
		_vOperationsHistory.push_back(OperationToString());
	}

	void Sub(double N)
	{
		_Op = en_Operations::eSub;
		_PrevResult = _Result;
		_UserInput = N, _Result -= N;
		_vResultsHistory.push_back(_Result);
		_vOperationsHistory.push_back(OperationToString());
	}

	void Mul(double N)
	{
		_Op = en_Operations::eMul;
		_PrevResult = _Result;
		_UserInput = N, _Result *= N;
		_vResultsHistory.push_back(_Result);
		_vOperationsHistory.push_back(OperationToString());
	}

	void Div(double N)
	{
		_Op = en_Operations::eDiv;
		if (N != 0)
		{
			_PrevResult = _Result;
			_UserInput = N, _Result /= N;
			_vResultsHistory.push_back(_Result);
			_vOperationsHistory.push_back(OperationToString());
		}
		else
			_DivBy0 = true;
	}

	void Mod(double N)
	{
		_Op = en_Operations::eMod;
		if (N != 0)
		{
			_PrevResult = _Result;
			_UserInput = N;
			_Result -= N * (long long)(_Result / N);
			_vResultsHistory.push_back(_Result);
			_vOperationsHistory.push_back(OperationToString());
		}
		else
			_Mod0 = true;
	}

	// Print Results
	void PrintResult()
	{
		switch (_Op)
		{
		case en_Operations::eNoOp:
			return No_OpMSG();

		case en_Operations::eAdd:
			return AddMSG();

		case en_Operations::eSub:
			return SubMSG();

		case en_Operations::eMul:
			return MulMSG();

		case en_Operations::eDiv:
			return DivMSG();

		case en_Operations::eMod:
			return ModMSG();

		case en_Operations::eCanLstOp:
			return CancelLastOpMSG();
		}
	}

	double GetFinalResult()
	{
		return _Result;
	}

	void PrintHistory()
	{
		if (_vOperationsHistory.empty())
		{
			cout << "\nNo History :-(\n";
			return;
		}
		cout << "\n============================\n";
		cout << "Operations History:\n";
		cout << "-------------------\n\n";
		for (const string S : _vOperationsHistory)
			cout << "- " << S << '\n';
		cout << "\n============================\n";
	}

};


int main(void)
{
	clsCalculator Calc;

	Calc.Add(10);
	Calc.PrintResult();

	Calc.Mul(10);
	Calc.PrintResult();

	Calc.Div(2);
	Calc.PrintResult();

	Calc.Mul(10);
	Calc.PrintResult();

	Calc.Mul(50);
	Calc.PrintResult();

	Calc.PrintHistory();

	Calc.ClearHistory();

	Calc.PrintHistory();


	return 0;
}