#include <iostream>
#include <stdio.h>
using namespace std;
void Line(int lf, int ln, int mij, int rt, int operand = 2) {
    int i;
    printf("\n%c", lf);
    for (int j = 1; j <= operand; j++) {
        for (i = 1; i <= 3; i++) printf("%c", ln); printf("%c", mij);
    }
    for (i = 1; i <= 10; i++) printf("%c", ln); printf("%c", rt);

}

void Complement() {
    Line(201, 205, 209, 187, 1);
    printf("\n%c A %c not A %4c", 186, 179, 186, 1);
    Line(199, 196, 197, 182, 1);
    for (int a = 0; a <= 1; a++) {
        printf("\n%c %d %c %4d %5c", 186, a, 179, !a, 186);
    }
    Line(200, 205, 207, 188, 1);
}

void Conjuctie() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A and B %2c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, a && b, 186);
        }
    }
    Line(200, 205, 207, 188);
}

void Dijunctie() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A or B %3c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, a || b, 186);
        }
    }
    Line(200, 205, 207, 188);
}

void DiferentaSimetrica() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A xor B %2c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, a != b, 186);
        }
    }
    Line(200, 205, 207, 188);
}

void Shifer() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A Nand B %c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, !(a && b), 186);
        }
    }
    Line(200, 205, 207, 188);
}

void Pierce() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A Nor B %2c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, !(a || b), 186);
        }
    }
    Line(200, 205, 207, 188);
}

void Implication() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A -> B %3c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, !a || b, 186);
        }
    }
    Line(200, 205, 207, 188);
}

void Equivalence() {
    Line(201, 205, 209, 187);
    printf("\n%c A %c B %c A <=> B %2c", 186, 179, 179, 186);
    Line(199, 196, 197, 182);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("\n%c %d %c %d %c %4d %5c", 186, a, 179, b, 179, (a && b) || (!a && !b), 186);
        }
    }
    Line(200, 205, 207, 188);
}

void ProblemWith3Variables() {
    Line(201, 205, 209, 187, 3);
    printf("\n%c A %c B %c C %c Result %3c", 186, 179, 179, 179, 186);
    Line(199, 196, 197, 182, 3);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int c = 0; c <= 1; c++) {
                printf("\n%c %d %c %d %c %d %c %4d %5c", 186, a, 179, b, 179, c, 179, (a && b) || (!a && c), 186);
            }
        }
    }
    Line(200, 205, 207, 188, 3);
}

void ParityLogic() {
    Line(201, 205, 209, 187, 3);
printf("\n%c A %c B %c C %c %4c %5c", 186, 179, 179, 179, 'P', 186);
    Line(199, 196, 197, 182, 3);
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int c = 0; c <= 1; c++) {
                printf("\n%c %d %c %d %c %d %c %4d %5c", 186, a, 179, b, 179, c, 179, a ^ b ^ c, 186);
            }
        }
    }
    Line(200, 205, 207, 188, 3);
}

int main()
{
    system("color 1F");
    cout << "Proect nr.1, elaborat de Terentii Iulian IS11Z" << endl;
    cout << "\tTema: Operation of set" << endl;
    cout << "\tl.Dopolnenie" << endl;
    Complement();
    cout << "\t2.Conjunctie" << endl;
    Conjuctie();
    cout << "\t3.Dijunctie" << endl;
    Dijunctie();
    cout << "\t4.DiferentaSimetrica" << endl;
    DiferentaSimetrica();
    cout << "\t5.Shifer" << endl;
    Shifer();
    cout << "\t6.Pierce" << endl;
    Pierce();
    cout << "\t7.Implication" << endl;
    Implication();
    cout << "\t8.Equivalence" << endl;
    Equivalence();
    cout << "\t9.Problem with 3 variables: (A && B) || (!A && C)" << endl;
    ProblemWith3Variables();
    cout << "\t10.Logic: Parity (A XOR B XOR C)" << endl;
    ParityLogic();
    
    cout << "\n\nНажмите любую клавишу для выхода..." << endl;
    system("pause");
    return 0;
}