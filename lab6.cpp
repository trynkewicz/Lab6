#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	const int n = 2;           
	double x[n];               
	const int ntrial = 65;        
	const double eps = 1.e-6;    
	int iter;                    
	int i, j, k;                
	double tmp;                   
	double fvec[n];                
	double p[n];               
	double fjac[n][n];            
	x[0] = 0.;
	x[1] = -3.;
	
	ofstream out;
	out.open("graph.txt");
	for (iter = 1; iter <= ntrial; iter++) {
		
		for (i = 0; i < n; i++) {
			out << x[i] << " ";
		}
		out << endl;

		fvec[0] = 4 * x[0]  + 4 ;    //df/dx1 
		fvec[1] = 6 * x[1]  - 39 ;    //df/dx2 

		tmp = 0.;
		for (i = 0; i < n; i++) {
			tmp +=  fabs(fvec[i]);
		}
		if (tmp <= eps)
			break;

		
		fjac[0][0] = 4. ;           
		fjac[0][1] = 0.;    
		fjac[1][0] = 0.;        
		fjac[1][1] = 6.;    
		
		for (i = 0; i < n; i++)
			p[i] = -fvec[i];
		for (i = 0; i < n - 1; i++) {
			tmp = fjac[i][i];

			if (tmp == 0.) {
				cout << "Error: Zero element at main diagonal in Jacobean matrix\n";
				system("pause");
				return 0;
			}

			for (j = i + 1; j < n; j++) {
				p[j] -= p[i] / tmp;
				for (k = n - 1; k >= i; k--) {
					fjac[j][k] -= fjac[i][k] * fjac[j][i] / tmp;
				}
			}
		}
		for (i = n - 1; i >= 0; i--) {
			tmp = 0;
			for (j = i + 1; j < n; j++) {
				tmp += fjac[i][j] * p[j];
			}
			p[i] = (p[i] - tmp) / fjac[i][i];
		}

		for (i = 0; i < n; i++) {
			x[i] += p[i];
		}

	}
	out.close();
	if (iter < ntrial+2) {
		cout << "\n\n The minimum location\n";
		cout << "(" << x[0] << ", " << x[1] << ")\n";
		cout << "The number of itterations is " << iter << endl;
		system("pause");
		return 0;
	}
	
	system("pause");
	return 0;

}
