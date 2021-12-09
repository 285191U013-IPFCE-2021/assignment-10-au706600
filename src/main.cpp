extern "C"{
    // Add the header files required to run your main 
    #include "linked_list.h"
}
#include <stdio.h>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    //exercise 2
    	int sum;
      node *ns = NULL;
    	ns = make_node (1,
			make_node (2,
				   make_node (3,
					      make_node (4,
							  make_node (5,
								    NULL)))));

	sum = sum_squares (ns);	/* sum should equal 55 */
  	if(sum!=55)
      printf("False");
  	free_list(&ns);
	// sum=sum_squares(ns);
	// REQUIRE(sum==0);

	ns = make_node (1,NULL);
	sum=sum_squares(ns);
	if(sum!=1)
        printf("False");
	
	//exercise 3
	//ns contains one node with the value 1
	node *mns = map (ns, square);
	sum=sum_squares(ns);
	if(sum!=1)
    printf("False");
	free_list(&ns);
  	ns = make_node (1,
			make_node (2,
				   make_node (3,
					      NULL)));
	//ns is 1->2->3
  	mns = map (ns, square);
	//ns is 1->4->9
	sum=sum_squares(mns);
	//1+16+81 = 98
	if(sum!=98)
        printf("Fail");
	free_list(&mns);
    printf("Success");
    return 0;

}