#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

const size_t N = 12;//10 
const double dt = 0.05;//0.1 
const int latency_ind = 2; //latency  in units of dt (100ms)

struct State {

	vector<double> X;
	vector<double> Y;
	vector<double> Psi;
	vector<double> V;
	vector<double> Cte;
	vector<double> EPsi;
	vector<double> Delta;
	vector<double> A;
};

class MPC {
public:
	MPC();

	virtual ~MPC();

	State Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);

	double delta_previous{ 0 };
	double a_previous{ 0.1 };

};


#endif /* MPC_H */
