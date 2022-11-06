#include "BalancedTree.h"

int main() {
    int number;
    cout << "Введите размер дерева: ";
    cin >> number;
    BalancedTree balancedTree(number);
    int choose = -1;
    while (choose != 0) {
        cout << "\nДля вывода дерева - 1"
                "\nНайти кол-во положительных листьев - 2"
                "\nНайти количество узлов с заданным значением - 3"
                "\nПроходом в ширину удвоить значения всех узлов  - 4\n";
        cin >> choose;
        switch (choose) {
            case 1:
                balancedTree.print();
                break;
            case 2:
                cout << "Кол-во положительных узлов: " << balancedTree.countPositiveLeafs() << endl;
                break;
            case 3:
                cout << "Введите значение для поиска: ";
                cin >> number;
                cout << "Кол-во узлов с заданным значеним: " << balancedTree.count(number) << endl;
                break;
            case 4:
                balancedTree.doubleValueOfNodes();
                balancedTree.print();
                break;
            default:
                break;

        }
    }
    return 0;
}