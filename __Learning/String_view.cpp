#include <iostream>
#include <string>
#include <string_view>
#include <new>


// to watch heap allocation
static uint16_t alloc_count(0);
void* operator new(size_t size) {
	if (size <= 0) ++size;
	++alloc_count;
	std::cout << "Allocating " << size << " Bytes\n";

	if (void* ptr = malloc(size)) return ptr;
	return nullptr;
}


void sprint(const char* const sptr) {
	std::cout << "\nUsing char pointer\n";
	std::cout << "S = " << sptr << std::endl;
}

void sprint(std::string_view SV) {
	std::cout << "\nUsing string_view\n";
	std::cout << "S = " << SV << std::endl;
}

void sprint(const std::string& S) {
	std::cout << "\nUsing string\n";
	std::cout << "S = " << S << std::endl;
}


int main() {
	//std::string S("Mahmoud Gad"); // 1

	// 3 memory allocations
	//std::string firstN(S.substr(0, 7)); // 1
	//std::string lastN(S.substr(8, 3)); // 1

	// 1 memory allocation
	//std::string_view firstN(S.c_str(), 7);
	//std::string_view lastN(S.c_str() + 8, 3);


	// 0 memory allocation
	const char* const S("Mahmoud Gad");
	std::string_view firstN(S, 7);
	std::string_view lastN(S + 8, 3);



	sprint(S);
	sprint(firstN);
	sprint(lastN);


	return 0;
}
