/*----------------------------------------------------------------------------
LAB EXERCISE:SQUARE ROOT APPROXIMATION
--------------------------------------
Write an assembly code subroutine to approximate the square root of an argument 
using the bisection method. All math is done with integers, so the resulting 
square root will also be an integer
 *----------------------------------------------------------------------------*/

__asm int my_sqrt(int x)
{
	MOV r1,#0 ; r1 = a = 0
	MOV r2,#65535 ; r2 = b = 1<<17 (approx)
	MOV r3,#0  ; r3 = c
	MOV r4,r3 ; r4 = c_old = c

	loop:
		MOV r4,r3 ; c_old = c
		ADD r3,r2,r1  ; c = a + b
		ASR r3,r3,#1  ; c = c >> 1
		MUL r5,r3,r3  ; d = c*c
		CMP r0,r5     ; r0 is the argument x that was passed into the function
		BLT lt  
		BGT gt 
		BEQ exit

	lt:
		MOV r1,r3  ; a  = c
		CMP r3,r4  ; if c = c_old
		BEQ exit   
		B loop
	
	gt:
		MOV r2,r3  ; b = c
		CMP r3,r4  ; if c == c_old
		BEQ exit
		B loop

	exit:
		BX lr

}

int main(void)
{
		volatile int r, j=0;
		int i;
		r = my_sqrt(0); 	// should be 0
		r = my_sqrt(25); 	// should be 5
		r = my_sqrt(133); // should be 11
	
		for (i=0; i<10000; i++) {
			r = my_sqrt(i);
			j+=r;
		}
		

		while (1)
			;
}
// *******************************ARM University Program Copyright © ARM Ltd 2013*************************************   
