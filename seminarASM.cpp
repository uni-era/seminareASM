// pspspsps

#include <iostream>
using namespace std;

int sum(int t[], int n) {
	//for (int i = 0; i < n; i++)
	//	s += t[i];
	//return s;
    _asm {
        mov eax, 0 // or 0 since int says 0 it dont rly matter
        mov ebx, 0
        mov ecx, n
    myloop :
        cmp ebx, ecx
            jge outside // jump WHEN i IS >= TO 5 GIRL NOT BEFORE
            add eax, t[ebx * 4] // se misca din 4 in 4, cand i e 1 avem un prim set de 4 biti etc
            inc ebx
            jmp myloop
    outside :

    }
        
}

int main() {
    int t[] = { 2, -1, 8, 4, 7 };
	//int x = sum(t, 5);
    cout << sum(t, 5); // BIG UGLY VALUE // automatically reads the last value in the eax register
    return 0;
}

// SEMINAR 5

/*    int t[] = { 2, -1, 8, 4, 7 };
	int i, s = 0;
	//for (i = 0; i < 5; i++)
		//s += t[i];

    _asm {
        mov eax, s // or 0 since int says 0 it dont rly matter
        mov ebx, 0
    myloop:
        cmp ebx, 5
		jge outside // jump WHEN i IS >= TO 5 GIRL NOT BEFORE
        add eax, t[ebx * 4] // se misca din 4 in 4, cand i e 1 avem un prim set de 4 biti etc
        inc ebx
        jmp myloop
    outside:
        mov s, eax // keep this outside, you dont need to do this every time tf
    }

    cout << s;
    // t[ebx*4]
    return 0;*/

// SEMINAR 4

// ESP
// a        push 9      (a and be are in reverse order if we use C for some reason)
// b        push 5
// adr      call dif    <- ESP (moves here)
// EBP old <- EBP
//
// push ebp     |
// mov ebp, esp | always use these two before calling
// ------   |
// ------   | this is placeholder for the funciton immplementation
// pop ebp
// ret
// 
// ZONT CHANGE EBP INSIDE FUNCTISHUN

/*
void dif(int a, int b) {
    int c;
    c = a - b;
    cout << c << endl;
}

void difASM(int a, int b) {
    const char* s = "%d";
    _asm {
        mov eax, a
        sub eax, b
        push eax
        push s
        call printf
        add esp, 8
    }
}

int main() {
    _asm {
        push dword ptr 5
        push dword ptr 9
        call dif
        add esp, 8
    }
    // difASM(9, 5);
    return 0;
}

*/

/*
int sum(unsigned n, ...) {
    //for (int i = 0; i < n; i++) { }
    _asm { // eax and edx are for returning values, no need for push and pop like we did with ebx
        push ebx
        mov eax, 0
        mov ebx, 1
    forloop:
        cmp ebx, n
            ja theend
        add eax, [ebp + ebx * 4 + 8]
        inc ebx
        jmp forloop
    theend :
        pop ebx
    }
}

int main() {
    cout << sum(5, 1, 2, 3, 4, 5);
    return 0;
}
*/

/*
unsigned fact(unsigned n) {
    if (n = 0) return 1;
    return n * fact(n-1);
}

*/

/*
#include <cstdarg>

unsigned fact(unsigned n) {

    _asm {
        // push n-1 --> NO GOOD
        mov ebx, n
        cmp ebx, 0
            je iszero
        dec ebx
        push ebx
        call fact
        add esp, 4
        mul n
        jmp end1
    iszero:
        mov eax, 1
    end1:
    }
}

int main() {
    unsigned f;
    cin >> f;
    cout << fact(f);
    return 0;
}
*/

// SEMINAR 3

/*
    int t[] = { 4, 1, -2, 7, 9 };
    int i, s = 0;
    // for (i = 0; i < 5; i++)
    // 	    s += t[i];
    _asm {
        mov ebx, 0
        mov eax, 0
    myloop:
        cmp eax, 5
        jge outside
        add ebx, t[eax * 4]
        inc eax
        jmp myloop

    outside:
        mov s, ebx
    }

    cout << s;
*/

/*

    char s[] = "7293";
    unsigned a = 0;
    unsigned i;
    // for(i = 0; s[i] != '\0'; i++)
    //     a = a * 10 + (s[i] - '0');
    _asm {
        mov eax, 0
        mov ebx, 0
        myloop:
            cmp s[ebx], 0
            je outside
            mov edx, a
            mov ecx, 10
            mul ecx
            mov dl, s[ebx]
            sub dl, '0'
            add eax, edx
            inc ebx
            jmp myloop
        outside :
        mov a, eax
    }
    cout << a;
    return 0;
*/

/*
    unsigned a, b, c;
    a = 28;
    b = 98;
    // let's calc greatest  common divisor
    //while (b != 0) {
    //    c = a % b;
    //    a = b;
    //    b = c;
    //}
_asm {
    mov eax, a
    mov ebx, b

    myloop :
    cmp ebx, 0
        je outside
        mov edx, 0
        div ebx
        mov eax, ebx
        mov ebx, edx
        jmp myloop
        outside :
    mov a, eax
}
cout << a;
*/

/*

    unsigned a, b, x;
    if ((a > 5) && (b < 2))
        x = 10;
    _asm {
        cmp a, 5
        jle is_false
        cmp b, 2
        jge is_false
        mov x, 10
    is_false:
    }
*/

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

/*    char s[100];
        unsigned a = 9157;
        unsigned i = 0;
        do {
            // s[i] = (a % 10) + '0';
            // a = a / 10;
            // i++;
            _asm {
                mov ecx, 10
                mov edx, 0
                mov eax, a
                div ecx
                add edx, '0'
                mov ebx, i
                mov s[ebx], dl
                mov a, eax
                inc i // increments i by 1
            }

        } while (a);
        s[i] = '\0';
        printf("%s", s); // couts<< s;*/

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