#include <stdio.h>
#include<math.h>

# define EQ(A, B) (fabs(A - B) < 10e-7)

int isEmpty(int val)
{
	/* FIXME: You will write this function */
    //assert(v != 0);
	/* FIXME:  You will change this return value*/
    return (!val);
}


int main() {
	double value1 = 99.2;
    double value2 = 99.3;
	//int tmp;
	//tmp = isEmpty(value);
	//printf("When value is %d, return %d.\n", value1, tmp);
    int ret;
    /*if (EQ(value1, value2)) {
        printf("eq\n");
    }
    else {
        printf("Neq\n");
    }*/
    ret = EQ(value1, value2);
    printf("The output is %d\n", ret);
	
}