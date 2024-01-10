#include <iostream>
#include <queue>
#include "../DS/queue.h"
#include "../DS/iqueue.h"
#include "../DS/deque.h"
#include "../DS/vector.h"

#define MAIN_BEGIN int main(){
#define MAIN_END }





MAIN_BEGIN

std::initializer_list<int> list{ 10,27,3,7,5,16,1 };

std::priority_queue<int, std::deque<int>, std::greater<int>> PQ1(list.begin(), list.end());
std::priority_queue<int, std::deque<int>, std::less<int>> PQ2(list.begin(), list.end());

std::cout << "PQ1 ->";
while (!PQ1.empty()) {
	std::cout << " - " << PQ1.top();
	PQ1.pop();
}

std::cout << std::endl;

std::cout << "PQ2 ->";
while (!PQ2.empty()) {
	std::cout << " - " << PQ2.top();
	PQ2.pop();
}

std::cout << std::endl;


//MG::queue<int> Q;
//
//Q.print();
//
//Q.push(1);
//Q.push(2);
//Q.push(3);
//
//Q.print();
//
//Q.pop();
//
//Q.print();
//
//Q = {};
//
//Q.print();
//
//Q.push(7);
//Q.push(11);
//
//Q.print();
//
//Q.pop();
//Q.pop();
//Q.pop();
//Q.pop();
//Q.push(11);
//Q.push(11);
//Q.push(11);
//
//Q.print();

MAIN_END