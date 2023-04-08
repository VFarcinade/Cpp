#pragma once
#include <vector>
#include <math.h>
#include <iostream>
#include <tuple>

//Fonctions Vecteur.s
std::vector<double> diff(const std::vector<double>& v,const  std::vector<double>& w);
std::vector<double> sum(const std::vector<double>& v,const  std::vector<double>& w);
std::vector<double> prod(const std::vector<double> &v, const double& a);
std::vector<double> div(const std::vector<double> &v, const double& a);
double norm2(const std::vector<double>& v);
double scal(const std::vector<double>& v, const std::vector<double>& w);
void print(const std::vector<double>& v);
std::pair<double,double> MeanVar_res(const std::vector<double>& vres);
