#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>
#include <thread>
#include <mutex>

//Variant 2

using namespace std;

const double g = 9.8;
const double dt = 0.02;
const double beta = 0.991;
const int print_delay = 100;
const int calc_delay = 50;

struct circle
{
	double V;
	double t;
	double h;
	double l;
};

vector<circle> state(0);

mutex vec_locker;

void Model(double VX, double VY)
{
	double v = sqrt(pow(VX, 2) + pow(VY, 2));
	double alpha = atan(VY / VX);
	double t0 = (2 * v * sin(alpha)) / g;
	double t = dt;

	do
	{
		if (t >= t0) t = t0;

		double l = (pow(v, 2) * sin(2 * alpha)) / g;
		double h = (pow(v, 2) * pow(sin(alpha), 2)) / (2 * g);
		v = v * beta;
		t += dt;

		vec_locker.lock();
		state.push_back({ v,t,h,l });
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		this_thread::sleep_for(chrono::milliseconds(calc_delay - 10));
	} while (v > 0);
}

void printer()
{
	circle temp;
	do
	{
		this_thread::sleep_for(chrono::milliseconds(print_delay - 10));

		vec_locker.lock();
		temp = state.back();
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		cout << fixed;
		cout << setprecision(2) << temp.t << '\t' << temp.h << '\t' << temp.V << '\t' << temp.l << endl;
	} while (temp.h > 0);
}

int main(int argc, char* argv[])
{
	double m, vx, vy;

	if (argc != 4)
	{
		cout << "Not enough arguments" << endl;
		exit(-1);
	}
	else
	{
		stringstream convert(argv[1]);
		if (!(convert >> m))
		{
			cout << "Mass convertation error!" << endl;
			exit(-1);
		}

		convert.clear();
		convert.str(argv[2]);
		if (!(convert >> vx))
		{
			cout << "Speed convertation error!" << endl;
			exit(-1);
		}

		convert.clear();
		convert.str(argv[3]);
		if (!(convert >> vy))
		{
			cout << "Speed convertation error!" << endl;
			exit(-1);
		}
	}

	state.push_back({ 0.0, vx, vy });

	cout << endl << endl << "Time\tVx\tVy" << endl;
	cout << fixed;
	cout << setprecision(2) << 0.00 << '\t' << vx << '\t' << vy << endl;

	thread thread_m(Model, vx, vy);
	thread thread_p(printer);

	thread_m.join();
	thread_p.join();

	return 1;
}
