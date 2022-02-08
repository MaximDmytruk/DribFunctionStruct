/*1. Створіть структуру, що описує простий дріб. Реалізуйте арифметичні операції з дробами: суму, різницю, множення, ділення.
Врахувати можливість скорочення дробів і перетворення з неправильного дробу на простий.*/

#include <iostream>
using namespace std;
struct Drib         //Структура дробу
{
    int chis;   //зміна для чисельника
    int znam;   //зміна для знаменника 

    void input() {  //ф-ція вводу елемннтів дробу
        cout << "Enter numerator = ";
        cin >> chis;        //просимо ввестич чисельника
        cout << "Enter denominator = ";
        cin >> znam;        //просимо ввести знакменник 
    }
};
void printDrib(int numer, int denom) {  //Ф-ція для виведення на екран дробу
    int integ;     //Для цілих чисел 
    if (numer > denom)                  // Умова якщо дріб неправильний - далі переводимо та виводимо 
    {
        integ = numer / denom;                      //дізнаємось к-сть цілих чисел 
        if (numer % denom == 0) {                      //якщо після ділення чисельника/знаменник немає інших елементів 
            cout << integ << endl;                          //виводимо тільки число 
        }
        else cout << integ << ".(" << numer - denom << "/" << denom << ")" << endl; //у іншому випадку виводимо всі елементи, цілі та дріб
    }
    else {
        cout << numer << "/" << denom << endl;  // якщо дріб правильний - виводимо на екран 
    }

}
void sumDrib(Drib one, Drib two) {      //Ф-ція сума дробів
    int sum = 0;    //майбутня відповідь            

    if (one.znam == two.znam) {                 //Якщо знаменники однакові 
        sum = one.chis + two.chis;                          //сумуємо чисельники

        for (int i = two.znam; i > 1; i--)                      //цикл для скоротчення дробів(Перераховуємо всі елементи на які можемо поділити)
        {
            if (sum % i == 0 && one.znam % i == 0)                      //умова при якій чисельник та знаменик діляться без остачі 
            {
                sum = sum / i;
                one.znam = one.znam / i;                        //ділимо дріб на це число 
            }
        }
        printDrib(sum, one.znam);                         //Виводимо дріб на екран 
    }
    else {                                  //Якщо знаменники різні 
        int z1 = one.znam, z2 = two.znam;       //зміна для збереження знаменників
        one.chis = one.chis * z2;
        one.znam = one.znam * z2;           //зводимо до однакового знаменника
        two.chis = two.chis * z1;
        two.znam = two.znam * z1;

        sum = one.chis + two.chis;          //сумуємо чисельники

        for (int i = two.znam; i > 1; i--)      //цикл для скорочення дробу(Дії описував раніше)
        {
            if (sum % i == 0 && one.znam % i == 0)
            {
                sum = sum / i;
                one.znam = one.znam / i;
            }
        }
        printDrib(sum, one.znam);           //Виводимо на екран відповідь 
    }
}
void diffDrib(Drib one, Drib two) {         //Ф-ція для різниці дробів

    int diff = 0;            //зміна для відповіді

    if (one.znam == two.znam) {                 //Якщо знаменники однакові 
        diff = one.chis - two.chis;             //віднімаємо чисельники

        for (int i = two.znam; i > 1; i--)      //цикл для скорочення дробу(Дії описував раніше)
        {
            if (diff % i == 0 && one.znam % i == 0)
            {
                diff = diff / i;
                one.znam = one.znam / i;
            }
        }
        printDrib(diff, one.znam);          //Виводимо на екран відповідь 
    }
    else {                                  //Якщо знаменники різні
        int z1 = one.znam, z2 = two.znam;   //зміна для збереження знаменників
        one.chis = one.chis * z2;
        one.znam = one.znam * z2;
        two.chis = two.chis * z1;           //зводимо до однакового знаменника
        two.znam = two.znam * z1;

        diff = one.chis - two.chis;         //дізнаємось різницю

        for (int i = two.znam; i > 1; i--)                  //цикл для скорочення дробу(Дії описував раніше)
        {
            if (diff % i == 0 && one.znam % i == 0)
            {
                diff = diff / i;
                one.znam = one.znam / i;
            }
        }
        printDrib(diff, one.znam);      //друкуємо наш дріб
    }
}
void multDrib(Drib one, Drib two) {     //Ф-ція для добутку дробів 
    int chisD = one.chis * two.chis;       //по правилам множення чисельник*чисельник, знаменник *знаменник.
    int znamD = one.znam * two.znam;
    for (int i = znamD; i > 1; i--)
    {
        if (chisD % i == 0 && znamD % i == 0)   //цикл для скорочення дробу(Дії описував раніше)
        {
            chisD = chisD / i;
            znamD = znamD / i;
        }
    }
    printDrib(chisD, znamD);         //друкуємо наш дріб
}
void divisionDrib(Drib one, Drib two) {         //Функція ділення дробів    
    int chisD = one.chis * two.znam;        //по правилам ділення знаменника*чисельник іншого дробу
    int znamD = one.znam * two.chis;
    for (int i = znamD; i > 1; i--)             //цикл для скорочення дробу(Дії описував раніше)
    {
        if (chisD % i == 0 && znamD % i == 0)
        {
            chisD = chisD / i;
            znamD = znamD / i;
        }
    }
    printDrib(chisD, znamD);        //Виводимо відповідь 
}
int main()
{
    cout << "Drib #1:" << endl;     
    Drib one;           //Дріб 1 
    one.input();        //Просимо ввести дані 1дробу
    cout << "Drib #2:" << endl;
    Drib two;           //Дріб 2
    two.input();        //просимо ввести дані 2 дробу

    cout << endl;
        
    cout << "Sum = ";   //сума дробів 
    sumDrib(one, two);  //викликаємо ф-цію суми дробів 
    cout << "Difference = ";    //Різниця дробів
    diffDrib(one, two);         //викликаємо ф-цію різниці дробів 
    cout << "Product = ";   //множення дробів
    multDrib(one, two);         //викликаємо ф-цію різниці дробів
    cout << "Divisiont = ";         //ділення дробів
    divisionDrib(one, two);         //викликаємо ф-ці ділення дробів
}

