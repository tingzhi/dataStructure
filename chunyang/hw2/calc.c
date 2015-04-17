/* CS261- Assignment 2 - Part1
 * Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/14/2015
 * Development environment: Xcode & MSVC
 * Solution description:
   Application of the Stack ADT - Build an RPN Calculator
   In order to accomplish the goals of needed calculating operators.*/

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
		/* If there's anything in end, it's bad */
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
	c = b - a;
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
	TYPE a, b, c = 0;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	if (a == 0)
	{
		printf("Devide Error: Den is 0. Automatically ignore divide operator. May cause wrong result. Please check your input.\n");
		pushDynArr(stack, b);
		pushDynArr(stack, a);
	}
	else
	{
		c = b / a;
		pushDynArr(stack, c);
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their multiplication is pushed back onto the stack.
*/
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

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	the power of the first element to the second element is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, b, c;
	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);
	c = pow(b,a);
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	squared and pushed back onto the stack.
*/
void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = pow(a, 2);
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	cubed and pushed back onto the stack.
*/
void cube(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = pow(a, 3);
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	its absolute value is pushed back onto the stack.
*/
void absolute(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = fabs(a);
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	its squareroot value is pushed back onto the stack.
*/
void squareroot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c = 0;
	a = topDynArr(stack);
	popDynArr(stack);
	if (a < 0)
	{
		printf("Squareroot Error: negative number. Automatically ignore sqrt operator. May cause wrong result. Please check your input.\n");
		pushDynArr(stack, a);
	}
	else
	{
		c = sqrt(a);
		pushDynArr(stack, c);
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	the power of e to the element is pushed back onto the stack.
*/
void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = pow(2.7182818, a);
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	its natural log value is pushed back onto the stack.
*/
void naturalln(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = log(a);
	pushDynArr(stack, c);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one elements
	post: the top 1 element is popped and
	its base 10 log value is pushed back onto the stack.
*/
void base10log(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	TYPE a, c;
	a = topDynArr(stack);
	popDynArr(stack);
	c = log10(a);
	pushDynArr(stack, c);
}

/*transfer e to real number*/
void etonum(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	pushDynArr(stack, 2.7182818);
}

/*transfer pi to real number*/
void pitonum(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	pushDynArr(stack, 3.14159265);
}

double calculate(int numInputTokens, char **inputString)
{
	int i, count = 0, db = 0; /*count will count the total number of values, db will count if there's + - / x or ^.*/
	double result = 0.0, *num = malloc(sizeof(double));
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
		{
			add(stack);
			db++;                /*db count for operators which need 2 numbers to calculate. Same as - / x and ^.*/
		}
		else if (strcmp(s, "-") == 0)
		{
			subtract(stack);
			db++;
		}
		else if (strcmp(s, "/") == 0)
		{
			divide(stack);
			db++;
		}
		else if (strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
		{
			multiply(stack);
			db++;
		}
		else if (strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
		{
			power(stack);
			db++;
		}
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
		else {
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if (strcmp(s, "e") == 0)			/*transfer e to real value*/
			{
				etonum(stack);
				count++;
			}
			else if (strcmp(s, "pi") == 0)		/*transfer pi to real value*/
			{
				pitonum(stack);
				count++;
			}
			else if (isNumber(s, num) == 1)		/*Check if the input is a number. If so, push it onto the stack*/
			{
				pushDynArr(stack, *num);
				count++;
			}
			else
			{
				/*If the input is nothing above, break this program.*/
				printf("Input error. Please check.\n"); 
				/*Make multiplication clear*/
				printf("For multiplication, please type x insdead of *.\n");
				/*This function cannot check the zero value for 0.0, 0.000, 0e0, etc, so that we have to tell the user to use 0 straightly.*/
				printf("If the input contains value '0', please type 0 straightly instead of 0.0, 0.000, 0e0, etc.\n");
				return 0;
			}
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if (!stack)									/*Same as using assert*/
	{
		printf("Error: The stack is empty.\n");
		return 0;
	}

	/*If there's + - / x or ^ which needs 2 numbers, db will hold 1. Otherwise it's 0.*/
	if (db > 0)
		db = 1;

	/*Check if there are too many numbers compared to operators.*/
	if((i - 1 - count + db) < count)
		printf("Input error: Too few operators.\n");
	else
	{
		result = topDynArr(stack);				/*Store the final result*/
		printf("Final value = %lf\n", result);	/*print the final result out*/
	}

	/*free malloc*/
	free(num);
	free(stack);
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
