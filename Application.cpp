#include "InfixToPostfix.h"

int main(){
    InfixToPostfix calc;

    cout << "---Binary to Decimal Conversion---\n";
    char binaryNum[] = "10011101";
    int decimalResult = calc.convertBinaryToInt(binaryNum);
    cout << "Binary: " << binaryNum << " -> Decimal: " << decimalResult << endl;
    cout << "----------------------------------\n\n";

    string testExpressions[] ={"A + B - C", "( A + B ) * C", "( A + B) * ( C - D )", "A + ( ( B + C ) * ( E - F ) - G ) / ( H - I)", "A + B * ( C + D) - E / F * G + H"};
    cout << "---Infix to Postfix Conversion Tests---\n";
    for (int i = 0; i < 5; i++){
        calc.setInfix(testExpressions[i]);
        calc.convertToPostfix();

        calc.showInfix();
        calc.showPostfix();
        cout << "----------------------------------\n";
    }
    cout << "\n---Postfix Calculator Test---\n";
    calc.setInfix("10 + 2 * ( 3 + 4)"); 
    calc.convertToPostfix();
    try{
        int result = calc.postfixCalculator();
        cout << "Postfix for calculation: " << calc.getPostfix() << endl;
        cout << "Calculation Result: " << result << endl;
    }
    catch (const exception& err){
        cout << "Error: " << err.what() << endl;
    }
    return 0;
}