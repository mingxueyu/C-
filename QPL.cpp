#include <iostream>
#include <cstring>
#define N 100
using namespace std;
void permutation(char* a, int k, int m)
{	
int i, j;
	if (k == m)	
	{		
	for (i = 0; i <= m; i++)
				cout << a[i];
						cout << endl;
							}	else
								{	
									for (j = k; j <= m; j++)	
										{			swap(a[j], a[k]);	
												permutation(a, k + 1, m);		
													swap(a[j], a[k]);	
														}
															}
															} 
															int main()
															{	
															char a[N];
																int n;
																	cin >> a;
																		n = strlen(a) - 1;
																			permutation(a, 0, n);
																				return 0;
																				}


