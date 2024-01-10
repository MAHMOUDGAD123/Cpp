#include <iostream>
#include <map>
#include <vector>
#include "../DS/Map.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }


using C_Tree = std::_Tree < std::_Tmap_traits<int, std::string, std::less<int>, std::allocator<std::pair<const int, std::string>>, false>>;
using C_Map = std::map<int, std::string>;

using Test_Tree = MG::_Tree<MG::_Map_Traits<int, std::string>>;
using Test_Pair = MG::pair<const int, std::string>;
using Test_List = std::initializer_list<Test_Pair>;
using Tree_Iter = Test_Tree::const_iterator;

template<class _Tree>
static void T_Print(const _Tree& Tree) noexcept
{
	std::cout << "\n";
	if (Tree.empty()) {
		std::cout << "Empty :-(";
	}
	else {
		for (const auto& [key, val] : Tree)
			std::cout << key << " - " << val << '\n';
		std::cout << "-> Size = " << Tree.size() << '\n';
	}
	std::cout << "\n";
}





MAIN_BEGIN

Test_List list{ { 20, "A" }, { 15, "B" }, { 10, "C" }, { 30, "X" }, { 40, "W" }, { 50, "P" }, { 60, "V" }, { 70, "G" } };
Test_Tree Tree{ list };
Tree_Iter _B = Tree.begin();
Tree_Iter _E = Tree.end();

C_Map C_Map{ { 20, "A" }, { 15, "B" }, { 10, "C" }, { 30, "X" }, { 40, "W" } };

//T_Print(C_Map);
//
//std::cout << C_Map[200];
//
//T_Print(C_Map);

std::cout << "Before Extracting:\n";
T_Print(Tree);

MG::pair<Test_Tree::Node_Ptr, bool> _Victim = Tree.extract(10);
//MG::pair<Test_Tree::Node_Ptr, bool> _Victim = Tree.extract(_E); // no extraction will happen here

std::cout << "After Extracting:\n";
T_Print(Tree);

if (_Victim._Second) {
	Tree.insert(_Victim._First->_Data);
}

std::cout << "After Insert Again:\n";
T_Print(Tree);

MAIN_END