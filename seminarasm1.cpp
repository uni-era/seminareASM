// seminarasm1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{

        _asm {

        }

    return 0;
}

// SEMINAR 2

// div  ||  div bh -> ax / bh = al
//      ||            ac % bh = ah
// idiv

/*
int t[] = {2, 7, -1, 5};
int i, prod = 1;
for (i=0; i<4; i++) {
    // prod *= t[i];
    _asm {
        mov eax, prod
        mov ebx, i
        imul t[ebx * 4]
        mov prod, eax
    }
}
cout << prod;
*/

/*    char s[] = "4718";
    unsigned a = 0;
    unsigned i;
    for (i = 0; s[i] != '\0'; i++)
		// a = a * 10 + (s[i] - '0');
        _asm {
            mov eax, a
            mov ebx, 10
            mov ecx, i
            mul ebx
            mov dl, s[ecx] // dl because edx - dumb bitch
            sub dl, '0'
		    add eax, edx
		    mov a, eax
        }

    cout << a;
    return 0;*/


// SEMINAR 1

// EAX
// EBX
// ECX
// EDX
// ESI
// EDI
// EBP
// ESP

/*
    int a = 15;
    int b = 27;
    //a = b;
    cout << a << " " << b << endl;
    _asm { ... }
    cout << a << " " << b << " ";
*/

/*_asm {
        mov a, 15;
        mov b, 27;
        mov edi, b;
        mov a, edi;
    }*/

/*    
_asm {
    mov eax, a;
    xchg eax, b;
    mov a, eax;
}
*/

/*

    int t[] = { 1, 7, -9, 12, 4 };
    int i; int s = 0;
    for (i = 0; i < 5; i++)
        _asm {
            mov eax, s;
            mov ebx, i;
            add eax, t[ebx*4]; // se misca din 4 in 4, cand i e 1 avem un prim set de 4 biti etc
            mov s, eax;
        }

    printf("%d", s);
*/

/*
int i = 73;
char c = -8;
/*
_asm {
    movzx eax, c;
    mov i, eax;
}
*/ /*
_asm {
    mov eax, i;
    mov c, al;
}
printf("%d", c);
*/