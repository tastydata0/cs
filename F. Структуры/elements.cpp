#include "rang.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// AtomicNumber,Element,Symbol,AtomicMass,NumberofNeutrons,NumberofProtons,Period,Metal,Type,BoilingPoint
struct Element {
    int atomicNumber, numberOfNeutrons, numberOfProtons, period;
    string element, symbol, type;
    double atomicMass, boilingPoint;
    bool isMetal;

    int getNumberOfElecrons() const
    {
        // Рассчеты на основе законов химмии или физики ...
        return numberOfProtons;
    }

    rang::fg getColor() const
    {
        if (type == "Nonmetal") {
            return rang::fg::blue;
        } else if (type == "Noble Gas") {
            return rang::fg::red;
        } else if (type == "Alkali Metal") {
            return rang::fg::green;
        } else if (type == "Alkaline Earth Metal") {
            return rang::fg::red;
        } else if (type == "Transition Metal") {
            return rang::fg::magenta;
        } else if (type == "Metalloid") {
            return rang::fg::yellow;
        } else if (type == "Metal") {
            return rang::fg::green;
        } else if (type == "Lanthanide") {
            return rang::fg::cyan;
        } else if (type == "Actinide") {
            return rang::fg::yellow;
        } else {
            return rang::fg::reset;
        }
    }
};

void print(const Element& elem)
{
    cout << elem.getColor() << elem.element << " (" << elem.symbol << ")\n\tAtomic mass: " << elem.atomicMass << "\n\tElectrons: " << elem.getNumberOfElecrons() << endl;
    // cout << elem.getColor() << elem.symbol << "\t";
}

int main()
{
    ifstream elementsFile("e2.csv");
    if (!elementsFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string header;
    getline(elementsFile, header);

    vector<Element> table;

    while (true) {
        Element elem;
        string buf;
        if (!getline(elementsFile, buf, ',')) {
            break;
        }

        elem.atomicNumber = stoi(buf);
        getline(elementsFile, elem.element, ',');
        getline(elementsFile, elem.symbol, ',');
        getline(elementsFile, buf, ',');
        elem.atomicMass = stod(buf);
        getline(elementsFile, buf, ',');
        elem.numberOfNeutrons = stoi(buf);
        getline(elementsFile, buf, ',');
        elem.numberOfProtons = stoi(buf);
        getline(elementsFile, buf, ',');
        elem.period = stoi(buf);
        getline(elementsFile, buf, ',');
        elem.isMetal = (buf == "yes");
        getline(elementsFile, elem.type, ',');
        getline(elementsFile, buf); // До '\n'
        if (buf.empty())
            elem.boilingPoint = -1;
        else
            elem.boilingPoint = stod(buf);

        table.push_back(elem);
        // print(elem);
    }

    // ДЗ: Пользователь вводит короткое название элемента, например "Li", а программа выводит информацию об этом элементе
}
