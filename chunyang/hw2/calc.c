/* CS261- Assignment 2 - Part1*/
/* Name: Li, Tingzhi & Zhang, Chunyang
/* Date: 4/14/2015
/* Development: Xcode & MSVC
/* Solution description:
   Application of the Stack ADT - Build an RPN Calculator */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <math.h>


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, b, c;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	c = a + b;
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, b, c;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	c = a - b;
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, b, c;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	if (b == 0)
	{
		printf("Devide Error: Den is 0. Automatically ignore this operator. May cause wrong result. Please check your input.\n");
		pushDynArr(stack, b);
		pushDynArr(stack, a);
	}
	else
		c = a / b;
	pushDynArr(stack, c);
}

void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, b, c;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	c = a * b;
	pushDynArr(stack, c);
}

void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, b, c;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	c = pow(a,b);
	pushDynArr(stack, c);
}

void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = pow(a, 2);
	pushDynArr(stack, c);
}

void cube(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = pow(a, 3);
	pushDynArr(stack, c);
}

void absolute(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = fabs(a);
	pushDynArr(stack, c);
}

void squareroot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	if (a < 0)
	{
		printf("Squareroot Error: negative number. Automatically ignore sqrt operator. May cause wrong result. Please check your input.\n");
		pushDynArr(stack, a);
	}
	else
		c = sqrt(a);
	pushDynArr(stack, c);
}

void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = pow(2.7182818, a);
	pushDynArr(stack, c);
}

void naturalln(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = log(a);
	pushDynArr(stack, c);
}

void base10log(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = log10(a);
	pushDynArr(stack, c);
}

void etonum(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	popDynArr(stack);
	pushDynArr(stack, 2.7182818);
}

void pitonum(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	popDynArr(stack);
	pushDynArr(stack, 3.14159265);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0, *num = 0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if (strcmp(s, "+") == 0)
			add(stack);
		else if (strcmp(s, "-") == 0)
			subtract(stack);
		else if (strcmp(s, "/") == 0)
			divide(stack);
		else if (strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiply(stack);
		else if (strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			power(stack);
		else if (strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
			square(stack);
		else if (strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			cube(stack);
		else if (strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absolute(stack);
		else if (strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			squareroot(stack);
		else if (strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			exponential(stack);
		else if (strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			naturalln(stack);
		else if (strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			base10log(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if (strcmp(s, "e") == 0)
				etonum(stack);
			else if (strcmp(s, "pi") == 0)
				pitonum(stack);
			else if (isNumber(s, num) == 1)
				pushDynArr(stack, *num);
			else
				printf("Input error. Please check.\n");			
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	result = topDynArr(stack);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
