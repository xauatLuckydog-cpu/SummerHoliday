#include <iostream>
#include <string>
#include <stdexcept>
#define MIN_VALUE 1e-8
using namespace std;

double divideNumbers(double numerator, double denominator) {
	if (abs(denominator) < MIN_VALUE) {
		throw invalid_argument("Denominator cannot be 0.");
	}
	return numerator / denominator;
}

//int main() {
//	try {
//		cout << divideNumbers(5.0, 0) << endl;
//	}
//	catch(const invalid_argument& exception){
//		cout << "Exception caught:" << exception.what() << endl;
//	}
//	
//}